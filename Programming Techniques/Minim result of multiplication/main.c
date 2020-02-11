#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main()
{  int i=0,n,maxNegative=INT_MAX, nrNegative=0 , nrZero=0,minNegative=INT_MIN,p=1;
    FILE *f=fopen("date.in","r");
    fscanf(f,"%d",&n);
    int *v=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        {fscanf(f,"%d",&v[i]);
         if(v[i]<0)
            {nrNegative++;
            if(v[i]<maxNegative) maxNegative=v[i];
            if(v[i]>minNegative) minNegative=v[i];
         }
         if(v[i]==0) nrZero++;
        }
 if(nrZero!=0 && nrNegative==0)
 {
     printf("\n Solutia este tot vectorul cu produsul 0 \n");

     for(i=0;i<n;i++)
     {printf("%d ",v[i]);
     }
 }



 if(nrZero!=0 && nrNegative!=0)
 { if(nrNegative%2==0)
     {for(i=0;i<n;i++)
     {
         if(v[i]!=minNegative && v[i]!=0) { printf("%d ",v[i]); p=p*v[i];}
     }
  printf("\n %d",p);
 }

  if(nrNegative%2==1)
  {
      for(i=0;i<n;i++)
      if(v[i]!=0) {printf("%d ",v[i]); p=p*v[i];}
      printf("\n %d",p);
  }
 }



 if(nrZero==0 && nrNegative!=0)
 {
     if(nrNegative%2==0)
     {for(i=0;i<n;i++)
     {
         if(v[i]!=minNegative) { printf("%d ",v[i]); p=p*v[i];}

     }
      printf("\n %d  ",p);
     }
  if(nrNegative%2==1)
  {
      for(i=0;i<n;i++)
     {printf("%d ",v[i]); p=p*v[i];}
      printf("\n %d",p);
  }
 }

 if(nrZero==0 && nrNegative==0)
 {
     printf("\n Solutia este minimul din vector");
     int min=INT_MAX;
     for(i=0;i<n;i++)
     {if(v[i]<min)
         min=v[i];
     }
     printf("\n %d",min);
 }
    fclose(f);
    free(v);



    return 0;

}
