//Number 21
#include <bits/stdc++.h>

using namespace std;

int dr[] = {1,0,-1, 0};
int dc[] = {0,1, 0,-1};

char grafo[109][109];

int Y, X;

int floodfill(int r, int c, char c1, char c2){
   if (r < 0 || r >= Y || c < 0 || c >= X){
     return 0;
   }
   if (grafo[r][c] != c1){
    return 0;
   }
   int ans = 1;
   grafo[r][c] = c2;
   for (int d = 0; d < 4; d++){
     ans += floodfill(r + dr[d], c + dc[d], c1, c2);
   }
   return ans;
}

int main()
{
    int casos;
    cin >> casos;
    for(int i=0; i<casos; i++){
        int y, x;
        cin >> y >> x;
        cin.ignore();
        Y = 0;
        X = 0;

        while(1){
            string cadena;
            getline(cin, cadena);
            if(cadena == ""){
                break;
            }
            for(int j=0; j<cadena.size(); j++){
                if(cadena[j] == '0'){
                    grafo[Y][j] = 'W';
                }
                if(cadena[j] == '1'){
                    grafo[Y][j] = 'L';
                }
            }
            X= cadena.size();
            Y++;
        }

        x--;
        y--;

        int resultado = floodfill(y, x, 'W', 'L');
        cout << resultado << "\n";

        if(i < casos-1){
            cout << "\n";
        }

    }
    return 0;
}
