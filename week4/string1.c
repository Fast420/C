// Yunen He 2014
// Write a function that determines if a string is a palindrome
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int start = 0;
int size = 0;
char reversed_s[] = "";

int palindrome(char s[])
{
	size = strlen(s);
	//reverse the string
	for (int i = size - 1; i >= 0; --i)
	{
		reversed_s[start] = s[i];
		start++;
	}

	// comapre them
	for (int j = 0; j < size; ++j)
	{
		if (reversed_s[j] != s[j])
		{
			printf("%c",s[j]);
			return 0;
		}
	}
	return 1;
}

int main()
{
	char s[] = "Wassamassaw";
	// convert characters to lower case
	size = strlen(s);
	for (int i = 0; i < size; ++i)
	{
		s[i] = tolower(s[i]);
	}
	printf("%d\n",palindrome(s));
}
