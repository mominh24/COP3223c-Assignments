//Momin Hussain
//UCF COP3223

#include <stdio.h>

int Newsum(int);

int main()
{
    int number;

    printf("Enter a Positive Integer Number: ");
    //Telling user to enter a Positive number 
    scanf("%d", &number);

    printf("The sum of first %d numbers is %d.", number, Newsum(number));

    return 0;
}

int Newsum(int n) //Using recursion 
{
    if (n == 0)
        return 0;
    else
        return n + Newsum(n - 1);
}
	  
	  
