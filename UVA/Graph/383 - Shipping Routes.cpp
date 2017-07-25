//Number 29
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > grafo;

int main()
{
   int casos;
   cin >> casos;

   cout<<"SHIPPING ROUTES OUTPUT"<<"\n";

   for(int i=0; i<casos; i++){
      cout<<"\n"<<"DATA SET  "<<i+1<<"\n"<<"\n";
      int nodos, conexiones, consultas;
      cin >> nodos >> conexiones >> consultas;

      grafo.assign(10000, vector<int>());
      int nodosverdaderos = 1;
      map<string,int> mapa;

      mapa.clear();

      for(int j=0; j<nodos; j++){
          string nodoCadena;
          cin >> nodoCadena;
          if(mapa[nodoCadena] == 0){
             mapa[nodoCadena] = nodosverdaderos++;
        }
      }

      nodosverdaderos--;

      for(int j=0; j<conexiones; j++){
         string nodoX, nodoY;
         cin >> nodoX >> nodoY;

         grafo[mapa[nodoX]].push_back(mapa[nodoY]);
         grafo[mapa[nodoY]].push_back(mapa[nodoX]);
      }

      for(int j=0; j<consultas; j++){
           int peso;
           string inicio, fin;
           cin >> peso >> inicio >> fin;

           vector<int> d;
           d.assign(10000, -1);

           d[mapa[inicio]] = 0;

           queue<int> q;

           if(mapa[inicio] != 0 && mapa[fin] != 0){
           q.push(mapa[inicio]);
           }else{
              d[mapa[fin]] = 0;
            }


           while(!q.empty()){
              int u = q.front(); q.pop();
              for (int k = 0; k < (int)grafo[u].size(); k++) {
                 int v = grafo[u][k];
                 if (d[v] == -1){
                   d[v] = d[u] + 1;
                   q.push(v);
                 }
              }
           }

             int total = peso*d[mapa[fin]]*100;
             if(total >= 0){
             cout<<"$"<< total <<"\n";
             }else{
               cout<<"NO SHIPMENT POSSIBLE"<<"\n";
             }

      }

   }
     cout<<"\n"<<"END OF OUTPUT"<<"\n";

    return 0;
}
