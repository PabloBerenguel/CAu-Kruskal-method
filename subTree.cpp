#include "subTree.hpp"
#include<bits/stdc++.h>
using namespace std;

subTree::subTree(int size){
  _value.reserve(size);
  for (int i = 0; i <= size; i++){
    get<0>(_value[i]) = 0;
    get<1>(_value[i]) = i;
  }
}

int subTree::recurs(int i){
  if (i != get<1>(_value[i]))
    get<1>(_value[i]) = recurs(get<1>(_value[i]));
  return (get<1>(_value[i]));
}

void subTree::match(int x, int y){
  x = recurs(x);
  y = recurs(y);
  if (get<0>(_value[x]) > get<0>(_value[y]))
    get<1>(_value[y]) = x;
  else
    get<1>(_value[x]) = y;
  if (get<0>(_value[x]) == get<0>(_value[y]))
    get<0>(_value[y])++;
}
