#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

char** parse_cmdline(const char* cmdline);

void free_all(char**);

int count_rows(char*);

int main()
{
	char input[1024];
	while(1)
	{
		printf("$ ");
		if(fgets(input,1024,stdin) == NULL) 
		{
			//printf("\n");
			break;
		}
		char** s = parse_cmdline(input);
		if(s == 0) continue;
		pid_t pid = fork();
		if(pid == 0)
		{
			if(execv(s[0],s))
			{
				perror(s[0]);
				exit(1);
			}
		}
		else if(pid > 0)
		{
			wait(NULL);
			free_all(s);
		}
		else
		{
			perror("fork");
			exit(1);
		}
	}
	return 0;
}

char** parse_cmdline(const char* cmdline)
{
	int rows = 0;
	int columns = 0;
	if(strcmp(cmdline,"\n") == 0)
	{
		return 0; 
	}
	int size1 = 1;
	int size2 = 1;
	char** parsed = malloc(size1*sizeof(char*));
	*parsed = malloc(size2*sizeof(char));
	for(int i=0; i<strlen(cmdline); i++)
	{	
		if(cmdline[i] == ' ')
		{
			rows++;
			size2 = 1;
			if(rows == size1)
			{
				size1*=2;
				parsed = realloc(parsed,size1*sizeof(char*));
			}
			*(parsed + rows) = malloc(size2*sizeof(char));
			columns = 0;
		}
		else
		{
			if(cmdline[i] == '\n')
			{
				i++;
			}
			if(i == size2) 
			{
				size2*=2;
				*(parsed+rows) = realloc(*(parsed+rows),size2*sizeof(char));
			}
			parsed[rows][columns] = cmdline[i];
			columns++;
		}
	}
	int fd;
	//printf("%s\n",parsed[0]);
	if((fd = open(parsed[0], O_CLOEXEC)) == -1) 
	{
		perror(parsed[0]);
		return 0;
	}
	close(fd);
	parsed[++rows] = NULL;		
	return parsed;
}

void free_all(char** s)
{
	int i;
	int size = 0;
	for(i=0; *(s+i)!=NULL; i++)
	{
		free(*(s+i));
	}
	free(s);
	s = NULL;
}
