//Number 22
#include <bits/stdc++.h>

using namespace std;

int dr[] = {1,0,-1, 0};
int dc[] = {0,1, 0,-1};

char grafo[10][15];
int checador[10][15];
bool columinador[15];
int puntos;
int contador;

void floodfill(int r,int c, char c1, char c2){
   if (r < 0 || r >= 10 || c < 0 || c >= 15) return;
   if (grafo[r][c] != c1) return;
   grafo[r][c] = c2;
   for (int d = 0; d < 4; d++)
    floodfill(r + dr[d], c + dc[d], c1, c2);
}



int floodfillBusqueda(int r, int c, char c1){
   if (r < 0 || r >= 10 || c < 0 || c >= 15) return 0;
   if (grafo[r][c] != c1) return 0;
   if(checador[r][c] == 1) return 0;
   int ans = 1;
   checador[r][c] = 1;
   for (int d = 0; d < 4; d++)
     ans += floodfillBusqueda(r + dr[d], c + dc[d], c1);
   return ans;
}

void columnas(){
    for(int i=0; i<10; i++){
        for(int j=0; j<15; j++){
            int arriba = i-1;
            if(arriba < 10 && arriba >= 0){
                if(grafo[arriba][j] == '.' && grafo[i][j] != '.'){
                    grafo[arriba][j] = grafo[i][j];
                    grafo[i][j] = '.';
                    contador++;
                }
            }
        }
    }
}

void checarFilas(){
   int limite=0;
   for(int i=0; i<15; i++){
    for(int j=0; j<10; j++){
         if(grafo[j][i] == '.'){
            limite++;
         }
    }
     if(limite == 10){
        columinador[i] = 1;
     }
     limite = 0;
   }

}


int main()
{
    int casos;
    cin >> casos;

    for(int i=0; i<casos; i++){


         for(int j=9; j>=0; j--){
            for(int k=0; k<15; k++){
                cin >> grafo[j][k];
            }
         }
         int rojo, verde, azul, mayor;
         int x, y, x2, y2, x3, y3, X, Y;
         int cont=0, score=0;
         int bolas = 0;

         cout << "Game " << i+1 << ":\n\n";
         while(1){
            memset(checador, 0, sizeof(checador));
            memset(columinador, 0, sizeof(columinador));
            cont++;
            rojo = 0;
            verde = 0;
            azul = 0;
            mayor = 0, X=0, Y=0;
            x=0, y=0, x2=0, y2=0, x3=0, y3=0;
            char letra;
            for(int j=0; j<15; j++){
                for(int k=0; k<10; k++){
                    if(grafo[k][j] == 'R' && checador[k][j] == 0){
                        int resultado = floodfillBusqueda(k,j, 'R');
                        if(resultado > rojo){
                            rojo = resultado;
                            x = j, y = k;
                        }
                    }
                    if(grafo[k][j] == 'G' && checador[k][j] == 0){
                        int resultado = floodfillBusqueda(k, j, 'G');
                        if(resultado > verde){
                            verde = resultado;
                            x2 = j, y2 = k;
                        }
                    }
                    if(grafo[k][j] == 'B' && checador[k][j] == 0){
                        int resultado = floodfillBusqueda(k, j, 'B');
                        if(resultado > azul){
                            azul = resultado;
                            x3 = j, y3 = k;
                        }
                    }
                    if(rojo > verde && rojo > azul){
                        mayor = rojo;
                        X=x, Y=y;
                        letra = 'R';
                    }
                    if(verde > rojo && verde > azul){
                        mayor = verde;
                        X=x2, Y=y2;
                        letra = 'G';
                    }
                    if(azul > rojo && azul > verde){
                        mayor = azul;
                        X=x3, Y=y3;
                        letra = 'B';
                    }
                }
            }

            int fin = rojo+azul+verde;
            if(fin <= 1){
                break;
            }
            if(rojo <= 1 && azul <= 1 && verde <=1){
                break;
            }
            int puntos = (mayor - 2) * (mayor - 2);
            score = score + puntos;
            bolas = bolas + mayor;

            cout << "Move " << cont << " at (" << Y+1 << "," << X+1 << "): removed " << mayor << " balls of color " << letra << ", got " << puntos << " points.\n";
            floodfill(Y,X,letra, '.');

            while(1){
                contador = 0;
                columnas();
                if(contador == 0){
                    break;
                }
            }


            while(1){
                memset(columinador, 0, sizeof(columinador));
                contador = 0;
                checarFilas();
                for(int j=0; j<15; j++){
                    if(columinador[j] == 1){

                        if(j+1 < 15){
                            if(grafo[0][j+1] != '.'){
                                grafo[0][j] = grafo[0][j+1];
                                grafo[0][j+1] = '.';
                                contador++;
                            }
                            if(grafo[1][j+1] != '.'){
                                grafo[1][j] = grafo[1][j+1];
                                grafo[1][j+1] = '.';
                                contador++;
                            }
                            if(grafo[2][j+1] != '.'){
                                grafo[2][j] = grafo[2][j+1];
                                grafo[2][j+1] = '.';
                                contador++;
                            }
                            if(grafo[3][j+1] != '.'){
                                grafo[3][j] = grafo[3][j+1];
                                grafo[3][j+1] = '.';
                                contador++;
                            }
                            if(grafo[4][j+1] != '.'){
                                grafo[4][j] = grafo[4][j+1];
                                grafo[4][j+1] = '.';
                                contador++;
                            }
                            if(grafo[5][j+1] != '.'){
                                grafo[5][j] = grafo[5][j+1];
                                grafo[5][j+1] = '.';
                                contador++;
                            }
                            if(grafo[6][j+1] != '.'){
                                grafo[6][j] = grafo[6][j+1];
                                grafo[6][j+1] = '.';
                                contador++;
                            }
                            if(grafo[7][j+1] != '.'){
                                grafo[7][j] = grafo[7][j+1];
                                grafo[7][j+1] = '.';
                                contador++;
                            }
                            if(grafo[8][j+1] != '.'){
                                grafo[8][j] = grafo[8][j+1];
                                grafo[8][j+1] = '.';
                                contador++;
                            }
                            if(grafo[9][j+1] != '.'){
                                grafo[9][j] = grafo[9][j+1];
                                grafo[9][j+1] = '.';
                                contador++;
                            }
                        }
                    }
                }
                if(contador == 0){
                    break;
                }
            }

         }
          bolas = 150-bolas;
          if(bolas == 0){
             score = score + 1000;
          }
         cout << "Final score: " << score << ", with " << bolas << " balls remaining.\n";
         if(i < casos-1){
            cout << "\n";
         }

    }

    return 0;
}
