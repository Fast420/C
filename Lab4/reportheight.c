#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

struct person
{
    char name[30];
    float height;
};

int main()
{
    struct person people [1024];
    int count = 0;
    struct person single;
    //int file = open("data.txt",O_RDONLY);
    FILE *file= fopen("data.txt","r");
    float sum = 0;
    float max = 0;
    float min = 99999999;

    while (fscanf(file, "%s %f", single.name, &single.height) != EOF)
    {
        people[count] = single;
        sum += single.height;
        max = single.height > max ? single.height:max;
        min = single.height < min ? single.height:min;
        count += 1;
    }
    printf("Of the %d people the average height is %3.2fm, the tallest person is Jill at %3.2fm, and shortest is Bill at %fm.\n", count, sum/count, max, min);
}