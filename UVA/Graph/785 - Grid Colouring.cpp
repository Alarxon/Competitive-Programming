//Number 26
#include <bits/stdc++.h>

using namespace std;

int dr[] = {1,0,-1, 0};
int dc[] = {0,1, 0,-1};

char grafo[100][100];
char grafoAuxiliar[100][100];
int  grafoPuntos[100][100];
int Y;

void floodfill(int r, int c, char c2){
  if (r < 0 || r >= Y || c < 0 || c > 99){
    return;
  }
  if (grafo[r][c] == 'X'){
    return;
  }
  if(grafoPuntos[r][c] == 1){
    return;
  }

  grafo[r][c] = c2;

  grafoPuntos[r][c] = 1;

  for (int d = 0; d < 4; d++){
   floodfill(r + dr[d], c + dc[d], c2);
  }
}

string fin;

int main()
{
    int cont;

    while(1){
        Y=0;
        cont = 0;
        for(int j=0; j<100; j++){
            memcpy(&grafo[j], &grafoAuxiliar[j], sizeof(grafoAuxiliar[0]));
        }


        memset(grafoPuntos, 0, sizeof(grafoPuntos));
        string cadena;
        while(1){

            getline(cin, cadena);

            if(cadena[0] == '_'){
                break;
            }
            if(!cin){
                cont++;
                break;
            }

            for(int j=0; j<cadena.size(); j++){
                grafo[Y][j] = cadena[j];
             }

            Y++;
        }

        if(cont > 0){
            break;
        }

        for(int j=0; j<Y; j++){
            for(int k=0; grafo[j][k]; k++){
               if(grafo[j][k] != ' ' && grafo[j][k] != '_' && grafo[j][k] != 'X' && grafoPuntos[j][k] != 1){
                   floodfill(j, k, grafo[j][k]);
               }
            }
        }

        for(int j=0; j<Y; j++){
            for(int k=0; grafo[j][k]; k++){
                cout << grafo[j][k];
            }
            cout << "\n";
        }
        for(int j=0; j<cadena.size(); j++){
            cout << cadena[j];
        }
        cout << "\n";

    }


    return 0;
}

