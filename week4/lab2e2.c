// Yunen He 2014
#include<stdio.h>
int main(){
int i = 0;
float sum = 0;
float num = 0;
float p_num = 0;
float max = 0;
float min = 0;

while(scanf("%f",&num)!=EOF)
{
	if (i == 0)
	{
		p_num = num;
		max = num;
		min = num;
	}
	else
	{
		if (num > p_num)
			max = num;
		else
			min = p_num;
	}
	sum+=num;
	p_num = num;
	i++;
}
printf("average %f\n",sum/i);
printf("min %f\n",min);
printf("max %f\n",max);
}


