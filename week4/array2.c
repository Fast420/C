// Yunen He 2014
#include<stdio.h>
/**
Write a program that does basic operations on 3x3 matrixes included addition and multiplication
**/

int array1[3][3];
int array2[3][3];
int array3[3][3];
int main()
{
	array1[0][0] = 6;
	array1[0][1] = 9;
	array1[0][2] = 0;
	array1[1][0] = 5;
	array1[1][1] = 8;
	array1[1][2] = 1;
	array1[2][0] = 7;
	array1[2][1] = 4;
	array1[2][2] = 0;	

	array2[0][0] = 7;
	array2[0][1] = 7;
	array2[0][2] = 1;
	array2[1][0] = 3;
	array2[1][1] = 5;
	array2[1][2] = 3;
	array2[2][0] = 5;
	array2[2][1] = 6;
	array2[2][2] = 3;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			array3[i][j] = 0;
		}
	}	
printf("addition \n");
//  adds two 3x3 matrices
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("%d ",array1[i][j]);
		}
		printf(" ");

		for (int j = 0; j < 3; ++j)
		{
			printf("%d ",array2[i][j]);
		}
		printf(" ");
		for (int j = 0; j < 3; ++j)
		{
			array3[i][j] = array1[i][j] + array2[i][j];
			printf("%d ",array3[i][j]);
		}
		printf("\n");
	}
printf("\n");
// multiplies two 3x3 matrices
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			array3[i][j] = 0;
		}
	}	
printf("multiplication \n");
	for (int i = 0; i < 3; ++i)
	{	
		for (int j = 0; j < 3; ++j)
		{
			printf("%d ",array1[i][j]);
		}
		printf(" ");

		for (int j = 0; j < 3; ++j)
		{
			printf("%d ",array2[i][j]);
		}
		printf(" ");	
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				array3[i][j] += array1[i][k] * array2[k][j];
			}
		printf("%d ",array3[i][j]);
		}
		printf("\n");
	}
}