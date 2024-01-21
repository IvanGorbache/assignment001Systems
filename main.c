#include <stdio.h>
#include "NumClass.h"
int main(){
	int start = 0, finish = 0, i = 0;
	scanf("%d",&start);
	scanf("%d",&finish);
	if((start>0 && finish> 0) && (start<=finish))
	{
		printf("\nThe Armstrong numbers are: ");
		for(i = start;i<=finish;i++)
		{
			if(isArmstrong(i))
			{
				printf("%d ",i);
			}
		}
		printf("\nThe palindrome numbers are: ");
		for(i = start;i<=finish;i++)
		{
			if(isPalindrome(i))
			{
				printf("%d ",i);
			}
		}
		printf("\nThe Prime numbers are: ");
		for(i = start;i<=finish;i++)
		{
			if(isPrime(i))
			{
				printf("%d ",i);
			}
		}
		printf("\nThe Strong numbers are: ");
		for(i = start;i<=finish;i++)
		{
			if(isStrong(i))
			{
				printf("%d ",i);
			}
		}
	}
	printf("\n");
	return 0;
}
