//Number 5
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<vector<ll> >arreglo;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll m,n;
    while(cin >> m >> n && m != EOF && n != EOF){
        ll a;
        arreglo.assign(1000000, vector<ll> ());
        for(ll i=0; i<m; i++){
            cin >> a;
            arreglo[a].push_back(i+1);
        }

        ll x, y;
        for(ll i=1; i<=n; i++){
            cin >> x >> y;
            x = x -1;
            if(x < arreglo[y].size()){
            cout << arreglo[y][x] << "\n";
            }else{
               cout << "0\n";
            }

        }
    }


    return 0;
}
