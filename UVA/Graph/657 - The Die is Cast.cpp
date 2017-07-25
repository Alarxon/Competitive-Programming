//Number 20
#include <bits/stdc++.h>

using namespace std;

int dr[] = {1,0,-1, 0};
int dc[] = {0,1, 0,-1};

char grafo[100][100];
int x, y;
int cont;

vector<int> resultados;

void floodfillX(int r, int c, char c1, char c2){
  if (r < 0 || r >= y || c < 0 || c >= x ){
     return;
  }
  if(grafo[r][c] != c1){
    return;
  }
  grafo[r][c] = c2;
  for(int d = 0; d < 4; d++){
      floodfillX(r + dr[d], c + dc[d], c1, c2);
    }
}


void floodfill(int r, int c, char c1, char c2) {
  if (r < 0 || r >= y || c < 0 || c >= x || grafo[r][c] == '.'){
     return;
  }
  if(grafo[r][c] == 'X'){
     floodfillX(r, c, 'X', '*');
     cont++;
  }

  if (grafo[r][c] != c1){
    return;
  }
  grafo[r][c] = c2;
  for (int d = 0; d < 4; d++){
      floodfill(r + dr[d], c + dc[d], c1, c2);
  }

}

int main()
{
    int caso = 0;
    while(cin >> x >> y && x != 0 && y != 0){
        memset(grafo, 0, sizeof(grafo));

        for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
                cin >> grafo[i][j];
            }
        }

        resultados.clear();
        cont = 0;

        int checador = 0;

        for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
                if(grafo[i][j] != '.'){
                   cont = 0;
                   checador++;
                   floodfill(i, j, '*', '.');
                   if(checador == 1){
                    cout << "\n";
                   for(int k=0; k<y; k++){
                    for(int l=0; l<x; l++){
                        cout << grafo[k][l];
                    }
                    cout << "\n";
                   }
                   }
                   if(cont != 0){
                       resultados.push_back(cont);
                   }
                }
            }
        }
        caso++;

        sort(resultados.begin(), resultados.end());

        cout << "Throw " << caso << "\n";
        for(int i=0; i<(int)resultados.size(); i++){
            cout << resultados[i];
            if(i < (int)resultados.size()-1){
                cout << " ";
            }
        }
        cout << "\n\n";
    }


    return 0;
}
