#include <stdio.h>
#include <stdlib.h>
int x[100]={0},n;
int evalid(int k)
{
    for(int i=1;i<k;i++)
        if(x[i]==x[k]) return 0;
    for(int i=1;i<k;i++)
        if(x[i]<x[k]) return 0;
   return 1;
}

int esolutie(int k,int contor)
{
    if(k==contor) return 1;
    return 0;
}
void tipar(int k)
{ printf("\n");
    for(int i=1;i<=k;i++)
        printf("%d ",x[i]);
}
void bkt(int k,int contor)
{
    int i;
    for(i=1;i<=n;i++)
    {
        x[k]=i;
        if(evalid(k))
            if(esolutie(k,contor)) tipar(contor);
            else bkt(k+1,contor);
    }
}
int main()
{
    printf("\n Insert n! ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    bkt(1,i);


    return 0;
}
