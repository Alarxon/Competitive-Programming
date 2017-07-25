//Number 3|
#include <bits/stdc++.h>

using namespace std;

vector<string> cadenas;
vector<vector<int> > grafo;


int main()
{
    int casos;
    cin >> casos;
    for(int i=0; i<casos; i++){
       cadenas.clear();
       grafo.assign(1000, vector<int>());
       string nombres;
       map<string,int> mapa;
       int nodos = 1;
       while(cin >> nombres && nombres[0] != '*'){
            if(mapa[nombres] == 0){
                mapa[nombres] = nodos++;
            }
            cadenas.push_back(nombres);
       }
       nodos--;
       for(int j=0; j<cadenas.size(); j++){
          for(int k=0; k<cadenas.size(); k++){
              string nombreJ, nombreK;
              nombreJ = cadenas[j];
              nombreK = cadenas[k];

              int cont = 0;
              if(nombreJ.size() == nombreK.size()){
                 for(int l=0; l<nombreJ.size(); l++){
                     if(nombreJ[l] == nombreK[l]){
                        cont++;
                     }
                 }
              }
              if(nombreJ.size()-1 == cont){
                  grafo[mapa[nombreJ]].push_back(mapa[nombreK]);
              }
          }
       }
       cin.ignore();
       int espacio = 0;
       string inicio,fin;

       while(1){
         string pares;
         getline(cin, pares);
         if(pares == ""){
            break;
         }
         espacio = pares.find(' ');
         inicio = pares.substr(0,espacio);
         fin  = pares.substr(espacio+1,pares.size());


          vector<int> d;
          d.assign(1000, -1);

          d[mapa[inicio]] = 0;

          queue<int> q;
          q.push(mapa[inicio]);

          while (!q.empty()){
            int u = q.front(); q.pop();
            for (int j = 0; j < (int)grafo[u].size(); j++) {
               int v = grafo[u][j];
               if (d[v] == -1){
                 d[v] = d[u] + 1;
                 q.push(v);
               }
            }
          }
          cout << inicio << " " << fin << " " << d[mapa[fin]] << "\n";

       }
       if(i < casos-1){
        cout << "\n";
       }

    }
    
    return 0;
}
