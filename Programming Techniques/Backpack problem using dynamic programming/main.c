#include <stdio.h>
#include <stdlib.h>

int maxim(int a,int b)
{
    if(a>b) return a;
    else return b;
}
void afisare(int n,int G, int M[n][G])
{ printf("\n");
    for(int i=0;i<=n;i++)
    {
        printf("\n");
        for(int j=0;j<=G;j++)
            printf("%d ",M[i][j]);
    }
}
int main()
{
    FILE *fin=fopen("date.in","r");
    int n;
    fscanf(fin,"%d",&n);
    int g[50],c[50],G;
    int cmax[50][50];
    printf("\n %d",n);
    for(int i=1;i<=n;i++)
        {fscanf(fin,"%d",&c[i]);
        }
    for(int i=1;i<=n;i++)
        {fscanf(fin,"%d",&g[i]);
        }
    fscanf(fin,"%d",&G);
    for(int i=0;i<=n;i++)
    {cmax[i][0]=0;
    }
    for(int i=0;i<=G;i++)
    {
        cmax[0][i]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=G;j++)
          {cmax[i][j] = cmax[i-1][j];
            if((g[i] <= j) && (cmax[i-1][j-g[i]] + c[i] > cmax[i-1][j]))
                cmax[i][j] = cmax[i-1][j-g[i]] + c[i];
          }

        }

    printf("\n");
    for(int i=0;i<=n;i++)
    {
        printf("\n");
        for(int j=0;j<=G;j++)
            printf("%d ",cmax[i][j]);
    }

    int i=n,j=G;
    while(cmax[i][j]!=0)
    {
        if(cmax[i-1][j]!=cmax[i][j]) {printf("\n%d",g[i]);  j=j-g[i]; i=i-1;}
        else {i=i-1;}
    }
       fclose(fin);
    return 0;
}
