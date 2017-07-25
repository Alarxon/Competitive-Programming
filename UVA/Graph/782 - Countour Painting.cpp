//Number 24
#include <bits/stdc++.h>

using namespace std;

int dr[] = {1,0,-1, 0};
int dc[] = {0,1, 0,-1};

char grafo[100][100];
char grafoAuxiliar[100][100];
char grafoRespuesta[100][100];
int  grafoPuntos[100][100];
int Y;
char signo;

int checador(int r, int c){
    int respuesta = 0;
    for(int i=0; i<4; i++){
        int R = r + dr[i];
        int C = c + dc[i];
        if(grafo[R][C] == signo){
            respuesta++;
        }
    }
    return respuesta;
}


void floodfill(int r, int c, char c1, char c2){
  if (r < 0 || r >= Y || c < 0 || c > 99){
    return;
  }
  if (grafo[r][c] != c1){
    return;
  }
  if(grafoPuntos[r][c] == 1){
    return;
  }

  if(checador(r, c) > 0){
  grafo[r][c] = c2;
  }
  grafoPuntos[r][c] = 1;

  for (int d = 0; d < 4; d++){
   floodfill(r + dr[d], c + dc[d], c1, c2);
  }
}

string fin;

int main()
{
    int casos;
    cin >> casos;
    cin.ignore();

    for(int i=0; i<casos; i++){
        Y=0;
        for(int j=0; j<100; j++){
            memcpy(&grafo[j], &grafoAuxiliar[j], sizeof(grafoAuxiliar[0]));
        }
        for(int j=0; j<100; j++){
            memcpy(&grafoRespuesta[j], &grafoAuxiliar[j], sizeof(grafoAuxiliar[0]));
        }


        memset(grafoPuntos, 0, sizeof(grafoPuntos));
        string cadena;
        while(1){
            getline(cin, cadena);
            if(cadena[0] == '_'){
                break;
            }

            if(cadena == ""){
                for(int j=0; j<99; j++){
                    grafo[Y][j] = ' ';
                }
            }else{

            for(int j=0; j<cadena.size(); j++){
                grafo[Y][j] = cadena[j];

                if(cadena[j] != ' ' && cadena[j] != '*' && cadena[j] != '#' && cadena[j] != '_'){
                  signo = cadena[j];
                }
             }
             for(int j=cadena.size(); j<99; j++){
                grafo[Y][j] = ' ';
             }
            }
            Y++;
        }
        for(int j=0; j<Y; j++){
            for(int k=0; grafo[j][k]; k++){
               if(grafo[j][k] == '*'){
                   grafo[j][k] = ' ';
                   floodfill(j, k, ' ', '#');
               }
            }
        }

        for(int j=0; j<Y; j++){
            int k = strlen(grafo[j])-1;
            int cont = 0;
            for(int l=k; l>=0; l--){
                if(grafo[j][l] != ' '){
                    cont = 1;
                }

                if(cont == 1){
                    grafoRespuesta[j][l] = grafo[j][l];
                }
            }
        }

        for(int j=0; j<Y; j++){
            for(int k=0; grafoRespuesta[j][k]; k++){
                cout << grafoRespuesta[j][k];
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
