//Number 7
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > grafo;
int light[99999];
int cont;
int ultimo;

void dfs(int mino, int tadeo, int lamp){
      cont++;
      for (int j = 0; j < (int)grafo[mino].size(); j++){
           int v = grafo[mino][j];

            if(cont == lamp){
                 light[mino] = 1;
            }

           if(v != tadeo && light[v] != 1){
               if(cont == lamp){
                 cont = 0;
                 char nodo = mino + 65;
                 cout << nodo << " ";
              }
               return dfs(v, mino, lamp);
           }
      }
     cout << "/" << char(mino + 65) << "\n";

}

int main()
{
    string cadena;
    while(cin >> cadena && cadena[0] != '#'){
       grafo.assign(1000, vector<int>());
       char minotauro;
       char tadeo;
       int lamparas;
       cin >> minotauro >> tadeo >> lamparas;
       for(int i=0; i<(int)cadena.size(); i++){
           if(cadena[i] == ':' || cadena[i] == '.'){
              int nodoPrincipal = cadena[i-1] - 65;
              for(int j=i+1; j<(int)cadena.size(); j++){
                  if(cadena[j] == ';' || cadena[j] == '.'){
                    break;
                  }else{
                    int nodoComunidado = cadena[j] - 65;
                    grafo[nodoPrincipal].push_back(nodoComunidado);
                  }
              }
           }
       }

       int minotaurus = minotauro - 65;
       int tadeus = tadeo - 65;
       cont = 0;
       memset(light, 0, sizeof(light));
       dfs(minotaurus, tadeus, lamparas);


    }


    return 0;
}
