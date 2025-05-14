#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function prototypes
void generate_signal(int signal[], int size);	
void clean_signal(int signal[], int size);        
int find_max(int signal[], int size);		      
int find_min(int signal[], int size);			 
float find_average(int signal[], int size);     

int main (void)
{
	int signal[100];
	int size = sizeof (signal) / sizeof (signal[0]); // Calculate array size
	int i;

	generate_signal(signal, size);
	printf("Original signals : \n");
	for (i = 0; i < size; i++)
	{
		if (i % 5 == 0)		// New line every 5 signals for neat display
		{
			printf("\n");
		}
		printf("signal[%2d] = %3d\t", i, signal[i]);
	}
	
	clean_signal(signal, size);
	printf("\n\nClean signals\n");
	for (i = 0; i < size; i++)
	{
		if (i % 5 == 0)
		{
			printf("\n");
		}
		printf("signal[%2d] = %3d\t", i, signal[i]);
	}

	printf("\n\nMax = %d \n",find_max (signal, size));
	printf("\nMin = %d \n",find_min (signal, size));
	printf("\nAverage = %.3f \n",find_average (signal, size));

	return 0;
}
// Generates random signal values and inserts -1 at 10 random positions
void generate_signal(int signal[], int size)
{
	srand (time(NULL));
	for (int i = 0; i < size; i++)
	{
		signal[i] = (rand() % 101);		//create signal
	}
	
	int count = 0;  	// count of -1
	while (count < 10)
	{
		int index = rand() % 100;
		if (signal[index] != -1)
		{
			signal[index] = -1;
			count++;
		}
	} 
} 
void clean_signal(int signal[], int size)		// Replaces corrupted signals (-1) with nearby average
{
	for (int i = 0; i < size; i++)
	{
		if (signal[i] == -1)
		{
			if (i == 0)
			signal[i] = signal[i+1] /2;
			
			else if (i == size - 1)
			signal[i] = signal[i-1]  /2;
			
			else 
			signal[i] = ( ( signal[i-1] + signal [i+1] ) /2 );
		}
	}
}
int find_max(int signal[], int size)	  // Returns the maximum value in the signal array
{
	int max = signal[0];
	
	for (int i = 1; i < size; i++)
	{
		if (signal[i] > max)
		{
			max = signal [i];
		}
	}
	return max;
}
int find_min(int signal[], int size)		// Returns the minimum value in the signal arra
{
	int min = signal[0];
	
	for (int i = 1; i < size; i++)
	{
		if (signal[i] < min)
		{
			min = signal [i];
		}
	}
	return min;
}
float find_average(int signal[], int size)		// Calculates and returns the average of the signal values
{
	float total = 0.0;
	for (int i = 0; i < size; i++)
	{
		total += signal[i];
	}
	float average = (total / size);
	return average;
}