#include <stdio.h>
#include <stdlib.h>
#include "NumClass.h"
#define MINARGS 3
#define START_ARG 1
#define END_ARG 2
int main(int argc, char *argv[]){
	//Declaring the start and finish of our number range.
	int start = 0, finish = 0, i = 0;
	//Checking if we have enough arguments
	if(argc==MINARGS)
	{
		//Getting an input from the console
		start = atoi(argv[START_ARG]);
		finish = atoi(argv[END_ARG]);
	}
	else
	{
		//Gettign a direct input from the user if we don't have arguments from the console
		scanf("%d",&start);
		scanf("%d",&finish);
	}
	//Checking if start is smaller than finish and that both are positive
	if((start > 0 && finish> 0) && (start <= finish))
	{
		//printing all the armstrong numbers in our range
		printf("The Armstrong numbers are:");
		for(i = start;i<=finish;i++)
		{
			if(isArmstrong(i))
			{
				printf(" %d",i);
			}
		}
		//printing all the palindromes in our range
		printf("\nThe Palindromes are:");
		for(i = start;i<=finish;i++)
		{
			if(isPalindrome(i))
			{
				printf(" %d",i);
			}
		}
		//printing all the primes in our range
		printf("\nThe Prime numbers are:");
		for(i = start;i<=finish;i++)
		{
			if(isPrime(i))
			{
				printf(" %d",i);
			}
		}
		//printing all the strong numbers in our range
		printf("\nThe Strong numbers are:");
		for(i = start;i<=finish;i++)
		{
			if(isStrong(i))
			{
				printf(" %d",i);
			}
		}
		printf("\n");
	}
	return 0;
}
