#include <bits/stdc++.h>

using namespace std;

//Limite
const int MaxN = 100005;

//Acortar la definicion del long long int
typedef long long int lli;

//Declarando arreglo
lli arr[MaxN];

//Tener siempre en cuenta que como podemos tener numeros grandes y tamaño arreglo grande, entonces hacemos todo long long int

int main(){
    //Declarar el tamaño y rango K
    lli N, K;
    cin>>N>>K;

    //Declarar la respuesta (con un limite muy grande), junto con la actual respuesta calculada
    lli ans = 1e18, actual = 0, sum = 0;

    //Leer arreglo de enteros
    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }

    //Ordenar el arreglo
    sort(arr, arr + N);

    //Calcular para el primer K rango

    //Sum sirve para llevar la suma de los primeros i-esimos numeros
    sum = arr[0];

    for(int i = 1; i < K; i++){
        //Se puede notar que se le sumara a actual el arr[i] * i y se le restara la sum de los pasados
        actual += arr[i] * i - sum;

        //Como ya se actualizo hasta arr[i], se añade a sum el arr[i]
        sum += arr[i];

        //Se aplica para los primeros K
    }

    ans = actual;

    for(int i = K; i < N; i++){
        //Se actualiza con el nuevo i-esimo

        //Se añade para el i-esimo K-1 veces
        actual += (K-1)*arr[i];
        //Se añade para el i-esimo - K  (K-1) veces tambien
        actual += (K-1)*arr[i-K];

        //Se quita el i-K numero
        sum -= arr[i-K];

        //Se resta dos veces la suma de los números del grupo i-K e i ignorando estos mismos
        actual -= 2*sum;

        sum += arr[i];

        //Se actualiza la ans con la actual
        //cout<<actual<<"\n";
        ans = min(ans, actual);
    }

    cout<<ans<<"\n";


}
