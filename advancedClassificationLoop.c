#include "NumClass.h"
#define TRUE 1
#define FALSE 0
#define GET_DIGIT 10
#define REMOVE_DIGIT 10
#define REMOVE_EDGES 2
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
    }while(a!=0); //continue until it reaches zero
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
//isPalindrome checks if a number is palindrome by continuously stripping it of its first and last digit till we reach zero
int isPalindrome(int a)
{
    int length = getLength(a);
    //continuously stripping it of its first and last digit till we reach zero
    while (a!=0)
    {
    	//chceking if the first and last digit are the same
        if((a/powerOf(REMOVE_DIGIT,length-1)) != (a%GET_DIGIT))
        {
            return FALSE;
        }
        //remvoing the first and last digit
        a = (a%powerOf(GET_DIGIT,length-1))/REMOVE_DIGIT;
        //updating the length
        length-=REMOVE_EDGES;
    }
    return TRUE;
}
//isArmstrong checks if a number is an armstrong number by summing all of its digits to the powre of its length and checking if they are equal
int isArmstrong(int a)
{
    int sum = 0;
    int b = a;
    int power = getLength(a);
    //continue until we reach zero
    while (a!=0)
    {
    	//adding to the sum
        sum += powerOf(a%GET_DIGIT,power);
        //removing last digit
        a/=REMOVE_DIGIT;
    }
    //checking if they are equal
    return b == sum; 
}
