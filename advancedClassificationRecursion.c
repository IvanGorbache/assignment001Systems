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
        a/=REMOVE_DIGIT;
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
int isPalindromeCheck(int a, int len)
{
	if(len == 1)
	{
		return TRUE;
	}
	else if(len == MIN_LENGTH)
	{
		return a%GET_DIGIT == a/REMOVE_DIGIT;
	}
	return isPalindromeCheck((a%powerOf(GET_DIGIT,len-1))/REMOVE_DIGIT,len-2) && (a%GET_DIGIT == a/powerOf(REMOVE_DIGIT,len-1));
	
}
int isPalindrome(int a)
{
	return isPalindromeCheck(a, getLength(a));	
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

