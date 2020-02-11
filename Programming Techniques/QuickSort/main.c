#include <stdio.h>
#include <stdlib.h>
int pivot(int v[],int st, int dr)
{
    int i=st,j=dr,aux,di=0,dj=-1;
    while(i<j)
    {
        if(v[i]>=v[j])
        {
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            aux=di; di=-dj; dj=-aux;
        }
        i=i+di;
        j=j+dj;
    }
}
int quickSort(int v[],int st,int dr)
{
    int p;
    if(st<dr)
    {
        p=pivot(v,st,dr);
        quickSort(v,st,p-1);
        quickSort(v,p+1,dr);
    }
}
int main()
{
    int v[50]={31,2,5,76,43,2,13,2,34,9};
    quickSort(v,0,10);
    int i;
    for(i=1;i<=10;i++)
    printf("%d ",v[i]);
    return 0;
}
