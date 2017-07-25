//Number 15
#include <bits/stdc++.h>

int dx[]={0,0,1,-1,1,-1};
int dy[]={1,-1,0,0,1,-1};

char grafo[200][200];
int dfs_num[200][200];
int tama;
int cont;

void dfs(int x, int y) {
   if(y == tama-1){
      cont = 1;
      return;
   }
   dfs_num[y][x] = 1;
   for(int i=0; i<6; i++){
      int X = x + dx[i];
      int Y = y + dy[i];

      if(X >= 0 && Y >= 0 && X <= tama-1 && Y <= tama-1){
         if(grafo[Y][X] == 'b' && dfs_num[Y][X] == 0){
             dfs(X, Y);
         }
      }
   }
}

using namespace std;

int main()
{
    int caso = 0;
    while(cin >> tama && tama != 0){
        caso++;
        memset(dfs_num, 0, sizeof(dfs_num));
        for(int i=0; i<tama; i++){
            for(int j=0; j<tama; j++){
                cin >> grafo[i][j];
            }
        }

        cont = 0;
        for(int i=0; i<tama; i++){
            if(grafo[0][i] == 'b' && cont == 0){
                 dfs(i, 0);
            }
        }

        if(cont == 1){
            cout << caso << " B\n";
        }else{
            cout << caso << " W\n";
        }


    }

    return 0;
}
