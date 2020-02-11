#include <stdio.h>
#include <stdlib.h>

int main()
{
   int v[10]={5,1,7,3,4,1,6,3,9,2};
   int lmax[10]={0}, succ[10],aux;
   lmax[9]=1;
   succ[9]=-1;
   for(int i=8;i>=0;i--)
   { int gasit=0;
       for(int j=i+1;j<=9;j++)
       if(v[j]>=v[i])
        {if(lmax[j]>=lmax[i]) {aux=j; lmax[i]=lmax[j]+1; }
        gasit=1;
        }
      if(gasit==0) {aux=-1; lmax[i]=1;}
    succ[i]=aux;
    }
    for(int i=0;i<=9;i++)
        printf("%d ",v[i]);
    printf("\n");
     for(int i=0;i<=9;i++)
        printf("%d ",lmax[i]);
    printf("\n");
    for(int i=0;i<=9;i++)
        printf("%d ",succ[i]);
   int max=lmax[0];
   for(int i=1;i<=9;i++)
   if(lmax[i]>max) {max=lmax[i]; aux=i;}
   int i=aux;
   while(succ[i]!=-1)
   {
       printf("\n%d",v[i]);
       i=succ[i];
   }
   printf("\n%d",v[i]);
    return 0;


}
