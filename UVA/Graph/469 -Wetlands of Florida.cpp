//Number 18
#include <bits/stdc++.h>

using namespace std;

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

char grafo[100][100];
char grafoAlterno[100][100];

int medida;
int cont;

int floodfill(int r, int c, char c1, char c2){
   if (r < 0 || r >= cont || c < 0 || c >= medida){
        return 0;
   }
   if (grafo[r][c] != c1){
      return 0;
   }
   int ans = 1;
   grafo[r][c] = c2;
   for (int d = 0; d < 8; d++)
    ans += floodfill(r + dx[d], c + dy[d], c1, c2);
   return ans;
}


int main()
{
    int casos;

    cin >> casos;
    for(int i=0; i<casos; i++){
        string primeraLinea;
        cin >> primeraLinea;
        medida = primeraLinea.size();
        for(int j=0; j<medida; j++){
            grafo[0][j] = primeraLinea[j];
        }
        cont = 1;
        int y;
        while(1){
            string cadena;
            cin >> cadena;
            if((int)cadena.size() != medida){
                if(cadena.size() == 1){
                    y = cadena[0];
                    y = y - 49;
                }
                if(cadena.size() == 2){
                    string numero = "";
                    numero+=cadena[0];
                    numero+=cadena[1];

                    y = atoi(numero.c_str());
                    y = y-1;
                }
                break;
            }
            for(int j=0; j<medida; j++){
                grafo[cont][j] = cadena[j];
            }
            cont++;
        }
        int x;
        cin >> x;
        x = x - 1;
        cin.ignore();


        for(int j=0; j<100; j++){
            memcpy(&grafoAlterno[j], &grafo[j], sizeof(grafo[0]));
        }


        int resultadoPrimero = floodfill(y, x, 'W', '.');
        cout << resultadoPrimero << "\n";

        while(1){
            for(int j=0; j<100; j++){
               memcpy(&grafo[j], &grafoAlterno[j], sizeof(grafoAlterno[0]));
            }
           string numeros;
           getline(cin, numeros);
           if(numeros == ""){
             break;
           }

           int tama = numeros.size();

           int Y, X;
           int auxY, auxX;

           if(tama == 3){
           Y = numeros[0];
           X = numeros[2];
           Y = Y - 49;
           X = X - 49;
           }
           if(tama == 5){
             string numeroTotal = "";
             int num;
             numeroTotal+=numeros[0];
             numeroTotal+=numeros[1];
             num = atoi(numeroTotal.c_str());

             Y = num-1;

             string numeroTotal2 = "";
             int num2;
             numeroTotal2+=numeros[3];
             numeroTotal2+=numeros[4];
             num2 = atoi(numeroTotal2.c_str());

             X = num2-1;
           }

           if(tama == 4){
              if(numeros[1] == 32){
                string numeroTotal = "";
                int num;
                numeroTotal+=numeros[0];
                num = atoi(numeroTotal.c_str());

                Y = num-1;

                string numeroTotal2 = "";
                int num2;
                numeroTotal2+=numeros[2];
                numeroTotal2+=numeros[3];
                num2 = atoi(numeroTotal2.c_str());

                X = num2-1;
              }else{
                string numeroTotal = "";
                int num;
                numeroTotal+=numeros[0];
                numeroTotal+=numeros[1];
                num = atoi(numeroTotal.c_str());

                Y = num-1;

                string numeroTotal2 = "";
                int num2;
                numeroTotal2+=numeros[3];
                num2 = atoi(numeroTotal2.c_str());

                X = num2-1;
              }
           }

           int resultado = floodfill(Y, X, 'W', '.');
           cout << resultado << "\n";
        }
        if(i < casos-1){
            cout << "\n";
        }

    }

    return 0;
}
