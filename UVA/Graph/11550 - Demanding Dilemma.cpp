//Number 4
#include <bits/stdc++.h>

using namespace std;

int matriz[10][100];


int main()
{
    int casos;
    cin >> casos;
    for(int i=0; i<casos; i++){
        int m, n;
        cin >> m >> n;
         memset(matriz,0,sizeof(matriz));
         for(int j=0; j<m; j++){
            for(int k=0; k<n; k++){
                cin >> matriz[j][k];
            }
         }
         int cont=0;
         int aux[m][m];
         memset(aux, 0, sizeof(aux));
         int mal=0;
         for(int j=0; j<n; j++){
            int acumulador=0;
            cont = 0;
            int x , y;
            for(int k=0; k<m; k++){
                 if(matriz[k][j] == 1){
                      if(acumulador == 0){
                          x =k;
                      }else{
                          y=k;
                      }
                      acumulador++;
                      cont++;
                 }
            }
              if(cont != 2){
                  mal = 1;
              }else{
                 if(aux[x][y] == 1 || aux[y][x] == 1){
                    mal = 1;
                 }
                 aux[x][y] = 1;
                 aux[y][x] = 1;
              }
         }
         if(mal == 1){
             printf("No\n");
         }else{
             printf("Yes\n");
         }

    }

    return 0;
}
