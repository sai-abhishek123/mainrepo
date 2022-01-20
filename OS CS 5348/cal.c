#include<stdio.h>
#include<string.h>
#include "quadratic.c"
#include "triples.c"
#include "sum.c"
main()
{
    int n;
    scanf("%d",&n);
    while(n>=1)
    {
    char a[12];
    scanf("%s",a);
    if(strcmp(a,"quadratic")==0)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        quadratic_solution(a,b,c);
    }
    else if(strcmp(a,"triples")==0)
    {
        int d,e;
        scanf("%d%d",&d,&e);
        find_triples(d,e);
    }
    else if(strcmp(a,"mod-sum")==0)
    {
        int g,h;
        scanf("%d%d",&g,&h);
        modular_sum(g,h);
    }
    n--;
    }
}