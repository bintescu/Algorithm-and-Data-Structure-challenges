#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int i, j, n, c[101], g[101], G, cmax[101][101];

    ifstream fin("rucsac.txt");

    fin >> n;

    for (i = 1; i <= n; i++)
        fin >> g[i] >> c[i];

    fin >> G;

    fin.close();

    for(j = 0; j <= G; j++)
        cmax[0][j] = 0;

    for(i = 0; i <= n; i++)
        cmax[i][0] = 0;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= G; j++)
        {
            cmax[i][j] = cmax[i-1][j];

            if((g[i] <= j) && (cmax[i-1][j-g[i]] + c[i] > cmax[i-1][j]))
                cmax[i][j] = cmax[i-1][j-g[i]] + c[i];
        }

    cout << "Castig maxim: " << cmax[n][G] << endl;
    cout << "Obiectele selectate: " << endl;

    i = n, j = G;

    while(i >= 1)
    {
        if(cmax[i][j] != cmax[i-1][j])
        {
            cout << i << " ";
            j = j - g[i];
        }
        i--;
    }

    return 0;
}
