// Yunen He 2014
#include<stdio.h>
#define TIMESTWOA(x) 2.0 * x
#define TIMESTWOB(x) ((x)+(x))
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MYFOR(E) for (int i = 0; i < E; ++i)
#define ADDFUN(x) fun ##x()

int main()
{
	printf("%f\n",TIMESTWOA(2+3));
	printf("%f\n",TIMESTWOA(2));
	printf("%f\n",1.0/TIMESTWOA(2));
	printf("%f\n",TIMESTWOA(1+1+1+1));
	printf("%d\n",MAX(1,2));
	printf("%d\n",TIMESTWOB(1*2*3));

	MYFOR(5)
	{
		printf("haha\n");
	}
}