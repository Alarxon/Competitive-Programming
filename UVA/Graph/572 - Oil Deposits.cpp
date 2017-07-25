//Number 19
#include <bits/stdc++.h>

using namespace std;

int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};

int y, x;

char grafo[109][109];
int checador[109][109];

int floodfill(int r, int c, char c1, char c2) {
     if (r < 0 || r >= y || c < 0 || c >= x){
        return 0;
     }
     if (grafo[r][c] != c1){
        return 0;
     }
     int ans = 1;
     grafo[r][c] = c2;
     checador[r][c] = 1;
     for (int d = 0; d < 8; d++){
      ans += floodfill(r + dr[d], c + dc[d], c1, c2);
     }
     return ans;
}


int main()
{
    while(cin >> y >> x && y != 0 && x != 0){
         memset(grafo, 0, sizeof(grafo));
         memset(checador, 0, sizeof(checador));
         for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
                cin >> grafo[i][j];
            }
         }
         int cont=0;

         for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
                if(grafo[i][j] == '@' && checador[i][j] == 0){
                     floodfill(i, j, '@', '.');
                     cont++;
                }
            }
         }
         cout << cont << "\n";

    }

    return 0;
}
