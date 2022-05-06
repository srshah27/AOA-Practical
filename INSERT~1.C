#include <stdio.h>
#include <conio.h>

int insertion(int arr[], int n)
{
    int i, temp, j, comparison = 0, iteration = 0;
    for (i = 1; i < n; i++)
    {
	temp = arr[i];
	j = i - 1;
	iteration++;

	while (j >= 0 && arr[j] > temp)
	{
	    arr[j + 1] = arr[j];
	    j--;
	    comparison++;
	}

	arr[j + 1] = temp;
    }
    printf("\nThe sorted list is: ");
    for (i = 0; i < n; i++)
    {
	printf("%d  ", arr[i]);
    }

    printf("\n\nNumber of comparison: %d", comparison);
    printf("\nNumber of iteration: %d", iteration);

    return (comparison + iteration);
}
int main()
{
    int inp[30];
    int n = 0;
    int i = 0;
    clrscr();
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements to be sorted: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &inp[i]);
    }
    
    printf("\n\nThe time complexity: %d", insertion(inp, n));
    getch();
    return 0;
}

