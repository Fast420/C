// Yunen He 2014
// Write a function that counts the number of words in a string
#include<stdio.h>
#include<string.h>

char s[] = "";
int size = 0;
int count = 0;

int count_word(char s[])
{
	size = strlen(s);
	for (int i = 0; i < size; ++i)
	{
		if (s[i] == ' ')
		{
			count++;
		}
	}
	count++;
	return count;
}

int main()
{
	char s[] = "I am Yunen";
	printf("%d\n",count_word(s));
}