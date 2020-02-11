#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void functieGenerare(FILE *f,int a,int b,int a1,int b1,int n)
{
    int r,i;
    for(i=0;i<n;i++)
       { fprintf(f,"%d ",i+1);
        r=rand()*rand();
        r=a+r%(b-a+1);
        fprintf(f,"%d  ",r);
        r=rand()*rand();
        r=a1+r%(b1-a1+1);
        fprintf(f,"%d\n",r);
       }

}
typedef struct
{   int cod;
    int nrZile;
    int Punctaj;
} Proiect;


void sortareDupaPunctaj(Proiect *v,int i,int j)
{
    int k=i,aux,l=0;
    for(k=i;k<=j;k++)
    for(l=k+1;l<=j;l++)
      {
          if(v[k].Punctaj<v[l].Punctaj) {aux=v[k].Punctaj;  v[k].Punctaj=v[l].Punctaj; v[l].Punctaj=aux; }
      }



}

int cmp(const void *a,const void *b)
{
 Proiect *va=(Proiect *)a;
 Proiect *vb=(Proiect *)b;
 return va->nrZile-vb->nrZile;
}
int main()
{
              int n=8; /// Numarul de proiecte din fisier (nu lungimea solutiei)!
                       /// E folosit in generarea randoom , insa pentru a nu genera de fiecare data
                      /// si sa fie folosit in program, l-am lasat inafara comentariului

  FILE *f=fopen("date.in","w");
    srand(time(NULL));
   functieGenerare(f,1,11,2,10,n);
    fclose(f);
   FILE *fo=fopen("date.in","r");
   Proiect *v=malloc(n*sizeof(Proiect));
   int i=0;
   for(i=0;i<n;i++)
     {
         fscanf(fo,"%d%d%d",&v[i].cod,&v[i].nrZile,&v[i].Punctaj);
     }
   fclose(fo);

   qsort(v,n,sizeof(Proiect),cmp);

    printf("\n");
    for(i=0;i<n;i++)
     printf("%d %d %d%\n",v[i].cod,v[i].nrZile,v[i].Punctaj);

 // Parcurgem structura sortata in functie de numarul de zile si in zonele in care nrZile sunt egale
 // o sortam crescator dupa punctaj.
    i=0;
    int j=i;
     while(i<n)
     {
         while(v[i].nrZile==v[j].nrZile) {j++;}
          if(j>i+1) sortareDupaPunctaj(v,i,j-1);
         i++;

     }


 // Creem un vector Plan in care salvam punctajele proiectelor realizabile
   int *Plan=calloc(5,sizeof(int));
     int contor=0;
     for(i=0;i<n;i++)
     {
       if(contor<v[i].nrZile && contor<5) {Plan[contor]=v[i].cod; contor++;}

     }


// Afisam solutia
  FILE *fout=fopen("date.out","w");

    for(i=0;i<5;i++)
   {
    fprintf(fout," %d",Plan[i]);
   }
   fclose(fout);
    free(Plan);
    free(v);
    return 0;
}
