// Yunen He 2014
/**
Excercise: Write a program in c called "welcome" that 
takes your name from standard input and outputs to standard out "Hello " and your name. 
**/
#include<stdio.h>
#include<stdlib.h>
#define NAMELEN 100
int main() {
  char name[NAMELEN];
  if (scanf("%s",name) > 0) {
     printf("Hello %s\n ",name);
  } else {
     printf("error scanning name. ");
  }
    return 0; 
}
