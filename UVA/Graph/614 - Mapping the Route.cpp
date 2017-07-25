//Number 10
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > grafo;
int mapa[500][500];
int resultado[500];
int checar;

int columnas, filas;
int x2, y2;
int NumeroFinal;
int x, y;

void dfs(int u, int cont){
   resultado[u] = resultado[cont] + 1;
   if(NumeroFinal == u){
      checar = 1;
   }
   for(int i=0; i<grafo[u].size(); i++){
      if(checar == 0){
        int v = grafo[u][i];
        if(resultado[v] == 0){
            dfs(v, u);
        }
      }
   }
   if(checar == 0){
      resultado[u] = -1;

   }

}

int main()
{
    int caso=1;
    while(1){
        cin >> columnas >> filas >> x >> y >> x2 >> y2;
        if(columnas == 0 && filas == 0 && x == 0 && y == 0 && x2 == 0 && y2 == 0){
            break;
        }
        grafo.assign(500, vector<int>());
        memset(mapa, 0, sizeof(mapa));

        for(int i=1; i<=columnas; i++){
            for(int j=1; j<=filas; j++){
                cin >> mapa[i][j];
            }
        }
        int cont = 1;

        for(int i=1; i<=columnas; i++){
            for(int j=1; j<=filas; j++){
                int derecha = cont + 1;
                int izquierda = cont - 1;
                int arriba = cont - filas;
                int abajo = cont + filas;

                int limiteDerecho = filas * i;
                int limiteArriba = 1;
                int limiteIzquierdo = limiteDerecho - (filas - 1);
                int limiteAbajo = filas*columnas;

                if(izquierda >= limiteIzquierdo){
                    switch(mapa[i][j-1]){
                      case 0:
                      grafo[cont].push_back(izquierda);
                      break;
                      case 1:
                      break;
                      case 2:
                      grafo[cont].push_back(izquierda);
                      break;
                      case 3:
                      break;
                    }
                }

                if(arriba >= limiteArriba){
                    switch(mapa[i-1][j]){
                      case 0:
                      grafo[cont].push_back(arriba);
                      break;
                      case 1:
                      grafo[cont].push_back(arriba);
                      break;
                      case 2:
                      break;
                      case 3:
                      break;
                    }
                }

                if(derecha <= limiteDerecho){
                     switch(mapa[i][j]){
                        case 0:
                        grafo[cont].push_back(derecha);
                        break;
                        case 1:
                        break;
                        case 2:
                        grafo[cont].push_back(derecha);
                        break;
                        case 3:
                        break;
                     }
                }

                if(abajo <= limiteAbajo){
                    switch(mapa[i][j]){
                      case 0:
                      grafo[cont].push_back(abajo);
                      break;
                      case 1:
                      grafo[cont].push_back(abajo);
                      break;
                      case 2:
                      break;
                      case 3:
                      break;
                    }
                }

                cont++;

            }
        }
        memset(resultado, 0, sizeof(resultado));
        int puntoInciial = ((x - 1) * filas) + y;
        NumeroFinal = ((x2 - 1) * filas) + y2;
        checar = 0;
        resultado[puntoInciial] = 1;

        dfs(puntoInciial, 0);

        printf("Maze %d\n\n", caso);
        cout << '+';
        for(int i=1; i<=filas; i++){
            printf("---+");
        }
        cout << endl;

        int imprimidor = 1;
        for(int i=1; i<=columnas; i++){
            cout << '|';
            for(int j=1; j<=filas; j++){
                if(resultado[imprimidor] == -1){
                    cout << "???";
                }else if(resultado[imprimidor] == 0){
                    cout << "   ";
                }else{
                    printf("%3d", resultado[imprimidor]);
                }
                if(j == filas || mapa[i][j] == 1 || mapa[i][j] == 3){
                       cout << "|";
                }else{
                       cout << " ";
                }
                imprimidor++;
            }

            cout << endl;
            cout << '+';
            for(int j=1; j<=filas; j++){
                if(i == columnas || mapa[i][j] == 2 || mapa[i][j] == 3){
                     cout << "---+";
                }else{
                     cout << "   +";
                }
            }
            cout << endl;
        }
         caso++;
         cout << "\n\n";

    }
    return 0;
}
