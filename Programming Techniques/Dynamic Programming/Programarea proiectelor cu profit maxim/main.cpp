#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Proiect
{
    char nume_proiect[50];
    int ziua_initiala , ziua_finala , bonus;
};

bool cmpProiecte(Proiect p1, Proiect p2)
{
    return (p1.ziua_finala < p2.ziua_finala);
}

int main()
{
    int i, j, n;
    Proiect *p;

    ifstream fin("proiecte.in");
    fin >> n;

    p = new Proiect[n+1];

    for(i = 1; i <= n; i++)
        fin >> p[i].nume_proiect >> p[i].ziua_initiala >> p[i].ziua_finala >> p[i].bonus;

    fin.close();

    sort(p + 1 , p + n + 1 , cmpProiecte);

    int *bm = new int[n+1];
    int *ult = new int[n+1];

    bm[0] = 0;
    ult[0] = 0;

    for (i = 1; i <= n; i++)
    {
        ult[i] = 0;

        for (j = i-1; j >= 1; j--)
            if (p[j].ziua_finala <= p[i].ziua_initiala)
            {
                ult[i] = j;
                break;
            }

        if(p[i].bonus + bm[ult[i]] > bm[i-1])
            bm[i] = p[i].bonus + bm[ult[i]];
        else
            bm[i] = bm[i-1];
    }

    ofstream fout("proiecte.out");

    i = n;
    while(i >= 1)
        if(bm[i] != bm[i-1])
        {
            fout << p[i].nume_proiect << " " << p[i].ziua_initiala << " " << p[i].ziua_finala << " " << p[i].bonus << endl;
            i = ult[i];
        }
        else
            i--;

    fout << endl;

    fout << "Bonusul echipei: " << bm[n];

    fout.close();

    return 0;
}
