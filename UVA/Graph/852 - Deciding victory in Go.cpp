//Number 27
#include <bits/stdc++.h>

using namespace std;

int dr[] = {1,0,-1, 0};
int dc[] = {0,1, 0,-1};

char grafo[9][9];
int negro;
int blanco;

int floodfill(int r, int c, char c1, char c2) {
  if (r < 0 || r >= 9 || c < 0 || c >= 9){
    return 0;
  }
  if (grafo[r][c] == 'X'){
     negro++;
     return 0;
  }
  if(grafo[r][c] == 'O'){
    blanco++;
    return 0;
  }
  if(grafo[r][c] == '#'){
    return 0;
  }
  int ans = 1;
  grafo[r][c] = c2;
  for (int d = 0; d < 4; d++){
    ans += floodfill(r + dr[d], c + dc[d], c1, c2);
  }
  return ans;
}

int floodfillColores(int r, int c, char c1, char c2) {
  if (r < 0 || r >= 9 || c < 0 || c >= 9){
    return 0;
  }
  if (grafo[r][c] != c1){
    return 0;
  }
  int ans = 1;
  grafo[r][c] = c2;
  for (int d = 0; d < 4; d++){
    ans += floodfillColores(r + dr[d], c + dc[d], c1, c2);
  }
  return ans;
}



int main()
{
    int casos;
    cin >> casos;

    for(int i=0; i<casos; i++){

        for(int j=0; j<9; j++){
            for(int k=0; k<9; k++){
                cin >> grafo[j][k];
            }
        }

        int Blancos=0;
        int Negros=0;

        for(int j=0; j<9; j++){
            for(int k=0; k<9; k++){
                if(grafo[j][k] == '.'){
                    blanco = 0;
                    negro = 0;
                    int resultado = floodfill(j,k, '.', '#');
                    if(blanco > 0 && negro == 0){
                        Blancos = Blancos + resultado;
                    }
                    if(negro > 0 && blanco == 0){
                        Negros = Negros + resultado;
                    }
                }
            }
        }

        for(int j=0; j<9; j++){
            for(int k=0; k<9; k++){
                if(grafo[j][k] == 'X'){
                    int resultado = floodfillColores(j, k, 'X', '#');
                    Negros = Negros + resultado;
                }
                if(grafo[j][k] == 'O'){
                    int resultado = floodfillColores(j, k, 'O', '#');
                    Blancos = Blancos + resultado;
                }
            }
        }

        cout << "Black " << Negros << " White " << Blancos << "\n";

    }

    return 0;
}
