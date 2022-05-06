#include <stdio.h>
#include <conio.h>

int cc = 0, swap = 0;

void quickSort(int a[], int low, int high)
{
    int temp, start, end;
    if (low < high)
    {
	int pivot = low;
	start = low;
	end = high;
	while (start < end)
	{
	    while (a[start] <= a[pivot])
	    {
		start++;
		cc++;
	    }
	    while (a[end] > a[pivot])
	    {
		end--;
		cc++;
	    }
	    if (start < end)
	    {
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		swap++;
	    }
	}
	temp = a[low];
	a[low] = a[end];
	a[end] = temp;
	swap++;
	quickSort(a, low, end - 1);
	quickSort(a, end + 1, high);
    }
}

void main()
{
    int a[20];
    int n, i, lb, ub;
    clrscr();
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
	scanf("%d", &a[i]);
    }
    quickSort(a, 0, n - 1);
    printf("\nThe sorted array: ");
    for (i = 0; i < n; i++)
    {
	printf("%d ", a[i]);
    }
    printf("\nNumber of Comparisons: %d", cc);
    printf("\nNumber of Swappings: %d", swap);
    printf("\nNumber of Operations: %d", swap + cc);
    getch();
}

//Best : 8 1 3 2 6 5 7 4 12 9 11 10 14 13 15
//Wosrt: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
//Avg : 1 15 2 14 3 13 4 12 5 11 6 10 7 9 8