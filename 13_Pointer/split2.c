// Yunen He 2014

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *get_str2(char *line)
{
	while(*line != ' ')
	{
		line++;
	}
	return(line);
}

int main()
{
    char line[80];
    char *str1_ptr;
    char *str2_ptr;

	// Hello World!
    fgets(line, sizeof(line), stdin);

    /* Get rid of trailing newline */
    line[strlen(line)-1] = '\0';

    printf("line: %s\n",line);

    str1_ptr = line;
    printf("Before str1_ptr: %s\n",str1_ptr);

    str2_ptr = get_str2(line);

    printf("str2_ptr: %s\n",str2_ptr);

    *str2_ptr = '\0';
    str2_ptr++;
    printf("After str1_ptr: %s\n",str1_ptr);
    return (0);
}
