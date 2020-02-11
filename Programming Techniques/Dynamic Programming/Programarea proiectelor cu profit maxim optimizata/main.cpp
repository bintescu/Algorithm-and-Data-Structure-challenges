#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Proiect
{
    char nume_proiect[50];
    int ziua_initiala , ziua_finala , bonus;
};

Proiect *p;
int *bm;

bool cmpProiecte(Proiect p1, Proiect p2)
{
    return (p1.ziua_finala < p2.ziua_finala);
}

int cautareBinara(int crt)
{
    int st = 1, dr = crt - 1;

    while (st <= dr)
    {
        int m = (st + dr) / 2;
        if (p[m].ziua_finala <= p[crt].ziua_initiala)
        {
            if (p[m + 1].ziua_finala <= p[crt].ziua_initiala)
                st = m + 1;
            else
                return m;
        }
        else
            dr = m - 1;
    }

    return 0;
}

void scriereSolutie(ofstream &fout , int i)
{
    if(i != 0)
    {
        int ult = cautareBinara(i);

        if(p[i].bonus + bm[ult] > bm[i-1])
        {
            scriereSolutie(fout , ult);
            fout << p[i].nume_proiect << " " << p[i].ziua_initiala << " " << p[i].ziua_finala << " " << p[i].bonus << endl;
        }
        else
            scriereSolutie(fout , i-1);
    }
}

int main()
{
    int i, n , ult;

    ifstream fin("proiecte.in");
    fin >> n;

    p = new Proiect[n+1];

    for(i = 1; i <= n; i++)
        fin >> p[i].nume_proiect >> p[i].ziua_initiala >> p[i].ziua_finala >> p[i].bonus;

    fin.close();

    sort(p+1 , p+n+1 , cmpProiecte);

    bm = new int[n+1];

    bm[0] = 0;

    for (i = 1; i <= n; i++)
    {
        ult = cautareBinara(i);
        bm[i] = p[i].bonus+bm[ult] > bm[i-1] ? p[i].bonus+bm[ult] : bm[i-1];
    }

    ofstream fout("proiecte.out");

    scriereSolutie(fout , n);

    fout << endl << "Bonusul echipei: " << bm[n];

    fout.close();

    delete[] p;
    delete[] bm;

    return 0;
}
