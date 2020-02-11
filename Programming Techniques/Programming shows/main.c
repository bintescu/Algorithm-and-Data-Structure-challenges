#include <stdio.h>
#include <stdlib.h>
typedef struct{
int data_inceput;
int data_sfarsit;
int profit;
int index;}proiect;

int cmp(const void *a, const void *b)
{
    int va=((proiect*)a)->data_sfarsit;
    int vb=((proiect*)b)->data_sfarsit;
    return va-vb;
}
void afisare(proiect v[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d %d %d %d \n",v[i].index, v[i].data_inceput, v[i].data_sfarsit, v[i].profit);
    }
}
int maxim(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    FILE *fin=fopen("date.in","r");
  int n;
  proiect v[20];
  fscanf(fin,"%d",&n);
  for(int i=0;i<n;i++)
    {fscanf(fin,"%d%d",&v[i].data_inceput,&v[i].data_sfarsit);
     fscanf(fin,"%d",&v[i].profit);
     v[i].index=i+1;
    }
    afisare(v,n);
    qsort(v,n,sizeof(proiect),cmp);
    printf("\n \n");
    afisare(v,n);

    for(int i=n;i>=1;i--)
    {
        v[i].data_inceput=v[i-1].data_inceput;
        v[i].data_sfarsit=v[i-1].data_sfarsit;
        v[i].index=v[i-1].index;
        v[i].profit=v[i-1].profit;
    }
    int ult[30];
    int j;
    ult[0]=0;
    ult[1]=0;
    for(int i=2;i<=n;i++)
    {   ult[i]=0;
        for(j=i-1;j>=0;j--)
        {
         if(v[j].data_sfarsit<=v[i].data_inceput)
         {ult[i]=j;
         break;
         }
        }


    }
    int pmax[30];
    pmax[0]=0;
    for(int i=1;i<=n;i++)
    {
        pmax[i]=maxim(pmax[i-1],(v[i].profit+pmax[ult[i]]));
    }
    printf("\n \n");
    for(int i=0;i<=n;i++)
    {
        printf("%d ",pmax[i]);
    }
    fclose(fin);
    int i=n;
    while(i>0)
    {
        if(pmax[i]!=pmax[i-1])
        {
            printf("%d ", v[i].index);
            i=ult[i];
        }
        else i--;
    }
    return 0;
}
