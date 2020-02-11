#include <stdio.h>
#include <stdlib.h>
int x[100],n=10;

int evalid(int k)
{ int s=0;

    for(int i=1;i<=k;i++)
        s=s+x[i];
    if(s<=n) return 1;
    else return 0;
}

int esolutie(int k)
{ int s=0;
    for(int i=1;i<=k;i++)
        s=s+x[i];
    if(s==n) return 1;
    else return 0;
}

void tipar(int k)
{ printf("\n");
    for(int i=1;i<=k;i++)
    {
        printf("%d ",x[i]);
    }
}
void bkt(int k)
{
    int i;
    for(i=1;i<=n;i++)
    {
        x[k]=i;
        if(evalid(k))
            if(esolutie(k)) tipar(k);
           else bkt(k+1);
    }
}
int main()
{
    bkt(1);
    return 0;
}
