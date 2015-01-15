// Yunen He 2014
#include<stdio.h>
#include<math.h>

#define SIZE 10

//
double dist(double x1, double y1, double x2, double y2)
{
	double dist = 0;
	dist = sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
	return dist;
}


int main()
{
	double x = 0;
	double y = 0;
	double sum = 0;
	int index = 0;
	
	//
	double x1 = 0;
	double x2 = 0;
	double y1 = 0;
	double y2 = 0;

	//
	double xArray[SIZE];
	double yArray[SIZE];

	while(scanf("%lf %lf",&x,&y) == 2)
	{
		xArray[index] += x;
		yArray[index] += y;
		index++;
	}

	int count = 0;
	count = index - 1;
	int i = 0;

	while(count > 0)
	{
		//
		x1 = xArray[i];
		y1 = yArray[i];

		x2 = xArray[i+1];
		y2 = yArray[i+1];

		sum += dist(x1,y1,x2,y2);

		//
		count--;
		i++;
	}

	printf("total distacne: %lf\n",sum);
	return 0;
}