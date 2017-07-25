//Number 23
#include <bits/stdc++.h>

using namespace std;

int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};

char grafo[1019][1010*2];
int grafoRespuesta[1010][1010*2];
int contador[1019][1010];
int mayor[1010];
int Y, X;

void floodfill(int r, int c, char c1, char c2, int numero) {
  if (r < 0 || r >= Y || c < 0 || c >= X) return;
  if (grafo[r][c] != c1) return;
  contador[r][c] = 1;
  grafo[r][c] = c2;
  grafoRespuesta[r][c] = numero;
  for (int d = 0; d < 8; d++)
    floodfill(r + dr[d], c + dc[d], c1, c2, numero);
}

int main()
{

    int checador = 0;
    while(1){
      memset(contador, 0, sizeof(contador));
      memset(grafoRespuesta, 0, sizeof(grafoRespuesta));
      memset(mayor, 0, sizeof(mayor));
      Y = 0;
      X = 0;
      while(1){
        string cadena;
        getline(cin, cadena);
        if(cadena[0] == '%'){
            break;
        }
        if(cadena == ""){
            checador++;
            break;
        }
        X = 0;
        for(int i=0; i<cadena.size(); i++){
          if(cadena[i] != ' '){
           grafo[Y][X] = cadena[i];
           X++;
          }
        }
        Y++;
      }
      int cont = 1;
      for(int i=0; i<Y; i++){
        for(int j=0; j<X; j++){
            if(contador[i][j] == 0){
                char letra = grafo[i][j];
                floodfill(i, j, letra, '.', cont);
                cont++;
            }
        }
      }

      for(int i=0; i<X; i++){
        int mayornumero = 0;
        for(int j=0; j<Y; j++){
         if(grafoRespuesta[j][i] > mayornumero){
            mayornumero = grafoRespuesta[j][i];
         }
        }
        mayor[i] = mayornumero;
      }

      for(int i=0; i<Y; i++){

        for(int j=0; j<X; j++){
            int mayorsito =  mayor[j];
            int numero = grafoRespuesta[i][j];
            int sifras;
            int sifras2;

            if(mayorsito < 10){
                sifras = 1;
            }
            if(mayorsito >= 10 && mayorsito < 100){
                sifras = 2;
            }
            if(mayorsito >= 100 && mayorsito < 1000){
                sifras = 3;
            }
            if(mayorsito >= 1000 && mayorsito < 10000){
                sifras = 4;
            }


            if(numero < 10){
                sifras2 = 1;
            }
            if(numero >= 10 && numero < 100){
                sifras2 = 2;
            }
            if(numero >= 100 && numero < 1000){
                sifras2 = 3;
            }
            if(numero >= 1000 && numero < 10000){
                sifras2 = 4;
            }


            if(sifras == 3){
                if(sifras2 == 1){
                    cout << " ";
                    cout << " ";
                }
                if(sifras2 == 2){
                    cout << " ";
                }
            }
            if(sifras == 2){
                if(sifras2 == 1){
                    cout << " ";
                }
            }
            if(sifras == 4){
                if(sifras2 == 1){
                    cout << " ";
                    cout << " ";
                    cout << " ";
                }
                if(sifras2 == 2){
                    cout << " ";
                    cout << " ";
                }
                if(sifras2 == 3){
                    cout << " ";
                }
            }

            cout << grafoRespuesta[i][j];
            if(j < X-1){
                cout << " ";
            }
        }
        cout << "\n";
      }
      cout << '%' << "\n";


      if(checador > 0){
        break;
      }

    }

    return 0;
}
