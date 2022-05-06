#include <stdio.h>
#include <conio.h>
int selection(int arr[], int n)
{
    int i, j, iteration = 0, comparison = 0, min, temp;
    for (i = 0; i < n - 1; i++)
    {
	iteration++;
	min = i;
	for (j = i + 1; j < n; j++)
	{
	    comparison++;
	    if (arr[j] < arr[min])
		min = j;
	}
	if (min != i)
	{
	    temp = arr[min];
	    arr[min] = arr[i];
	    arr[i] = temp;
	}
    }

    printf("\nThe sorted list is: ");
    for (i = 0; i < n; i++)
    {
	printf("%d  ", arr[i]);
    }

    printf("\n\nNumber of comparisons: %d", comparison);
    printf("\nNumber of iterations: %d", iteration);
    return (comparison + iteration);
}


int main()
{
    int inp[30];
    int n = 0, i = 0;
    clrscr();
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements to be sorted: ");
    for (i = 0; i < n; i++)
    {
	scanf("%d", &inp[i]);
    }
    printf("\n\nThe time complexity: %d", selection(inp, n));
    getch();
    return 0;
}


