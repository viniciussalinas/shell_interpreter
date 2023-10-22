#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX 256

void printa(int i);

int main() {
  	
	FILE *oldfd;
	int newfd;

  	char comando[MAX];
  	int pid;
	
	int i = 0;
	char *arg;
	char *args[MAX];

    while (1) {

		printf("> ");
		gets(comando);

		arg = strtok(comando, " \n ");
		args[0] = arg;
	
		if (!strcmp(comando, "exit")) {
		  exit(EXIT_SUCCESS);
		}

		//separa os argumentos
		for (i = 1; (arg = strtok(NULL, " \n")) != NULL; i++){

			args[i] = arg;
				
		}

		args[i] = NULL;		

		if (pid) {  //processo pai

			if (strcmp(args[i - 1], "&"))

		    	waitpid(pid, NULL, 0); 

		} else {

			if (!strcmp(args[i - 2], ">")){

 				freopen (args[i - 1], "w" , stdout);
				args[i - 2] = NULL;	

			}	

			else if (!strcmp(args[i - 2], "<")){

 				freopen (args[i - 1], "r" , stdin);
				args[i - 2] = NULL;	

			}

			if (!strcmp(args[i - 1], "&"))
		
				args[i - 1] = NULL;

			execvp(args[0], args);
			printf("Erro ao executar comando!\n");
			exit(EXIT_FAILURE);
	   		
		}
	
    }

}

//open: abre o arquivo
//dup2 pega os dados de open
/*
void printa(int i){
	
	int j;

	for (j = 0; j < i; j++)

		printf("%s\n", args[j]);


}
*/

/*
		for (j = 0; j < i; j++){

			printf("j = %d, '%s'\n", j, args[j]);

		}
*/
