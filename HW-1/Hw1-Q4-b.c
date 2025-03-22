#include <stdio.h>
#include <math.h>

void computeHomeValue (void);

int main (void)
{

    computeHomeValue ();



    return 0 ; //Succesfully terminate 
} //End of the main function

void computeHomeValue (void)
{
    int popularity, size;  //Define variables
    int homeValue;

    printf("Enter popularity : \n");  //Enter 1
    scanf( "%d", &popularity );  //Prompt 1

    printf("Enter size : \n");  //Enter 2
    scanf("%d", &size);  //Prompt 2

    homeValue = ( (pow(popularity,3) + pow(size, 2))* 10000 );  //Calculate home value

    printf("\nHome Value : %d \n", homeValue);  //Print the computed home value on the screen
}

/*Program started

Enter popularity : 
5
Enter size : 
2
 
Home Value : 1290000 

Program ended*/