//Number 6
#include <bits/stdc++.h>

using namespace std;

int checador[101][101];


int main()
{
    int X, Y;
    cin >> X >> Y;
    int x,y;
    char orientacion;
    memset(checador, 0, sizeof(checador));
    while(cin >> x >> y >> orientacion && x != EOF && y != EOF && orientacion != EOF){
        string cadena;
        cin >> cadena;

        int LOST = 0;
        int anteriorX=0, anteriorY=0;

        for(int i=0; i<cadena.size(); i++){
               if(cadena[i] == 'L'){
                    switch(orientacion){
                      case 'N':
                      orientacion = 'W';
                      break;
                      case 'W':
                      orientacion = 'S';
                      break;
                      case 'S':
                      orientacion = 'E';
                      break;
                      case 'E':
                      orientacion = 'N';
                      break;
                    }

               }
               if(cadena[i] == 'R'){
                    switch(orientacion){
                      case 'N':
                      orientacion = 'E';
                      break;
                      case 'E':
                      orientacion = 'S';
                      break;
                      case 'S':
                      orientacion = 'W';
                      break;
                      case 'W':
                      orientacion = 'N';
                      break;
                    }

               }

               if(x <= X && y <= Y && x >= 0 && y >= 0){
                    anteriorX = x;
                    anteriorY = y;
                 }

               if(cadena[i] == 'F'){
                    switch(orientacion){
                      case 'N':
                      y++;
                      break;
                      case 'E':
                      x++;
                      break;
                      case 'S':
                      y--;
                      break;
                      case 'W':
                      x--;
                      break;
                    }
               }


               if(x > X || y > Y || x < 0 || y < 0){
                    x = anteriorX;
                    y = anteriorY;
                    if(checador[x][y] == 1){
                      continue;
                    }else{
                       LOST++;
                       checador[x][y] = 1;
                       break;
                    }
              }
        }
        if(LOST >= 1){
            cout << x << " " << y << " " << orientacion << " LOST\n";
         }else{
           cout << x << " " << y << " " << orientacion << "\n";
        }
    }

    return 0;
}
