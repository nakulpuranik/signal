#include "header.h"

static void sig_handler(int signo)
{
  printf("Ignoring the Signal!\n");
}

// this process will not end untill parent process kills it
int main(int argc, char *argv[]){
	int j;
	printf("\nInside child thread\n");
	//handle signal SIGHUP to ignore
	if (signal(SIGINT, sig_handler) == SIG_ERR){
  		printf("\ncan't catch SIGINT\n");
  	}
	for (j = 0; ; j++) {
		//printf("%d\n", j);
		sleep(3);
	}
	return 0;
}