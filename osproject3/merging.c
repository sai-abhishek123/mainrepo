#include <stdio.h>
#include <stdlib.h>
void sorting(int arr[], int l, int m, int r)
{
	int i, j, k;
	int a=m-l+1;
	int b=r-m;
	int L[a],R[b];
	for (i=0;i<a;i++)
		L[i] = arr[l + i];
	for (j=0; j<b; j++)
		R[j] = arr[m + 1 + j];
	i=0,j=0,k=l;
	while (i<a&&j<b) {
		if (L[i]<=R[j]) 
        {
			arr[k]= L[i];
			i++;
		}
		else 
        {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i<a) {
		arr[k]=L[i];
		i++;
		k++;
	}
	while (j<b) {
		arr[k]=R[j];
		j++;
		k++;
	}
}
void merging(int arr[],int l,int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		merging(arr, l, m);
		merging(arr, m + 1, r);
		sorting(arr, l, m, r);
	}
}
int main()
{
FILE *ptr;
ptr=fopen("testcase.txt","r");
int n;
fscanf(ptr,"%d",&n);
int arr[n],b[n],c[n];
int i;
for(i=0;i<n;i++)
{
    fscanf(ptr,"%d",&arr[i]);
}
    printf("Printing array L1\n");
	for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
	merging(arr,0,n/4-1);
	merging(arr,n/4,n/2-1);
	merging(arr,n/2,3*n/4-1);
	merging(arr,3*n/4,n-1);
	printf("After Sort L2\n");
	for(i=0;i<n/4;i++)
    {
        printf("%d ",arr[i]);
        b[i]=arr[i];
    }
    printf("|");
    for(i=n/4;i<n/2;i++)
    {
        printf("%d ",arr[i]);
        b[i]=arr[i];
    }
    printf("|");
    for(i=n/2;i<3*n/4;i++)
    {
        printf("%d ",arr[i]);
        b[i]=arr[i];
    }
    printf("|");
    for(i=3*n/4;i<n;i++)
    {
        printf("%d ",arr[i]);
        b[i]=arr[i];
    }
    merging(b,0,n/2-1);
    merging(b,n/2,n-1);
    printf("\n");
    printf("After Sort L3\n");
    for(i=0;i<n/2;i++)
    {
        printf("%d ",b[i]);
        c[i]=b[i];
    }
    printf("|");
    for(i=n/2;i<n;i++)
    {
        printf("%d ",b[i]);
        c[i]=b[i];
    }
    printf("|");
    printf("\n");
    merging(c, 0, n-1);
	printf("After Sort L4\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",c[i]);
    }
    printf("\n");
}