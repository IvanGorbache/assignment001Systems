#include "NumClass.h"
#define TRUE 1
#define FALSE 0
#define PRIME_MIN 2
#define GET_DIGIT 10
#define REMOVE_DIGIT 10
//implementing the factorial funtion !a
int factorial(int a)
{
    	int sum = 1;
    	while (a!=0)
    	{
        	sum*=a--;
    	}
    	return sum;
    
}
//checking if a number is prime
int isPrime(int a)
{
	//checking if the number is smaller than one
	if(a < 1)
	{
		return FALSE;
	}
	//checing if the number is divisible by half of the numbers before him.
    	for(int i = PRIME_MIN;i<=a/PRIME_MIN;i++)
    	{
        	if(a%i==0)
       		{
        	    return FALSE;
        	}
    	}
    	return TRUE;
}
//checking if a number is strong by checking it's equal to the sum of its digits factorial
int isStrong(int a)
{
    	int sum = 0;
    	int b = a;
    	while (a!=0)
    	{
        	sum+=factorial(a%GET_DIGIT);
        	a/=REMOVE_DIGIT;
   	}
   	return b==sum;
}
