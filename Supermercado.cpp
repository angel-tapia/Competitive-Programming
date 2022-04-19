#include <bits/stdc++.h>
using namespace std;

//Funcion booleana que recibe un pair <float, string> y quiere ordenar de mayor a menor por el primer elemento
bool comp(pair<float, string> &a, pair<float, string> &b) {
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main(){
    //Leer la cantidad de productos
    int N;
    cin>>N;

    //Declarar el arreglo de productos
    vector <pair <float, string> > lista;

    //Declarar total
    float total = 0;

    //Leer los productos
    for(int i = 0; i < N; i++){
        string nombre;
        float precio;

        cin>>nombre>>precio;

        //Se suman todos los precios a total
        total += precio;

        lista.push_back({precio, nombre});
    }

    //Ordenar los productos de acuerdo al de mayor a menor precio y después nombre
    sort(lista.begin(), lista.end(), comp);

    //Imprimir los productos ordenados con el siguiente formato
    //i | nombre | precio
    for(int i = 0; i < N; i++){
        cout<<i+1<<" | "<<lista[i].second<<" | "<<lista[i].first<<"\n";
    }

    //Imprimir el total
    cout<<"\n"<<total<<"\n";

}
