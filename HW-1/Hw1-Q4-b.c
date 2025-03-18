#include <stdio.h>
#include <math.h>

void computeHomeValue (void);

int main (void)
{

    computeHomeValue ();



    return 0 ;
}
void computeHomeValue (void)
{
    int popularity, size; 
    int homeValue;

    printf( " Enter popularity : \n" );
    scanf( "%d", &popularity );

    printf(" Enter size : \n");
    scanf("%d", &size);

    homeValue = ( pow( popularity,3 ) + pow( size, 2 ) ) * 1000;

    printf(" \n Home Value : %d \n ", homeValue);


}