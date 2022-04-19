#include <iostream>
using namespace std;

pair <int, int> mergeSort(int N){
  if(N == 1){
    return {0, 0};
  }
  pair <int, int> ans, hijo;
  int menor, mayor;

  hijo = mergeSort(N/2);

  menor = hijo.first;
  mayor = hijo.second;

  ans.first = menor*2 + N/2;
  ans.second = mayor*2 + N-1;

  /*cout<<N<<"\n";
  cout<<ans.first<<" "<<menor<<"\n";
  cout<<ans.second<<" "<<mayor<<"\n";
  */return ans;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int N;
  cin>>N;
  
  pair <int, int> ans;

  ans = mergeSort(N);

  cout<<ans.first<<" "<<ans.second<<"\n";
  // TODO: fixme.

  return 0;
}
