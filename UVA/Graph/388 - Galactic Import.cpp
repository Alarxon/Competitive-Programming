//Number 30
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    while(cin >> n && n != EOF){
        double maximo = 0.0;
        char maxima;
        for(int i=0; i<n; i++){
            char letra;
            double valor;
            string cadena;
            cin >> letra >> valor >> cadena;
            if(valor > maximo){
                maximo = valor;
                maxima = letra;
            }
        }
        cout << "Import from " << maxima << "\n";
    }

    return 0;
}
