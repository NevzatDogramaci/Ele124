#include <stdio.h>

int main (void)
{
    int popularity , size;
    int homeWalue;

    printf ( " Enter popularity : \n " );
    scanf  ( "%d", &popularity );

    printf ( " Enter size : \n " );
    scanf  ( "%d", &size );

    homeWalue = (  ( ( pow ( popularity,3 ) )  +  ( pow (size,2) ) ) * 1000  ); 
    
    printf  ( " Home Value : %d\n ", homeWalue );

    return 0;
}
 