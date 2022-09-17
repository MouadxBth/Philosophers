# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Bonus.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 15:36:27 by mbouthai          #+#    #+#              #
#    Updated: 2022/09/17 01:07:46 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR	:= philo_bonus

NAME	:= $(DIR)/philo_bonus

BOLD	:=\033[1m

RESET	:=\033[0m

RED	:=\033[91m

GREEN	:=\033[92m

CYAN	:=\033[96m

INC_DIR	:= $(DIR)/inc/ 

EXTERN	:=

SRC_DIR	:= $(DIR)/src/

OBJ_DIR	:= $(DIR)/obj/

DEP_DIR	:= $(DIR)/dep/

RM	:= rm -f

RMDIR	:= rmdir

CC	:= gcc

CFLAGS	:= -Wall -Werror -Wextra -pthread -I$(INC_DIR) $(EXTERN)

LFLAGS	:=

INC_FS	:= philosophers_bonus.h

SRC_FS	:= philosophers_bonus.c philosopher_bonus.c \
	philosophers_create_bonus.c philosophers_start_bonus.c \
	philosopher_utils_bonus.c philosophers_arguments_bonus.c \
	philosophers_cleanup_bonus.c philosophers_death_bonus.c \
	ft_atoi_bonus.c

INCS	= $(addprefix $(INC_DIR), $(INC_FS))

SRCS	= $(addprefix $(SRC_DIR), $(SRC_FS))

OBJS	= $(addprefix $(OBJ_DIR), $(notdir $(SRCS:%=%.o)))

DEPS	= $(addprefix $(DEP_DIR), $(notdir $(SRCS:%=%.d)))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(GREEN)BUILDING BONUS$(RESET)\n"
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(OBJ_DIR):
	@echo "\n$(BOLD)CREATING BONUS OBJ DIRECTORY$(RESET)\n"
	mkdir -p $@

$(DEP_DIR):
	@echo "\n$(BOLD)CREATING BONUS DEP DIRECTORY$(RESET)\n"
	mkdir -p $@

$(OBJS): | $(OBJ_DIR)

$(OBJS): | $(DEP_DIR)

$(OBJS): $(OBJ_DIR)%.o: $(SRC_DIR)%
	$(CC) $(CFLAGS) -MMD -MF $(addprefix $(DEP_DIR), $(notdir $(<:%=%.d))) -c $< -o $@

cleanobj:
	@echo "\n$(RED)CLEANING BONUS OBJECT FILES$(RESET)\n"
	-$(RM) $(wildcard $(OBJS))

cleanobjdir: cleanobj
	-$(RMDIR) $(OBJ_DIR)

cleandep:
	@echo "\n$(RED)CLEANING BONUS DEPENDENCIES$(RESET)\n"
	-$(RM) $(wildcard $(DEPS))

cleandepdir: cleandep
	-$(RMDIR) $(DEP_DIR)

clean: cleanobjdir cleandepdir

fclean: clean
	@echo "\n$(RED)CLEANING BONUS BINARY$(RESET)\n"
	-$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all bonus cleanobj cleanobjdir cleandep cleandepdir clean fclean
