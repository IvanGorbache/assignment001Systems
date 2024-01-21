#include "NumClass.h"
#define TRUE 1
#define FALSE 0
#define GET_DIGIT 10
#define REMOVE_DIGIT 10
#define MIN_LENGTH 2
int getLength(int a)
{
    int n = 0;
    do 
    {
        a/=10;
        n++;
    }while(a!=0);
    return n;
}
int powerOf(int a, int b)
{
    int result = 1;
    while (b>0)
    {
        result *= a;
        b--;
    }
    return result;
}
int isPalindrome(int a)
{
	if(getLength(a) == 1)
	{
		return TRUE;
	}
	else if(getLength(a) == MIN_LENGTH)
	{
		return a%GET_DIGIT == a/powerOf(REMOVE_DIGIT,getLength(a)-1);
	}
	return isPalindrome(a%powerOf(GET_DIGIT,getLength(a)-1)/REMOVE_DIGIT) && (a%GET_DIGIT == a/powerOf(REMOVE_DIGIT,getLength(a)-1));
	
}
int checkAromstrongRecrusive(int a,int digits)
{
	if(a!=0)
	{
		return powerOf(a%GET_DIGIT,digits) + checkAromstrongRecrusive(a/REMOVE_DIGIT, digits);
	}
	return 0;
}
int isArmstrong(int a)
{
	return checkAromstrongRecrusive(a,getLength(a)) == a;
}

