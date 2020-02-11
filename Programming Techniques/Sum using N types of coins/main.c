#include <stdio.h>
#include <stdlib.h>
int v[5]={5,1,7,3}, S=20, n=4, x[20];

int verif(int k)
{ int s=0;
    for(int i=1;i<=k;i++)
        s=s+x[i]*v[i-1];
    if(s<=S) return 1;
    else return 0;
}

int esol(int k)
{
    int s=0;
    for(int i=1;i<=k;i++)
        s=s+x[i]*v[i-1];
    if(s==S) return 1;
    else return 0;
}

void tipar(int k)
{ printf("\n");
    for(int i=1;i<=k;i++)
        printf("%d monede de %d\n",x[i],v[i-1]);
}
void bkt(int k)
{  int i;
    for(i=1;i<=n;i++)
    {
        x[k]=i;
        if(verif(k))
            if(esol(k)) tipar(k);
            else bkt(k+1);
    }
}
int main()
{

   bkt(1);
    return 0;
}
