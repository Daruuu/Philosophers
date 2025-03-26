#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

# define NC "\e[0m"
# define YELLOW "\e[1;33m"

void	*thread_routine(void *data)
{
	pthread_t	tid;
	// The pthread_self() function provides
	// this thread's own ID.
	tid = pthread_self();
	printf("%sThread [%ld]: The heaviest burden is to exist without living.%s\n", YELLOW, tid, NC);
	return (NULL); // The thread ends here.
}

int main(void)
{
	pthread_t tid1; // First thread's ID
	pthread_t tid2; // Second thread's ID

	// Creating the first thread that will go
	// execute its thread_routine function.
  	pthread_create(&tid1, NULL, thread_routine, NULL);
  	printf("Main: Created first thread [%ld]\n", tid1);
//  	Creating the second thread that will also execute thread_routine.
  	pthread_create(&tid2, NULL, thread_routine, NULL);
  	printf("Main: Created second thread [%ld]\n", tid2);
//  	The main thread waits for the new threads to end
//  	with pthread_join.
  	pthread_join(tid1, NULL);
  	printf("Main: Joining first thread [%ld]\n", tid1);
  	pthread_join(tid2, NULL);
  	printf("Main: Joining second thread [%ld]\n", tid2);
  	return (0);
}
















 










/*
pthread_t ntid;
void
printids(const char *s)
{
pid_t
pid;
pthread_t
tid;
pid = getpid();
tid = pthread_self();
printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long)pid,
(unsigned long)tid, (unsigned long)tid);
}
void *
thr_fn(void *arg)
{
printids("new thread: ");
return((void *)0);
}
int
main(void)
{
int
err;
err = pthread_create(&ntid, NULL, thr_fn, NULL);
if (err != 0)
	printf("can’t create thread\n");
printids("main thread:");
sleep(1);
exit(0);
}
*/
