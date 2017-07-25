//Number 3
#include <bits/stdc++.h>

using namespace std;

vector <vector<int> >vecinos;

int main()
{
    int casos;
    cin >> casos;
    for(int i=0; i<casos; i++){
        int num;
        cin >> num;
        vecinos.assign(1001, vector<int>());
         for(int j=1; j<=num; j++){
            int cont=0;
            int veci=0;
             while(1){
                cin >> veci;
                cont++;
                char c = getchar();
                 if( c == '\n' ){
                    break;
                }
             }
             vecinos[cont].push_back(j);
         }
        string espacio;
        getline(cin, espacio);
        for(int j=1; j<num; j++){
             if(vecinos[j].size() > 0){
                 for(int k=0; k<vecinos[j].size(); k++){
                      printf("%d", vecinos[j][k]);
                      if(k < vecinos[j].size()-1){
                           printf(" ");
                      }
                 }
                 printf("\n");
                 break;
             }
        }

    }

    return 0;
}
