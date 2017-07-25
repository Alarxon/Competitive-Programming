//Number 17
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > grafo;
vector<int> dfs_num;

void dfs(int u){
   dfs_num[u] = 1;
   for(int j=0; j<(int)grafo[u].size(); j++){
      int v = grafo[u][j];
      if(dfs_num[v] == 0){
         dfs(v);
      }
   }

}

int main()
{
    int casos;
    cin >> casos;

    for(int i=0; i<casos; i++){

        int cont = 0;

        char letra;
        cin >> letra;
        cin.ignore();
        int nodos = letra-64;
        grafo.assign(nodos, vector<int>());

        while(1){
            string cadena;
            getline(cin, cadena);

            if(cadena == ""){
                 break;
            }

            int nodo1 = cadena[0] - 65;
            int nodo2 = cadena[1] - 65;
            grafo[nodo1].push_back(nodo2);
            grafo[nodo2].push_back(nodo1);

        }
        dfs_num.assign(nodos, 0);

        for(int j=0; j<nodos; j++){
            if(dfs_num[j] == 0){
                cont++;
                dfs(j);
            }
        }
        cout << cont << "\n";

        if(i < casos-1){
            cout << "\n";
        }

    }


    return 0;
}
