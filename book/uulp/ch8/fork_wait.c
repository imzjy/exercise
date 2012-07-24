#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char *arglist[3];
	arglist[0] = "ls";
	arglist[1] = "-la";
	arglist[2] = NULL;
	pid_t ret_pid;
	int status;
	
	printf("do listing\n");

	if(fork() == 0)
	{
		//child
		//execvp("ls",arglist);
		printf("child %d do something, and sleep for 2 seconds\n", getpid());
		sleep(2);
		exit(17);
	}
	else
	{
		//parent
		printf("parent %d do sth\n", getpid());
		ret_pid = wait(&status);  //wait for child process exit;
		printf("after wait\n");

		//int exit_value = status >> 8;
		int exit_value = WEXITSTATUS(status);   //marco define in sys/wait to extract some bit of status
		int coredump = status & 0x80;
		int sig = status & 0x7F;
		printf("return child pid:%d, status:0x%x\n", ret_pid, status);
		printf("%d,%d,%d\n",exit_value,coredump,sig);
	}

	printf("end listing\n");


}
