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
int ReadAndClean   ( FILE* fp , char **c );  // The word is converted to a lowercase letter and punctuation marks are discarded
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

	char *word;
    while ( ReadAndClean ( fp , &word ) )
    {
        int indx = FindIndex ( wordArray , word , wordCount);

        if ( indx != -1 )
        {
            wordArray[indx].frequency++;
            free ( word );

        }

        else
        {
            wordArray = ( WordFrequency* ) realloc ( wordArray , ( wordCount + 1 ) * sizeof ( WordFrequency ) );
            if ( wordArray == NULL )
            {
                printf( "Memory allocation failed" );
                free ( word );
                cleanMemory ( wordArray , wordCount );
                return 0;
            }
            wordArray[wordCount].word = word;
            wordArray[wordCount].frequency = 1;
            wordCount++;
        }
    }
    fclose (fp);
    ListAndPrint ( wordArray , wordCount );

    cleanMemory ( wordArray , wordCount );

    return 0;
}

int ReadAndClean( FILE *fp, char **c )
{
    int ch;
    int i = 0;
    int size = 20;

    *c = (char *) malloc ( size * sizeof (char) );
    if ( *c == NULL )
    {
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)         // retrieves all characters until the end of the file
    {
        if (isalpha(ch))
        {
            if ( i > ( size - 1 ) )             // sufficient memory allocation block
            {
                size++;
                *c = ( char* ) realloc ( *c, size * sizeof (char) );

                if ( *c == NULL )
                {
                    free ( *c );
                    return 0;
                }
            }
            (*c)[i++] = tolower(ch);
        }

        else if (i > 0)         //break the loop if it is not alphanumeric
        {
            break;
        }

    }
    (*c)[i] = '\0';         // for strcmp

    if (i == 0 && ch == EOF)
    {
        free ( *c );
        return 0;
    }

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
        free(wordArray[i].word);     // the space allocated for each word is deleted
    }
    free(wordArray);        // the space allocated for the entire structure is deleted
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
