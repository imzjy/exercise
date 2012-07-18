#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void wakeup(int signum);

int main()
{
	printf("begin....\n");
	fflush(stdout);  //force flush the output buffer

	signal(SIGALRM, wakeup);
	alarm(4); //signal a alarm in 4 seconds
	pause();

	printf("continue....\n");
}

void wakeup(int signum)
{
	printf("in wake up\n");
}
