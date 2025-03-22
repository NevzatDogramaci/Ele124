#include <stdio.h>
#include <math.h>

int computeHomeValue (int popularity, int size);

int main ()
{

    int popularity, size;  //Define variables
    
    printf("Enter popularity : \n"); //Enter 1
    scanf("%d",&popularity);  //Prompt 1

    printf("Enter size : \n");  //Enter 2
    scanf("%d",&size);  //Prompt 2

    printf("Home Value : %d \n" , computeHomeValue ( popularity , size ) );  //Print the computed home value on the screen

    return 0;  //Program ended successfully

} //End of the main function

int computeHomeValue ( int popularity , int size )
{
    return (((pow( popularity , 3 ))  +  (pow(size , 2))) * 10000 ); //Calculate home value
}

/*Program started 

Enter popularity : 
5
Enter size : 
2
Home Value : 1290000

Porgam ended */