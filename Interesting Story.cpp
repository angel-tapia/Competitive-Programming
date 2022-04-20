#include <bits/stdc++.h>

using namespace std;

//Limites
const int MaxN = 200005;

string palabras[MaxN];

void solve(){
    int N;
    cin >> N;

    //Leer N palabras
    for(int i = 0; i < N; i++) {
        cin >> palabras[i];
    
    }

    //Variable donde se almacena el resultado actual es maximo, respuesta final es answer
    int maximo = 0, answer = 0;

    //Para cada posible letra haremos lo siguiente
    //1. Para cada palabra le asignamos un numero, ese numero tiene el siguiente valor = apariciones[letraActual] - aparicionesDemas
    //2. Obtenemos un nuevo arreglo donde estarán todos los valores de asignados, lo ordenamos de menor a mayor  o de mayor a menor
    //3. Supongamos que lo ordenamos de mayor a menor, agarraremos los numeros mientras la suma sea positiva, una vez que sea 0 o negativa, entonces ya no agarramos esa palabra
    //4. Actualizamos nuestro maximo y la respuesta

    //Para cada letra
    for(int i = 0; i < 5; i++){

        vector <int> asignados;
        int aparicionesLetra = 0;
        int aparicionesDemas = 0;
        maximo = 0;

        for(int j = 0; j < N; j++){
            
            //Por cada palabra calculamos su valor de asignacion
            aparicionesLetra = 0;
            aparicionesDemas = 0;

            for(int p = 0; p < palabras[j].size(); p++){
                //Calculamos la cantidad de apariciones de la letra actual
                if(palabras[j][p] - 'a' == i){
                    aparicionesLetra += 1;
                }
                else {
                    aparicionesDemas += 1;
                }
            }

            //Insertamos el valor de asignacion
            asignados.push_back(aparicionesLetra - aparicionesDemas);
        }

        //Ordenamos el arreglo de menor a mayor
        sort(asignados.begin(), asignados.end());

        //Hacemos una variable donde guardaremos la suma actual
        int suma = 0;

        //Hacemos un for para agarrar los numeros mientras sea positivo
        for(int j = asignados.size() - 1 ; j >= 0; j--){
            suma += asignados[j];
            if(suma <= 0){
                break;
            }
            maximo += 1;
        }

        //Actualizamos nuestra respuesta
        answer = max(answer, maximo);
    }

    //Imprimir respuesta
    cout << answer << "\n";
}

int main(){
    cin.tie(0),ios_base::sync_with_stdio(0);
    int T;

    cin >> T;

    while(T--){
        solve();
    }


}
