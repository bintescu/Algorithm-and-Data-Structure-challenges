#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int ora_inceput;
    int ora_final;
    int index;
}spectacol;

typedef struct
{
    int continut[100];
    int ora_final;
    int k;
}sala;

void afisare(spectacol v[100],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d %d \n",v[i].ora_inceput,v[i].ora_final);
    }
}
int cmp(const void *a,const void *b)
{
    int va=((spectacol*)a)->ora_inceput;
    int vb=((spectacol*)b)->ora_inceput;
    return va-vb;
}
int main()
{
    FILE *fin=fopen("date.in","r");
    int n;
    spectacol v[100];
    sala S[100];
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
     {
         fscanf(fin,"%d",&v[i].ora_inceput);
         fscanf(fin,"%d",&v[i].ora_final);
        v[i].index=i+1;
     }
     afisare(v,n);
     qsort(v,n,sizeof(spectacol),cmp);
     printf("\n");
     afisare(v,n);
     S[0].continut[0]=v[0].index;
     S[0].k=1;
     S[0].ora_final=v[0].ora_final;
     int numarsala=0;
     for(int i=1;i<n;i++)
        S[i].k=0;
     for(int i=1;i<n;i++)
     {  int j=0,gasit=0;
        for(j=0;j<=numarsala;j++)
            if(v[i].ora_inceput >= S[j].ora_final) {gasit=1; break;}
       if(gasit==1) {S[j].continut[S[j].k]=v[i].index;
                     S[j].k++;
                     S[j].ora_final=v[i].ora_final;
                     }
      else
        { numarsala++;
         S[numarsala].continut[S[numarsala].k]=v[i].index;
         S[numarsala].k++;
         S[numarsala].ora_final=v[i].ora_final;
        }

     }

     for(int i=0;i<=numarsala;i++)
     {
         printf("\n");
         for(int j=0;j<S[i].k;j++)
            printf("%d ",S[i].continut[j]);
         printf(" Ora final=%d",S[i].ora_final);
     }
    return 0;
}
