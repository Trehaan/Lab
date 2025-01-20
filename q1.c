#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int num;
	int opcounts[50];
} tests;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int* arr,int len, tests* counter)
{
	int i,j;
	for (i = 0; i < len - 1; i++)
	{
		for (j=0;j<len-i-1;j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				counter->opcounts[counter->num]++;
			}
		}
	}

	counter->num ++;

}

int main()
{
	int i,n;
	tests* Tests = (tests*) malloc(sizeof(tests));
	Tests->num = 0;

	while (n != -1)
	{
		printf("\nEnter the length of the array : ");
		scanf("%d",&n);

		if (n == -1)
			break;

		int arr[n];

		for (i = 0; i<n; i++)
		{
			printf("Enter element %d : ",i+1);
			scanf("%d",&arr[i]);
		}

		bubbleSort(arr,n,Tests);

		printf("\nSorted array : ");
		for (i = 0; i < n; i++)
			printf("%d\t",arr[i]);

		printf("Opcount = %d",Tests->opcounts[Tests->num - 1]);
	}

	return 0;
}