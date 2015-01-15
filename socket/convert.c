#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
	    char str[10];

    int x = 65536;

    sprintf(str,"%d",x);

    printf("%s \n",str);

    return 0;
}