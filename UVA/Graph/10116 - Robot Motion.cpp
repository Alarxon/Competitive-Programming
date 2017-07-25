//Number 13
#include <bits/stdc++.h>

using namespace std;

int grafo[100][100];
int pasos[100][100];
int cont;
int checador;

int columnas, filas;

void dfs(int u, int v){
    cont++;
    int X, Y;

    if(grafo[u][v] == 1){
        X = v;
        Y = u - 1;
    }
    if(grafo[u][v] == 2){
        X = v;
        Y = u + 1;
    }
    if(grafo[u][v] == 3){
        X = v + 1;
        Y = u;
    }
    if(grafo[u][v] == 4){
        X = v - 1;
        Y = u;
    }

    if(X > 0 && X <= filas && Y > 0 && Y <= columnas){
        if(pasos[u][v] == 0){

            pasos[u][v] = cont;
            dfs(Y, X);
        }else{
           checador = pasos[u][v];
           return;
        }
    }else{
       return;
    }

}

int main()
{
    int entrada;
    while(cin >> columnas >> filas >> entrada && columnas != 0 && filas != 0 && entrada != 0){
         memset(grafo, 0, sizeof(0));
         char movimiento;
         for(int i=1; i<=columnas; i++){
            for(int j=1; j<=filas; j++){
                cin >> movimiento;
                if(movimiento == 'N'){
                    grafo[i][j] = 1;
                }
                if(movimiento == 'S'){
                    grafo[i][j] = 2;
                }
                if(movimiento == 'E'){
                    grafo[i][j] = 3;
                }
                if(movimiento == 'W'){
                    grafo[i][j] = 4;
                }
            }
         }
         memset(pasos, 0, sizeof(pasos));
         cont = 0;
         checador = 0;
         dfs(1, entrada);

         if(checador == 0){
            cout << cont << " step(s) to exit\n";
         }else{
            int loop = cont - checador;
            int pasos = checador-1;
            cout << pasos << " step(s) before a loop of " << loop << " step(s)\n";
         }

    }
    return 0;
}
