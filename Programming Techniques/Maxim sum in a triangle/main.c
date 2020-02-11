#include <stdio.h>
#include <stdlib.h>
int maxim(int a,int b)
{
    if(a>b) return a;
    return b;
}
void afisare(int n,int M[][n])
{
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("\n");
        for(int j=0;j<=i;i++)
            printf("%d ",M[i][j]);
    }
}
int main()
{
   int M[5][5]={{5,0,0,0},{-17,10,0,0},{9,-6,12,0},{-8,2,21,6}};
printf("\n");
    for(int i=0;i<4;i++)
    {
        printf("\n");
        for(int j=0;j<=i;j++)
            printf("%d ",M[i][j]);
    }
   int Maux[10][10];
   for(int i=0;i<4;i++)
    Maux[3][i]=M[3][i];
   for(int i=2;i>=0;i--)
   {
       for(int j=0;j<=i;j++)
       Maux[i][j]=M[i][j]+maxim(Maux[i+1][j],Maux[i+1][j+1]);

   }
printf("\n");
    for(int i=0;i<4;i++)
    {
        printf("\n");
        for(int j=0;j<=i;j++)
            printf("%d ",Maux[i][j]);
    }
    printf("\n");
    int i=0,j=0;
    while(i<3)
    {
      if(Maux[i+1][j]==maxim(Maux[i+1][j],Maux[i+1][j+1])) {printf("%d \n",Maux[i][j]-Maux[i+1][j]); i++;}
      if(Maux[i+1][j+1]==maxim(Maux[i+1][j],Maux[i+1][j+1])) {printf("%d \n",Maux[i][j]-Maux[i+1][j+1]); i++;j++;}


    }
    printf("%d",Maux[i][j]);
    return 0;
}
