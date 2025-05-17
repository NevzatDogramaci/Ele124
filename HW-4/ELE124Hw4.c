#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char *word;
    int frequency;
} WordFrequency; // it keeps each different word in its structure

// function prototype
int ReadAndClean   ( FILE* fp , char c[] );  // The word is converted to a lowercase letter and punctuation marks are discarded
void ListAndPrint  ( WordFrequency *wordArray , int N );   //Sorted and printed alphabetically or by frequency
void cleanMemory   (WordFrequency x[], int N);
int  FindIndex     ( WordFrequency *wordArray , char *c , int N );

int main()
{
    WordFrequency *wordArray = NULL;
    int wordCount = 0;
    FILE *fp;
    int i;

    fp = fopen( "input.txt", "r");

    if ( fp == NULL ) // File checked
    {
        printf ("The file could not be opened");
        return 0;
    }

	char word[200];
    while ( ReadAndClean ( fp , word ) )
    {
    	if (strlen ( word ) == 0 )
            continue;

        int indx = FindIndex ( wordArray , word , wordCount);
        if ( indx != -1 )
            wordArray[indx].frequency++;

        else
        {
            wordArray = ( WordFrequency* ) realloc ( wordArray , ( wordCount + 1 ) * sizeof ( WordFrequency ) );
            if ( wordArray == NULL )
            {
                printf( "Memory allocation failed" );
                cleanMemory ( wordArray , wordCount );
                return 0;
            }

            wordArray[wordCount].word = ( char* ) calloc ( strlen ( word) + 1 , sizeof (char) );
            if ( wordArray[wordCount].word == NULL )
            {
                printf( "Memory allocation failed" );
                cleanMemory ( wordArray , wordCount );
                return 0;
            }
            strcpy ( wordArray[wordCount].word , word );
            wordArray[wordCount].frequency = 1;
            wordCount++;
        }
    }
    fclose (fp);
    ListAndPrint ( wordArray , wordCount );

    cleanMemory ( wordArray , wordCount );

    return 0;
}

int ReadAndClean ( FILE* fp , char c[] )
{
	if ( fscanf ( fp, "%s", c ) == EOF ) // in each cycle, the words are assigned to word
 		return 0;

    char temp[200];
    int i = 0, j = 0;

    while ( c[i] != '\0' )
    {
        if ( isalnum ( c[i] ) ) // Only letters are taken and converted to lowercase before being assigned
        {
            temp [j++] = tolower ( c[i] );
        }
        i++;
    }
    temp [j] = '\0';

    strcpy ( c , temp ); // The temporary array is copied into the original array
	return 1;
}

void ListAndPrint  ( WordFrequency x[] , int N )
{
    int i, j;
    WordFrequency temp;
    char choice;

    do
    {
        printf("Please select the sorting type : \n");
        printf("Enter 'a' for alphabetical sorting or 'f' for frequency-based sorting\n");
        scanf(" %c", &choice);
    }while ( choice != 'a' && choice != 'f' );

    if ( choice == 'a' ) // The words are sorted alphabetically
    {
        for ( i = 0; i < N -1; i++ )
        {
            for ( j = i + 1; j < N; j++)
            {
                if ( strcmp ( x[i].word , x[j].word ) > 0 )
                {
                    temp = x[i];
                    x[i] = x[j];
                    x[j] = temp;
                }
            }
        }
    }

    if ( choice == 'f' ) // The frequencies are sorted in ascending order
    {
        for ( i = 0; i < N -1; i++ )
        {
            for ( j = i + 1; j < N; j++)
            {
                if  ( x[i].frequency > x[j].frequency )
                {
                    temp = x[i];
                    x[i] = x[j];
                    x[j] = temp;
                }
            }
        }
    }
    // The results are printed in the desired order
    printf("\n------------------------------------------\n");
    printf("       WORDS         ||      FREQUENCY      \n");
    printf("------------------------------------------\n");
    for ( i = 0; i < N; i++ )
    {
        printf( "%-15s %15d\n", x[i].word, x[i].frequency );
    }
    printf("------------------------------------------\n\n");
}

void cleanMemory(WordFrequency *wordArray, int N)
{
    for (int i = 0; i < N; i++)
    {
        free(wordArray[i].word);
    }
    free(wordArray);
}
int FindIndex ( WordFrequency *wordArray , char *c , int N )
{
	for ( int i = 0; i < N; i++)
	{
		if ( strcmp (wordArray[i].word , c) == 0 )
		{
			return i;
		}
	}
	return -1;
}