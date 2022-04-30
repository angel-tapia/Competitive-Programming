#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
const int MaxN = 100005;

lli arr[MaxN];

lli candidates[MaxN];
int main(){
    lli H, N, limite;
    lli sumTotal, cantidad;

    //Horas y Cantidad libros
    cin>>H>>N;

    //Leer los libros que tendremos
    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }

    //Ordenar el arreglo
    sort(arr, arr+N);

    //Marcar el limite de paginas que podemos leer
    limite = H*60;

    sumTotal = 0;
    cantidad = 0;
    for(int i = 0; i < N; i++){
        sumTotal += arr[i];
        if(sumTotal <= limite){
            cantidad += 1;
            candidates[i] = i;
        }
        else {
            sumTotal -= arr[i];
            break;
        }
    }

    /**
    Hacer two pointers, primero quitamos el mayor numero
    y después encontrar el numero más grande que podemos meter
    repetimos el algoritmo con el siguiente más grande
    (de los anteriores que eran grandes)
    Por ejemplo:
    Si tenemos el arreglo (ordenado por anterioridad)
    5 10 20 35 40 60 100
    Con un limite de paginas a leer de 120
    Nuestro rango de seleccionados sería
    (5 10 20 35) 55 60 100

    Entonces quitaremos el 35 e intentaremos
    maximizar el número que podemos meter
           L          R
    (5 10 20) 35 55 (60) 100

    Después quitamos el 20 que es el siguiente más
    grande anterior e intentamos utiliza el numero
    mas grande posible
          L      R
    (5 10 20) 35 55 (60) 100
       L   R
    (5 10) 20 (35) 55 (60) 100

    De nuevo, quitamos el siguiente mas grande(el 10)
    e intentamos poner el mas gande posible (el 20)


     L   R
     (5) 10 (20) (35) 55 (60) 100
     Ahora intentamos quitar el 5, intentamos poner el
     mas grande pero no existe, entonces así queda
     nuestra respuesta final
    */

    ///Conseguimos el mayor numero que podemos meter
    int L = cantidad-1, R;
    ///Quitamos el actual candidato mayor
    sumTotal -= arr[candidates[cantidad-1]];

    ///For para ver cual mayor es el candidato nuevo
    for(int i = L+1; i < N; i++){
        if(sumTotal + arr[i] <= limite){
            R = i;
            candidates[cantidad-1] = i;
        }
    }

    ///Adding el nuevo candidato mayor
    sumTotal += arr[candidates[cantidad-1]];

    ///Aplicamos la idea de los two pointers, quitar el mayor actual candidato viejo y añadir uno nuevo
    R -= 1;
    L -= 1;

    ///Mientras L < R entonces todavia queda candidatos por ver
    while(L < R){
        ///Si es posible agarrar el nuevo mayor y quitar el viejo mayor entonces lo hacemos
        if(sumTotal - arr[candidates[L]] + arr[R] <= limite){
            //cout<<sumTotal<<" "<<arr[candidates[L]]<<" "<<arr[R]<<"\n";
            sumTotal -= arr[candidates[L]];
            candidates[L] = R;
            sumTotal += arr[R];
            L -= 1;
            R -= 1;
        }
        else {
            ///Caso contrario pasamos al siguiente mayor nuevo
            R -= 1;
        }
    }

    ///Imprimir nuestra respuesta
    for(int i = 0; i < cantidad; i++){
        cout<<arr[candidates[i]]<<" ";
    }

}
