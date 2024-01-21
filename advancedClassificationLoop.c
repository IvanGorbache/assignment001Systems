#include "NumClass.h"
#define TRUE 1
#define FALSE 0
#define GET_DIGIT 10
#define REMOVE_DIGIT 10
#define REMOVE_EDGES 2
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
int isPalindrome(int a)
{
    int length = getLength(a);
    while (a!=0)
    {
        if((a/powerOf(REMOVE_DIGIT,length-1)) != (a%GET_DIGIT))
        {
            return FALSE;
        }
        a = (a%powerOf(GET_DIGIT,length-1))/REMOVE_DIGIT;
        length-=REMOVE_EDGES;
    }
    return TRUE;
}
int isArmstrong(int a)
{
    int sum = 0;
    int b = a;
    int power = getLength(a);
    while (a!=0)
    {
        sum += powerOf(a%GET_DIGIT,power);
        a/=REMOVE_DIGIT;
    }
    
    return b == sum; 
}
