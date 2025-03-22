#include <stdio.h>

int main (void)
{
    int popularity , size;  //Define variables
    int homeWalue;

    printf ("Enter the popularity : \n");  //Enter 1
    scanf  ("%d", &popularity );  //Prompt 1

    printf ("Enter the size : \n"); //Enter 2
    scanf  ("%d", &size );  //Prompt 2

    homeWalue = (((pow ( popularity,3))  +  (pow(size,2))) * 10000 );  //Calculate home value
    
    printf  ("Home Value is : %d\n", homeWalue );  //Print the computed home value on the screen.

    return 0;  //Program ended successfully

}//End of the main function

/* Program started

Enter popularity : 
5
Enter size : 
2
Home Value : 1290000

Program ended */

 