//Number 2

#include <bits/stdc++.h>

using namespace std;

int matriz[10000][10000];
int posiciones[10000];
int numeros[10000];

int main()
{
    int m,n;
    while(cin >> m >> n && m != EOF && n != EOF){
        memset(matriz, 0, sizeof(matriz));
         for(int i=1; i<=m; i++){
              memset(posiciones, 0, sizeof(posiciones));
              int num;
              cin >> num;
              if(num != 0){
              for(int j=1; j<=num; j++){
                   cin >> posiciones[j];
              }
              for(int j=1; j<=num; j++){
                  int elemento;
                  cin >> elemento;
                  matriz[i][posiciones[j]] = elemento;
              }
               }else{
                 string espacio;
                 getline(cin, espacio);
               }
         }
         printf("%d %d\n", n, m);
         int cont=0;
         for(int j=1; j<=n; j++){
                memset(numeros, 0, sizeof(numeros));
                memset(posiciones, 0, sizeof(posiciones));
                cont=0;
            for(int k=1; k<=m; k++){
                if(matriz[k][j] != 0){
                    cont++;
                    posiciones[cont] = k;
                    numeros[cont] = matriz[k][j];
                }
            }
             printf("%d", cont);
                for(int l=1; l<=cont; l++){
                    printf(" ");
                    printf("%d", posiciones[l]);
                }
                printf("\n");
                for(int l=1; l<=cont; l++){
                    printf("%d", numeros[l]);
                    if(l < cont){
                        printf(" ");
                    }
                }
                printf("\n");
         }

    }

    return 0;
}
