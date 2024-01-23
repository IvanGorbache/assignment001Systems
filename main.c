#include <stdio.h>
#include <stdlib.h>
#include "NumClass.h"
#define MINARGS 3
#define START_ARG 1
#define END_ARG 2
int main(int argc, char *argv[]){
	int start = 0, finish = 0, i = 0;
	if(argc!=MINARGS)
	{
		scanf("%d",&start);
		scanf("%d",&finish);
	}
	else
	{
		start = atoi(argv[START_ARG]);
		finish = atoi(argv[END_ARG]);
	}
	if((start>0 && finish> 0) && (start<=finish))
	{
		printf("The Armstrong numbers are:");
		for(i = start;i<=finish;i++)
		{
			if(isArmstrong(i))
			{
				printf(" %d",i);
			}
		}
		printf("\nThe Palindromes are:");
		for(i = start;i<=finish;i++)
		{
			if(isPalindrome(i))
			{
				printf(" %d",i);
			}
		}
		printf("\nThe Prime numbers are:");
		for(i = start;i<=finish;i++)
		{
			if(isPrime(i))
			{
				printf(" %d",i);
			}
		}
		printf("\nThe Strong numbers are:");
		for(i = start;i<=finish;i++)
		{
			if(isStrong(i))
			{
				printf(" %d",i);
			}
		}
	}
	return 0;
}
