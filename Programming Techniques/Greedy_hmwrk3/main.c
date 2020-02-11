#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void functieGenerare(FILE *f,int a,int b,int a1,int b1,int a2,int b2,int n)
{
    int r,i;
    for(i=0;i<n;i++)
       {
        fprintf(f,"%d ",i+1);
        r=rand()*rand();
        r=a+r%(b-a+1);
        fprintf(f,"%d ",r);
        r=rand()*rand();
        r=a1+r%(b1-a1+1);
        fprintf(f,"%d ",r);
        r=rand()*rand();
        r=a2+r%(b2-a2+1);
        fprintf(f,"%d\n",r);
       }

}

typedef struct
{
    int cod;
    float timp;
    int pret;
    int portii;
    float valoareMedie;
} FelDeMancare;

int cmp(const void *a, const void *b)
{
    FelDeMancare va=*(FelDeMancare *)a;
    FelDeMancare vb=*(FelDeMancare *)b;
    return vb.valoareMedie-va.valoareMedie;
}
int main()
{  // Ordonam toate felurile de mancare dupa valoarea medie a unei portii
    // = Cati bani castiga pe minut gatind acea portie (Luand in calcul timpul de asteptare total)
   int n=10,i,j;
  FILE *f=fopen("date.in","w");
  srand(time(NULL));
  functieGenerare(f,5,50,10,100,1,10,n);
  fclose(f);

  FILE *fin=fopen("date.in","r");
  FelDeMancare *v=malloc(n*sizeof(FelDeMancare));
  for(i=0;i<n;i++)
  {
      fscanf(fin,"%d%f%d%d",&v[i].cod,&v[i].timp,&v[i].pret,&v[i].portii);
  }
  fclose(fin);



  for(i=0;i<n;i++)
  {   float aux=v[i].timp;
      for(j=1;j<=v[i].portii;j++)
  {
      v[i].timp=v[i].timp+pow(0.5,j)*aux;
  }
   v[i].valoareMedie=(float)v[i].pret/v[i].timp;
      printf("%d %f %d %d %f\n",v[i].cod,v[i].timp,v[i].pret,v[i].portii,v[i].valoareMedie);

  }
 printf("\n\n");


  qsort(v,n,sizeof(FelDeMancare),cmp);


  for(i=0;i<n;i++)
  {
       printf("%d %f %d %d %f\n",v[i].cod,v[i].timp,v[i].pret,v[i].portii,v[i].valoareMedie);
  }

FILE *fo=fopen("date.out","w");
for(i=0;i<n;i++)
{
    fprintf(fo,"%d ",v[i].cod);
}
  fclose(fo);

  free(v);
    return 0;
}
