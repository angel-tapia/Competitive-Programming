#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

map <lli, lli> apCanicas;

int main(){
    lli N, C, K;
    cin>>N>>C>>K;
    
    lli grupos = __gcd(N, K);
    
    for(int i = 0; i < C; i++){
        int pos;
        cin>>pos;
        apCanicas[pos%grupos]++;
    }
    
    //Guardamos los dos valores mayores que fueron almacenados en apCanicas
    lli max1 = 0, max2 = 0;
    for(auto it = apCanicas.begin(); it != apCanicas.end(); it++){
        if(it->second > max1){
            max2 = max1;
            max1 = it->second;
        }else if(it->second > max2){
            max2 = it->second;
        }
    }

    //Imprimir el resultado max1 y max2
    cout<<max1<<" "<<max2<<endl;
}
