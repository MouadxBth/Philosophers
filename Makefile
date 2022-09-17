# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 15:36:27 by mbouthai          #+#    #+#              #
#    Updated: 2022/09/14 20:17:55 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR	:= philo

NAME	:= $(DIR)/philo

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

CFLAGS	:= -Wall -Werror -Wextra -pthread -g -I$(INC_DIR) $(EXTERN)

LFLAGS	:=

INC_FS	:= philosophers_bonus.h

SRC_FS	:= philosophers.c philosopher.c \
	philosophers_create.c philosopher_utils.c \
	philosophers_arguments.c philosophers_cleanup.c \
	philosophers_start.c philosophers_death.c ft_atoi.c

INCS	= $(addprefix $(INC_DIR), $(INC_FS))

SRCS	= $(addprefix $(SRC_DIR), $(SRC_FS))

OBJS	= $(addprefix $(OBJ_DIR), $(notdir $(SRCS:%=%.o)))

DEPS	= $(addprefix $(DEP_DIR), $(notdir $(SRCS:%=%.d)))

all: $(NAME)

bonus:
	@make -f Bonus.mk

$(NAME): $(OBJS)
	@echo "\n$(GREEN)BUILDING PROJECT$(RESET)\n"
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(OBJ_DIR):
	@echo "\n$(BOLD)CREATING OBJ DIRECTORY$(RESET)\n"
	mkdir -p $@

$(DEP_DIR):
	@echo "\n$(BOLD)CREATING DEP DIRECTORY$(RESET)\n"
	mkdir -p $@

$(OBJS): | $(OBJ_DIR)

$(OBJS): | $(DEP_DIR)

$(OBJS): $(OBJ_DIR)%.o: $(SRC_DIR)%
	$(CC) $(CFLAGS) -MMD -MF $(addprefix $(DEP_DIR), $(notdir $(<:%=%.d))) -c $< -o $@

cleanobj:
	@echo "\n$(RED)CLEANING OBJECT FILES$(RESET)\n"
	-$(RM) $(wildcard $(OBJS))

cleanobjdir: cleanobj
	-$(RMDIR) $(OBJ_DIR)

cleandep:
	@echo "\n$(RED)CLEANING DEPENDENCIES$(RESET)\n"
	-$(RM) $(wildcard $(DEPS))

cleandepdir: cleandep
	-$(RMDIR) $(DEP_DIR)

clean: cleanobjdir cleandepdir

fclean: clean
	@make fclean -f Bonus.mk
	@echo "\n$(RED)CLEANING BINARY$(RESET)\n"
	-$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all bonus cleanobj cleanobjdir cleandep cleandepdir clean fclean
