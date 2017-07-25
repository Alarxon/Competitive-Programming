//Number 16
#include <bits/stdc++.h>

using namespace std;

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

int grafo[100][100];
int dfs_num[100][100];
int pixeles;
int cont;

void dfs(int y, int x){
    dfs_num[y][x] = 1;
    for(int j=0; j<8; j++){
        int X = x + dx[j];
        int Y = y + dy[j];
        if(X >= 0 && Y >= 0 && X < pixeles && Y < pixeles){
             if(grafo[Y][X] == 1 &&dfs_num[Y][X] == 0){
                dfs(Y, X);
             }
        }
    }

}


int main()
{
    int caso = 0;
    while(cin >> pixeles && pixeles != EOF){
        memset(grafo, 2, sizeof(grafo));
        memset(dfs_num, 0, sizeof(dfs_num));
        caso++;
        for(int i=0; i<pixeles; i++){
            for(int j=0; j<pixeles; j++){
                char cadena;
                cin >> cadena;

                if(cadena == '1'){
                    grafo[i][j] = 1;
                }
                if(cadena == '0'){
                    grafo[i][j] = 0;
                }
            }
        }

        cont = 0;
        for(int i=0; i<pixeles; i++){
            for(int j=0; j<pixeles; j++){
                if(dfs_num[i][j] == 0 && grafo[i][j] == 1){
                    cont++;
                    dfs(i, j);
                }
            }
        }

        cout << "Image number " << caso << " contains " << cont << " war eagles.\n";
    }

    return 0;
}
