//Number 8
#include <bits/stdc++.h>

using namespace std;


vector<vector<int> > grafo;
vector<int> dfs_num;
int contador;

void dfs(int u){

    for (int j = 0; j < (int)grafo[u].size(); j++){
        int v = grafo[u][j];
        if(dfs_num[v] == 0){
           dfs_num[v] = 1;
           contador++;
           dfs(v);
        }
    }
}

int main()
{

    int nodos;
    while(cin >> nodos && nodos != 0){
       grafo.assign(110, vector<int>());
       int num;
       int vertice;
       while(cin >> num){
          if(num == 0){
            break;
          }
          while(1){
              cin >> vertice;
              if(vertice == 0){
                break;
              }
              grafo[num-1].push_back(vertice-1);
          }
       }
       int Numvertex;
       cin >> Numvertex;

       for(int i=0; i<Numvertex; i++){
         dfs_num.assign(nodos, 0);
         int vertex;
         cin >> vertex;
         contador = 0;
         dfs(vertex-1);
         int total = nodos-contador;
         cout << total;
         for(int j=0; j<(int)dfs_num.size(); j++){
             if(dfs_num[j] == 0){
                cout << " " << j+1;
             }
         }
         cout << "\n";
       }
    }


    return 0;
}
