#include <bits/stdc++.h>

using namespace std;

const int MaxN = 200005;

typedef long long int lli;

lli arr[MaxN];
lli sumaPrefijos[MaxN];
lli sumaSufijos[MaxN];

//Funcion que resuelve un caso
void solve(){
    //Leer N
    lli N;
    cin >> N;

    //Leer arreglo
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    //Ordenar arreglo
    sort(arr, arr + N);

    //Haremos un precalculo de la suma de prefijos y de sufijos
    sumaPrefijos[0] = arr[0];
    sumaSufijos[N - 1] = arr[N - 1];

    for(int i = 1; i < N; i++) {
        sumaPrefijos[i] = sumaPrefijos[i - 1] + arr[i];
    }

    for(int i = N - 2; i >= 0; i--) {
        sumaSufijos[i] = sumaSufijos[i + 1] + arr[i];
    }

    //La idea es la siguiente, si tenemos un grupo de K de elementos rojos, habrá K+1 elementos azules
    //Podemos hacer que los ultimos K elementos sean rojos y los primeros K+1 sean azules

    //Probaremos para cada posible K de 1 a N/2-1 para que si se pueda hacer el acomodo

    //Se tiene el limite hasta cual se checara el acomodo, si es impart se le añade 1
    int lim = N / 2;
    if(N%2) lim += 1;

    for(int K = 1; K < lim; K++){
        //Los sufijos de N-K hasta N-1 son rojos (son K), los primeros K+1 son azules (ahí está como K por indexado en 0)
        if(sumaSufijos[N-K] > sumaPrefijos[K]){
            //Si se puede, se imprime "YES"
            cout << "YES" << "\n";
            return;
        }
    }

    //No se pudo, se imprime "NO"
    cout << "NO" << "\n";
}

int main(){
    //Declarar los T casos a resolver
    int T;
    cin>>T;

    //Resolver cada caso
    while(T--){
        solve();
    }

}
