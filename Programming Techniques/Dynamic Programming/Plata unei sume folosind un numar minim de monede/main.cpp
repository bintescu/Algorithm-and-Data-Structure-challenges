#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    int n, i, j, s;
    int *m, *w, *p;

    ifstream fin("monede.txt");

    fin >> n;
    m = new int[n];

    for(i = 0; i < n; i++)
        fin >> m[i];

    fin >> s;

    fin.close();

    w = new int[s+1];
    p = new int[s+1];

    for(i = 0; i <= s; i++)
    {
        w[i] = s+1;
        p[i] = -1;
    }

    w[0]=0;
    for(i = 1; i <= s; i++)
        for(j = 0; j < n; j++)
            if(i >= m[j])
                if(1 + w[i-m[j]] < w[i])
                {
                    w[i] = 1 + w[i-m[j]];
                    p[i] = m[j];
                }

    if(w[s] == s+1)
        cout << "Suma " << s << " nu poate fi platita folosind monedele date!" << endl;
    else
    {
        cout << "Numarul minim de monede necesare pentru a plati suma " << s << " este " << w[s] << endl;
        cout << "O modalitate de plata: ";
        for(i = s; p[i] != -1; i = i - p[i])
            cout << p[i] << " ";
    }

    return 0;
}
