#include<stdio.h>
#include<time.h>
int clocking()
{
clock_t s,e;
double ct;
s=clock();
e=clock();
ct=((double)(e-s))/CLOCKS_PER_SEC;
return ct;
}