#include<stdio.h>
int main()
{
    int n,count=0;
    scanf("%d",&n);
    int a[n],i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int k;
    printf("Enter the element to be searched: \n");
    scanf("%d",&k);
    for(i=0;i<n;i++)
    {
        if(k==a[i])
        {
            printf("the element %d is in the location %d",k,i+1);
            count++;
        }
    }
    if(count==0)
        printf("Element has not been found");
}