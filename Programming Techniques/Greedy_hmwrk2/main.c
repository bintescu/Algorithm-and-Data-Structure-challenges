#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void functieGenerare(FILE *f,int a,int b,int a1,int b1,int n)
{
    int r,i;
    for(i=0;i<n;i++)
       { r=rand()*rand();
        r=a+r%(b-a+1);
        fprintf(f,"%d  ",r);
        r=rand()*rand();
        r=a1+r%(b1-a1+1);
        fprintf(f,"%d\n",r);
       }

}

typedef struct
{
    int minute;
    int secunde;
}Melodie;

int cmp(const void *a,const void *b)
{
    Melodie *va=(Melodie *)a;
    Melodie *vb=(Melodie *)b;
    return va->minute-vb->minute;
}
int main()
{  int n=10;
   /* FILE *f=fopen("date.in","w");
     srand(time(NULL));
    functieGenerare(f,1,9,1,59,n);
    fclose(f);*/
   printf("Cate secunde poate canta Sandel ?  (60s = 1 min) \n ");
   int s;
   scanf("%d",&s);
   Melodie *v=malloc(10*sizeof(Melodie));

   FILE *fi=fopen("date.in","r");
   int i;
   for(i=0;i<n;i++)
   {
       fscanf(fi,"%d%d",&v[i].minute,&v[i].secunde);
   }
   fclose(fi);

 // Sortam melodiile crescator dupa nr de minute
 qsort(v,n,sizeof(Melodie),cmp);
printf("\n\n");
   for(i=0;i<n;i++)
{
    printf(" %d  %d \n",v[i].minute,v[i].secunde);
}

// Transformam pentru fiecare melodiile timpul in secunde
// Apoi il scadem din timpul pe care Sandel il poate canta si de fiecare data cand Sandel mai ramane cu timp contorizam
printf("\n\n");
int c=0;
for(i=0;i<n;i++)
{
    if((s-(v[i].minute*60+v[i].secunde))>=0) {c++; s=s-(v[i].minute*60+v[i].secunde);}
   printf("%d\n",v[i].minute*60+v[i].secunde);
}
FILE *fout=fopen("date.out","w");

if(c!=n) fprintf(fout," Sandel poate canta %d  melodii ",c);
if(c==n) fprintf(fout," Sandel poate canta toate melodiile");

fclose(fout);
    return 0;
}
