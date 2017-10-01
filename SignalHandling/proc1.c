#include "header.h"

int main(int argc, char *argv[]){

	int status1,stats2;
	pid_t pid;

	
	printf("Parent process starts\n");

	if((pid = fork())==0){
		//child
		execl("./proc2","NULL",NULL);
	}
	else{

		sleep(2);

		//sending signal SIGHUP to child
		printf("Sending signal SIGHUP to child\n");	
		kill(pid,SIGINT);
		sleep(5);
		kill(pid,SIGKILL);
	}

	printf("Parent process ends\n");
	
	return 0;
}