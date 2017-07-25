//Number 14
#include <bits/stdc++.h>

using namespace std;

int grafo[100][100];

int main()
{
    int casos;
    cin >> casos;
    for(int i=0; i<casos; i++){
       memset(grafo, 0, sizeof(grafo));

       int y, x;
       cin >> y >> x;
       cin.ignore();

       for(int j=1; j<=y; j++){
         string laberinto;
         getline(cin, laberinto);
           for(int k=0; k<laberinto.size(); k++){
              if(laberinto[k] == '*'){
                  grafo[j][k+1] = 1;
              }
           }
       }
       int X, Y;
       cin >> Y >> X;
       cin.ignore();
       int cont = 0;
       char direccion = 'N';

       while(1){
           string movimientos;
           getline(cin, movimientos);
           for(int j=0; j<movimientos.size(); j++){
              if(movimientos[j] == 'Q'){
                 cont++;
                 break;
              }
              if(movimientos[j] == 'R'){
                 switch(direccion){
                    case 'N':
                    direccion = 'E';
                    break;
                    case 'E':
                    direccion = 'S';
                    break;
                    case 'S':
                    direccion = 'W';
                    break;
                    case 'W':
                    direccion = 'N';
                    break;
                 }
              }
              if(movimientos[j] == 'L'){
                 switch(direccion){
                   case 'N':
                   direccion = 'W';
                   break;
                   case 'W':
                   direccion = 'S';
                   break;
                   case 'S':
                   direccion = 'E';
                   break;
                   case 'E':
                   direccion = 'N';
                   break;
                 }
              }
              int checadorX = X;
              int checadorY = Y;
              if(movimientos[j] == 'F'){

                  if(direccion == 'N'){
                     checadorY--;
                  }
                  if(direccion == 'E'){
                     checadorX++;
                  }
                  if(direccion == 'S'){
                     checadorY++;
                  }
                  if(direccion == 'W'){
                     checadorX--;
                  }
              }
              if(grafo[checadorY][checadorX] == 0){
                  X = checadorX;
                  Y = checadorY;
              }

           }
           if(cont != 0){
              break;
           }
       }
       cout << Y << " " << X << " " << direccion << "\n";
       if(i < casos-1){
          cout << "\n";
       }
    }

    return 0;
}
