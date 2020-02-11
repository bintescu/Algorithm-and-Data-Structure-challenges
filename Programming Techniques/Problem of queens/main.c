#include <stdio.h>
#include <stdlib.h>
int n,x[20]={0};

int evalid(int k)
{ int i=1;
    for(i=1;i<k;i++)
    {
        if(x[i]==x[k]) return 0;
        if( abs(k-i)== abs(x[k]-x[i])) return 0;

    }
  return 1;
}

int esol(int k)
{
    if(k==n) return 1;
    return 0;
}

void tipar()
{ printf("\n");
    for(int i=1;i<=n;i++)
        printf("%d ",x[i]);
}

void bkt(int k)
{ int i;
    for(i=1;i<=n;i++)
    {
        x[k]=i;
        if(evalid(k))
            if(esol(k)) tipar();
          else bkt(k+1);
    }
}
int main()
{
  n=4;
  bkt(1);

    return 0;
}
