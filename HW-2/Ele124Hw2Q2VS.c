#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float genNumber ();
void Hunerler (float itemPrice, float *donationTotal , float *profitTotal);

int main (void)
{
    srand(time(NULL));

    float itemPrice = 0, donationTotal = 0, profitTotal = 0;
    float donationPart, profitPart;

    FILE *filePtr = fopen("HUnerlerDSR.txt", "a+");

    printf("HUnerler - Daily Sales Report\n");
    printf("=============================\n");

    for (int i = 0; i < 50; i++)
    {
        itemPrice = genNumber();

        Hunerler(itemPrice, &donationTotal, &profitTotal);

        printf("Item %d is $%5.2f\n",i + 1, itemPrice);
        
        fprintf(filePtr, "Item %d is $%5.2f\n",i + 1, itemPrice);
    }

    printf("Porfit is $%.2f\n", profitTotal);
    printf("Donation is $%.2f\n", donationTotal);

    fprintf(filePtr, "Total profit kept by store: $%.2f\n", profitTotal);
    fprintf(filePtr, "Total donated to university: $%.2f\n", donationTotal);

    fclose(filePtr);
    return 0;
}

float genNumber ()
{
    return ((float)(rand() % 2000)) / 100.0 ;
}

void Hunerler (float itemPrice, float *donationTotal, float *profitTotal)
{
    *profitTotal += (int)itemPrice;
    *donationTotal += itemPrice - (int)itemPrice;
}