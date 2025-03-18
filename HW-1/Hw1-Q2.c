    /* Addition program 
    #include <stdio.h>


    int main( void )
    {
      
       int integer1     
            //ERROR !!!   Missing semicolon (;)
    
     
        int integer2 
            //ERROR !!!  Missing semicolon (;)
    
      
        int x;      
            //Warning !  Unnecessary variable declaration, (x) never used
    
      
        printf( Enter first integer\n ); 
            //ERROR  !!! String must be enclosed in double quotes
        scanf( "%d", &integer1 );       
    
       
        printf( "Enter second integer\n" ); 
        scanf( "%d", &integer2 );           
       
      
        sum = integer1 + integer2; 
            //ERROR !!! Dont have variable sum declared
    
       
            printf( "Sum is %d\n", sum ); 
            //Warning !!! sum is not declared, so it cannot be printed
    
       return 0;                                                */
    
    
    
    
       /* Addition program */
    
       #include <stdio.h>
    
    /* function main begins program execution */
    int main( void )
    {
       int integer1;        /* first number to be input by user  */ 
       int integer2;        /* second number to be input by user */
       int sum;               /* variable in which sum will be stored */ 
    
       printf( "Enter first integer\n" );          /* prompt */
       scanf( "%d", &integer1 );                /* read an integer */
    
       printf( "Enter second integer\n" );       /* prompt */
       scanf( "%d", &integer2 );                /* read an integer */
       
       sum = integer1 + integer2;               /* assign total to sum */
    
       printf( "Sum is %d\n", sum );             /* print sum */
       return 0;                                /* indicate that program ended successfully */
    
    }      /* end function main */
    
/* 
    Enter first integer  
    4
    Enter second integer
    5
    Sum is 9    */