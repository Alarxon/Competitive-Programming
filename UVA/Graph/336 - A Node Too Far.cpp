//Number28
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > grafo;
int main()
{
    int nodos;
    int caso = 1;
    while(cin >> nodos){
        if(nodos == 0){
            break;
        }

        grafo.assign(10000, vector<int>());
        int nodosverdaderos = 1;
        map<int,int> mapa;

        for(int i=0; i<nodos; i++){
            int m, n;
            cin >> m >> n;
            if(mapa[m] == 0){
                mapa[m] = nodosverdaderos++;
            }
            if(mapa[n] == 0){
                mapa[n] = nodosverdaderos++;
            }

            grafo[mapa[m]].push_back(mapa[n]);
            grafo[mapa[n]].push_back(mapa[m]);

        }
        nodosverdaderos--;

        int inicio, distancia;

        while(cin >> inicio >> distancia){
            if(inicio == 0 && distancia == 0){
                break;
            }
            vector<int> d;
            d.assign(10000, -1);


            d[mapa[inicio]] = 0;

            queue<int> q;

            if(mapa[inicio] != 0){
            q.push(mapa[inicio]);
            }

            int contNodos=0;

            while(!q.empty()){
                int u = q.front(); q.pop();

                for (int j = 0; j < (int)grafo[u].size(); j++) {
                   int v = grafo[u][j];
                   if (d[v] == -1){
                       d[v] = d[u] + 1;
                       q.push(v);
                   }
                }

            }

            for(int j=1; j<=nodosverdaderos; j++){
                if(d[j] <= distancia && d[j] >= 0){
                   contNodos++;
                }
            }


           int total = nodosverdaderos - contNodos;

           printf ("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", caso, total, inicio, distancia);
           caso++;
        }

    }


    return 0;
}
