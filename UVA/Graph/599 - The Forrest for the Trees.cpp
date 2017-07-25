//Number 1


#include <bits/stdc++.h>
using namespace std;

vector <vector<int> >grafo;
bool noditos[26];
vector <int> dfs_num;


void dfs(int num){
    dfs_num[num] = 1;
    for (int k = 0; k < (int)grafo[num].size(); k++) {
        int v= grafo[num][k];
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
        string cadena;
      grafo.assign(26, vector<int>());
      memset(noditos, 0, sizeof(noditos));
      while(cin >> cadena){
          if(cadena[0] == '*'){
             break;
          }
          int a= cadena[1]-65;
          int b= cadena[3]-65;
          grafo[a].push_back(b);
          grafo[b].push_back(a);
      }
      string nodos;
      cin >> nodos;
     for(int j=0; j<nodos.size(); j++){
          if(nodos[j] != ','){
              int c= nodos[j]-65;
              noditos[c] = 1;
          }
     }
     int bellotas=0;
     for(int j=0; j<26; j++){
         if(noditos[j] == 1 && grafo[j].size() == 0){
             bellotas++;
         }
     }
     int arboles=0;
     dfs_num.assign(26, 0);
     for(int j=0; j<26; j++){
         if(noditos[j] == 1 && grafo[j].size() > 0){
                if(dfs_num[j] == 0){
                    arboles++;
                    dfs(j);
                }
         }
     }
      printf("There are %d tree(s) and %d acorn(s).\n", arboles, bellotas);


    }
    return 0;
}

