//Number 11
#include <bits/stdc++.h>

using namespace std;

int puntos[10];


int main()
{
    int x, y, direccion;

    while(cin >> x){
        if(x == -1){
            break;
        }
        cin >> y >> direccion;
        memset(puntos, -1, sizeof(puntos));
        int X, Y, terreno;

        for(int i=0; i<8; i++){
           cin >> X >> Y >> terreno;
           int puntoX = X-x;
           int puntoY = Y-y;

           if(puntoX == 0 && puntoY == 1){
               puntos[0] = terreno;
           }
           if(puntoX == -1 && puntoY == 1){
              puntos[1] = terreno;
           }
           if(puntoX == -1 && puntoY == 0){
              puntos[2] = terreno;
           }
           if(puntoX == -1 && puntoY == -1){
              puntos[3] = terreno;
           }
           if(puntoX == 0 && puntoY == -1){
              puntos[4] = terreno;
           }
           if(puntoX == 1 && puntoY == -1){
              puntos[5] = terreno;
           }
           if(puntoX == 1 && puntoY == 0){
              puntos[6] = terreno;
           }
           if(puntoX == 1 && puntoY == 1){
              puntos[7] = terreno;
           }
        }
        direccion = direccion + 5;
        if(direccion > 7){
            direccion = direccion - 8;
        }

        for(int i=direccion; i<9; i++){
              if(i == 8){
                 i = 0;
              }
              if(puntos[i] == 1){
                 cout << i << "\n";
                 break;
              }
        }

    }

    return 0;
}
