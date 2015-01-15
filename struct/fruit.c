// Yunen He 2014
#include<stdio.h>
#include<string.h>

struct fruit
{
	char name[30];
	char number;
};

struct fruit lunch;
struct fruit *p;

int main ()
{
	strcpy(lunch.name,"Apple");
	lunch.number = 2;
	printf("size : %ld\n", sizeof(struct fruit));
	printf("%s: %d\n", lunch.name,lunch.number);

	p = &lunch;
	printf("%s : %d\n", p->name, p->number);
	printf("%s : %d\n", (*p).name,(*p).number);
	return 0;
}
