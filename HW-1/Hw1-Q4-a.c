#include <stdio.h>
#include <math.h>

int computeHomeValue (int popularity, int size);

int main ()
{

    int popularity, size;
    
    printf(" Enter popularity : \n");
    scanf("%d",&popularity);

    printf(" Enter size : \n ");
    scanf("%d",&size);

    printf( " Home Value : %d \n " , computeHomeValue ( popularity , size ) );

    return 0;
}

int computeHomeValue ( int popularity , int size )
{
    int homeValue; 
    
    homeValue = ( (  (pow( popularity , 3 ) )  +  ( pow( size , 2 ) )  ) * 1000 );

    return homeValue;
}
 