//Number 32
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > grafo;

int main()
{
    int n;

    while(cin >> n && n != EOF){
         grafo.assign(1000, vector<int>());
         cin.ignore();
         for(int i=0; i<n; i++){
              string cadena;
              string nodoInicial;
              getline(cin, cadena);
              cadena = cadena + ',';
              int nodo = cadena.find('-');
              nodoInicial = cadena.substr(0, nodo);
              int Inicial = atoi(nodoInicial.c_str());

              string nodoFinal = cadena.substr(nodo+1);

              while(1){
                 int fin = nodoFinal.find(',');

                 string END = nodoFinal.substr(0, fin);
                 int num = atoi(END.c_str());
                 if(num > 0){
                 grafo[Inicial].push_back(num);
                 }
                 nodoFinal = nodoFinal.substr(fin+1);
                 if(nodoFinal.size() <= 0){
                    break;
                 }
              }
         }
         int busquedas;
         cin >> busquedas;
         cout << "-----\n";
         for(int i=0; i<busquedas; i++){
            int inicio, meta;
            cin >> inicio >> meta;

            vector<int> d(1000, -1);
            int numeros[1000];
            memset(numeros, 0, sizeof(numeros));
            d[inicio] = 0;
            queue<int> q;
            q.push(inicio);

            while (!q.empty()) {
              int u = q.front(); q.pop();
              for (int j = 0; j < (int)grafo[u].size(); j++) {
                    int v = grafo[u][j];
                    if (d[v] == -1){
                       d[v] = d[u] +1;

                       numeros[v] = u;

                       q.push(v);
                    }
               }
            }

           if(d[meta] != -1){
           vector<int> resultado;
           resultado.clear();
           resultado.push_back(meta);
           int t = meta;
           while(numeros[t] != t){
               t = numeros[t];
               resultado.push_back(t);
           }
           reverse(resultado.begin(), resultado.end());
           for(int j=1; j<resultado.size(); j++){
              cout << resultado[j];
              if(j < resultado.size()-1){
                cout << " ";
              }
           }
           cout << "\n";
           }else{
             cout << "connection impossible\n";
           }
         }

    }


    return 0;
}
