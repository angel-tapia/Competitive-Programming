#include <iostream>
using namespace std;

//Funcion que regresa un pair de int, como se comento en la linea que se llama la funcion mergeSort, izquierdo es optimo y derecho mas tardado
pair <int, int> mergeSort(int N){
  //Caso base para N = 1
  if(N == 1){
    return {0, 0};
  }
  //En ans se guarda la respuesta para la N actual, en hijo se guarda la respuesta que se calcula recursivamente
  pair <int, int> ans, hijo;
  //menor se refiere con la menor cantidad de comparaciones y mayor con la mayor cantidad de comparaciones
  int menor, mayor;
  
  //Se calcula recursivamente la respuesta para N/2
  hijo = mergeSort(N/2);

  //Menor es hijo.first por ser optimo
  menor = hijo.first;
  //Mayor es hijo.second por ser el mas tardado
  mayor = hijo.second;

  //ans se calcula de la siguiente forma, la respuesta de mis hijos + lo que tarda en los dos arreglos actuales
  ans.first = menor*2 + N/2;
  ans.second = mayor*2 + N-1;
  //Se multiplica por dos el menor y mayor, ya que estos dos tuvieron 2 hijos por lo cual hay que contarlos a ambos
  
  //Se regresa respuesta
  return ans;
}

int main() {
  //Optimización de tiempo cout y cin
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  
  //Leer la N
  int N;
  cin>>N;
  
  //Se almacena la respuesta en un pair de ints, donde el izquierdo es el mas optimo y el derecho es el mas tardado
  pair <int, int> ans;

  //Se llama la funcion con la N dada
  ans = mergeSort(N);

  //Se imprime la respuesta
  cout<<ans.first<<" "<<ans.second<<"\n";
  
  return 0;
}
