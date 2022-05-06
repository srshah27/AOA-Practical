#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int a[20];
int n,i;
int cc = 0;
void Merge(int, int);
void Msort(int, int, int);
void Disp();

void main()
{
    clrscr();
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter Elements: ");
    for(i = 0; i < n; i++)
    {
	scanf("%d",&a[i]);
    }
    Merge(0,n-1);
    printf("\n");
    Disp();
    printf("\nNumber of Comparisons/Operations: %d", cc);
    getch();
}

void Merge(int low, int high)
{
    int mid;
    if(low!=high)
    {
	mid=(low+high)/2;
	Merge(low,mid);
	Merge(mid+1,high);
	Msort(low,mid,high);
    }
}

void Msort(int low, int mid, int high)
{
    int temp[20];
    int i=low;
    int j=mid+1;
    int k=low;
    while((i<=mid)&&(j<=high))
    {
	cc++;
	if(a[i]<=a[j])
	temp[k++]=a[i++];
	else
	temp[k++]=a[j++];
    }
    while(i<=mid)
	temp[k++]=a[i++];
    while(j<=high)
	temp[k++]=a[j++];
    for(i=low;i<=high;i++)
	a[i]=temp[i];
}

void Disp()
{
    printf("The sorted array is: ");
    for(i=0;i<n;i++)
    {
	printf("%d ",a[i]);
    }
}

//Best: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
//Worst: 1 15 2 14 3 13 4 12 5 11 6 10 7 9 8
//Avg: 8 1 3 2 6 5 7 4 12 9 11 10 14 13 15