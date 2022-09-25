#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t printing;

typedef struct t_t
{
	pthread_t	thread;
	int id;
}	p_t;

void	*function(void *arg)
{
	p_t	*pt;
	long n;

	pt = (p_t *)arg;
	printf("test\n");
	pthread_mutex_lock(&printing);
	printf("%i started\n", pt->id);
	pthread_mutex_unlock(&printing);
	n = 100000;
	while (n > 0)
		n--;
	pthread_mutex_lock(&printing);
	printf("%i finished\n", pt->id);
	pthread_mutex_unlock(&printing);
	return (NULL);
}

int	main(void)
{
	p_t bunch[5];

	pthread_mutex_init(&printing, NULL);
	int index = 0;
	while (index < 5)
	{
		printf("hh\n");
		bunch[index].id = index + 1;
		pthread_create(&bunch[index].thread, NULL, function, &bunch[index]);
		pthread_detach(bunch[index].thread);
		index++;
	}
	printf("reached end\n");
	return (0);
}
