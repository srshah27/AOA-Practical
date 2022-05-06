#include <stdio.h>
#include <conio.h>

int gcd(int n, int m)
{
    int gcd, remainder;
    while (n != 0)
    {
	remainder = m % n;
	m = n;
	n = remainder;
    }
    gcd = m;
    return gcd;
}

void main()
{
    int numerat, denoma;
    int capacity, n, cwt, item;
    int shared[10][10];
    int counter = 1;
    int used[10];
    float total_profit;
    int i;
    int weight[10];
    int value[10];
    int beforecwt;
    clrscr();
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight and value of %d item:\n", n);
    for (i = 0; i < n; i++)
    {
	printf("Weight[%d]: ", i);
	scanf("%d", &weight[i]);
	printf("Value [%d]: ", i);
	scanf("%d", &value[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
	used[i] = 0;

    cwt = capacity;
    while (cwt > 0)
    {
	item = -1;
	for (i = 0; i < n; i++)
	    if ((used[i] == 0) && ((item == -1) || ((float)value[i] / weight[i] > (float)value[item] / weight[item])))
		item = i;

	used[item] = 1;
	beforecwt = cwt;
	cwt -= weight[item];
	total_profit += value[item];
	if (cwt >= 0)
	{
	    printf("Added object %d (%d Rs., %d kg) completely in the bag.\tSpace left: %d.\n", item + 1, value[item], weight[item], cwt);
	    shared[counter][0] = 1;
	    shared[counter][1] = 1;
	    counter++;
	}
	else
	{
	    numerat = beforecwt / gcd(beforecwt, weight[item]);
	    denoma = weight[item] / gcd(beforecwt, weight[item]);
	    shared[counter][0] = numerat;
	    shared[counter][1] = denoma;
	    counter++;
	    printf("Added %d/%d of object %d (%d Rs., %d kg) in the bag.\n", numerat, denoma, item + 1, value[item], weight[item]);
	    total_profit -= value[item];
	    total_profit += (1 + (float)cwt / weight[item]) * value[item];
	}
    }
    printf("\nThe bag is filled with objects worth %.2f Rs.\n", total_profit);
    getch();
}