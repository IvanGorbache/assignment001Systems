#include "NumClass.h"
#define TRUE 1
#define FALSE 0
#define PRIME_MIN 2
#define GET_DIGIT 10
#define REMOVE_DIGIT 10
int factorial(int a)
{
    	int sum = 1;
    	while (a!=0)
    	{
        	sum*=a--;
    	}
    	return sum;
    
}
int isPrime(int a)
{
	if(a < 1)
	{
		return FALSE;
	}
    	for(int i = PRIME_MIN;i<=a/PRIME_MIN;i++)
    	{
        	if(a%i==0)
       		{
        	    return FALSE;
        	}
    	}
    	return TRUE;
}
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
