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
	//child dead immediately
	exit(0);
}

void do_parent()
{
	printf("parent pid is:%d\n", getpid());
	//parent hold 30 seconds and call wait to revoke the child
	sleep(30);
	printf("call wait to revoke the child exit status\n");
	wait(NULL);

	sleep(30 * 60);
	exit(0);
}
