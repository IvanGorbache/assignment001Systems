#include "NumClass.h"
#define TRUE 1
#define FALSE 0
#define GET_DIGIT 10
#define REMOVE_DIGIT 10
#define MIN_LENGTH 2
//getLenfth gets an integer and counts the number of digits in it by removing the last digit until it reaches zero.
int getLength(int a)
{
    int n = 0;
    //Using a do while loop for the case that the user inputs 0 as the integer.
    do 
    {
       	//removing the last digit
        a/=REMOVE_DIGIT;
       	//adding to the the digit count
        n++;
    }while(a!=0);//continue until it reaches zero
    //returning result
    return n;
}
//powerOf impliments the power function a^b
int powerOf(int a, int b)
{
    int result = 1;
    //While the exponent of power is bigger than zero, multiply.
    while (b>0)
    {
        //multiply
        result *= a;
        b--;
    }
    return result;
}
//isPalindromeCheck recursive check if a number is palindrome by continuously stripping it of its first and last digit till we reach zero
int isPalindromeCheck(int a, int len)
{
	//Base case: a single digit
	if(len == 1)
	{
		return TRUE;
	}
	//Base case: a two digit number
	else if(len == MIN_LENGTH)
	{
		return a%GET_DIGIT == a/REMOVE_DIGIT;
	}
	//A recursive call with the edges removed. Checking if the edges are the same 
	return isPalindromeCheck((a%powerOf(GET_DIGIT,len-1))/REMOVE_DIGIT,len-2) && (a%GET_DIGIT == a/powerOf(REMOVE_DIGIT,len-1));
	
}
//using an extra helper function to check in a number is palindrome to maintain original length
int isPalindrome(int a)
{
	return isPalindromeCheck(a, getLength(a));	
}
//checkAromstrongRecrusive recursivly checks if a number is an armstrong number by summing all of its digits to the powre of its length and checking if they are equal
int checkAromstrongRecrusive(int a,int digits)
{
	//recursive call until we reach zero
	if(a!=0)
	{
		return powerOf(a%GET_DIGIT,digits) + checkAromstrongRecrusive(a/REMOVE_DIGIT, digits);
	}
	return 0;
}
// using an extra helper function to check in a number is Armstrong to maintain original length
int isArmstrong(int a)
{
	return checkAromstrongRecrusive(a,getLength(a)) == a;
}

