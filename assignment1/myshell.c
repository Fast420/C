#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int parse(char *line,char *args[])
{
     while(*line != '\0')
     {
          while(*line == ' ' || *line == '\t')
               *line++ = '\0';
          *args++ = line;

          while ((*line != '\0') && (*line != ' ') && (*line != '\t'))
            line++;
     }
     *args = '\0';
     return 0;
}

int execute(char *args[])
{
	pid_t pid;
	int status;

	pid = fork();

    if (pid < 0)
    {
        perror("error ocurred");
        exit(1);
    }

    if (pid == 0) {
        execvp(*args, args);
        execve(*args,NULL,NULL);
        perror(*args);
        exit(1);
    }
    else
    {
    	while(wait(&status) != pid)
    		;
    }
    return 0;
}

// chop the newline off
char *remove_newline(char *s)
{
    int len = strlen(s);

    if (len > 0 && s[len-1] == '\n')
        s[len-1] = '\0';

    return s;
}

int main()
{
     char line[1024];
     char *args[32];

     while(1)
     {
     	fgets (line,1024,stdin);
     	remove_newline(line);

     	parse(line,args);

     	if (strcmp(*args, "exit") == 0)
     		exit(0);

     	execute(args);
     }
     return 0;
}