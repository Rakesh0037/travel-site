#include<stdlib.h>
#include<stdio.h>
#include<windows.h>

void ArraySorting(long int *stratingOfArray, int numberOfElements);
float calcMedian(long int *array, int numberOfElements);
void SetColorAndBackground(int ForgC, int BackC);

int main()
{
    FILE *inputFile;
    int number = 0;
	
    int numberOfElements = 29;
    int selectedNumber = 0;
    int i = 0;

    if(numberOfElements/2 != 0)
    {
        selectedNumber = (numberOfElements/2) + 1;
    }
    else
    {
        selectedNumber = (numberOfElements/2);
    }


    long int arrayOfNumbers[numberOfElements];
    long int selectedArray[selectedNumber];


    inputFile = fopen("sequence.txt","r");
    if(inputFile == NULL)
    {
        printf("unable to open");
    }

    while (!feof(inputFile))
    {
        fscanf(inputFile,"%d",&number);
        arrayOfNumbers[i] = number;
        i++;
    }

    ArraySorting(arrayOfNumbers, numberOfElements);

    int j = 0;

    for(int i = 0; i < numberOfElements; i++)
    {
        if(i%2 == 0)
        {
            selectedArray[j] = arrayOfNumbers[i];
            SetColorAndBackground(10,4);
            printf("arrayOfNumbers[%d]: %li\n", i, arrayOfNumbers[i]);
            SetColorAndBackground(0xFF,0);
            j++;
        }
        else
        {
            printf("%li\n", arrayOfNumbers[i]);
        }
    }

    SetColorAndBackground(10,4);
    printf("\n\n Value of Median: %.2f\n", calcMedian(selectedArray, selectedNumber));

    SetColorAndBackground(0xFF,0);
    return 0;
}

void ArraySorting(long int *stratingOfArray, int numberOfElements)
{
    int tmp = 0;

    for(int j=0; j<numberOfElements; j++)
    {
        for(int k=j+1; k<numberOfElements; k++)
        {
            if(stratingOfArray[k] <stratingOfArray[j])
            {
                tmp = stratingOfArray[j];
                stratingOfArray[j] = stratingOfArray[k];
                stratingOfArray[k] = tmp;
            }
        }
    }
}

float calcMedian(long int *array, int numberOfElements)
{
    int median = 0;
    if(numberOfElements/2 == 0)
    {
        int value_One = array[(numberOfElements/2)-1];
        int value_Two = array[(numberOfElements/2)];

        median = (value_One + value_Two)/2;

    }
    else
    {
        median = array[numberOfElements/2];
    }
    return median;
}

void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

