#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void sig_handler(int signum)
{
	int i = 5;
	int j = 0;
	int k;
	switch (signum)
	{

	case SIGCHLD:
		printf("I am in SIGCHLD \n");
		fflush(stdout);
		k = i / j;
	case SIGFPE:
		printf("I am in SIGFPE \n");
        int arr[2];
		arr[10] = 10;
		//flush(stdout);
		
	case SIGILL:
		printf("I am in SIGILL\n");
		
		raise(SIGTERM);
        
		
		// printf("I am in SIGILL\n");
		// fflush(stdout);

	case SIGSEGV:
		printf("I am in SIGSEGV ");
		asm("ud2");
		//fflush(stdout);
	}
}
void sig_handler2(int signum)
{
	printf("I am in sighandler2222\n");
	fflush(stdout);
	exit(1);
}

int main()
{
	int status;
	signal(SIGCHLD, sig_handler);
	signal(SIGSEGV, sig_handler);
	signal(SIGFPE, sig_handler);
	signal(SIGILL, sig_handler);
	
	

	if (!(fork()))
	{
		exit(1);
	}
	wait(&status);
}