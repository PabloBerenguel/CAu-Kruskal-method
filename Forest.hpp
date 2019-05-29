#include "subTree.hpp"
#include<bits/stdc++.h>
using namespace std;

class Forest
{
  private:
   int _weight;
   vector<pair<int, pair<int, int>>> _forest;

  public:
    Forest();
    void add(int from, int too, int weight);
    int algo(subTree sTree);
};
