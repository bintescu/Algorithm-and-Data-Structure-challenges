#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Problema nr 2
int cmmdc(int a,int b)
{
    if(a==b) return a;
    else if(a>b) return cmmdc(a-b,b);
         else return cmmdc(a,b-a);
}
//Problema nr 3

void numarCaractere(char *sir,int n,int *s)
{
    if(n==-1) return 0;
     if(sir[n]>='a' && sir[n]<='z') {(*s)++ ;  return numarCaractere(sir,n-1,s);}
        else return numarCaractere(sir,n-1,s);
}

//Problema nr 4
int suma(int n,int *v)
{
    if(n==0) return 0;
    if(v[n]>0) return (v[n]+suma(n-1,v));
         else  return suma(n-1,v);
}
//Problema 5

int ValMax(int *v,int i,int j)
{   if(i==j) return v[i];
    else {int mij=(i+j)/2;
    int max1=ValMax(v,0,mij);
    int max2=ValMax(v,mij+1,j);
    if(max1>max2) return max1;
    else return max2;
    }}

int main()
{ //Apelare pb1
    int a,b;
printf("\n Introdu numerele pentru care vrem sa calculam cmmdc .. ");
scanf("%d%d",&a,&b);
printf("\n Cmmdc(%d,%d)=%d",a,b,cmmdc(a,b));


//Apelare pb2
int n,v[20],i;
printf("\n Introdu numarul de elemente ale vectorului .. ");
scanf("%d",&n);
printf("\n Introdu elementele pentru care vrem sa calculam suma celor pozitive .. ");
for(i=0;i<n;i++)
    scanf("%d",&v[i]);
printf("\n %d",suma(n-1,v));


//Apelare pb3
  int s=0;
  char sir[20]="MezoEndriMoLOogie"; //12 litere mici
  int L=strlen(sir)-1;
  numarCaractere(sir,L,&s);
  printf("\n\n%d",s);

//Apelare pb4
  printf("\n\n %d",ValMax(v,0,n));
    return 0;
}
