#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void do_child();
void do_parent();

int main()
{
	printf("begin fork\n");


	pid_t child_pid = fork();
	if(child_pid < 0)
		perror("fork failed!\n");
	else if(child_pid == 0)
		do_child();
	else
		do_parent();

}

void do_child()
{
	printf("child pid is:%d\n", getpid());
	while(1){
		printf(".");
		fflush(stdout);
		sleep(2);
	}

	exit(0);
}

void do_parent()
{
	printf("parent pid is:%d\n", getpid());
	sleep(30);
	//parent  exit
	printf("parent exit, and child PPID change to 1(init);\n");
	exit(0);
}
