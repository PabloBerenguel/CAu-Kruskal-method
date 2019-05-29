#include "Forest.hpp"

Forest::Forest(){
  this->_weight = 0;
}

void Forest::add(int from, int to, int weight){
  _forest.push_back({weight, {from, to}});
  sort(_forest.begin(), _forest.end());
}

int Forest::algo(subTree sTree){
	for (vector<pair<int, pair<int, int>>>::iterator it =_forest.begin(); it!=_forest.end(); it++)
		if (sTree.recurs(it->second.first) != sTree.recurs(it->second.second) && (this->_weight += it->first) > 0 && (cout << "Link from: "<< it->second.first << " to: " << it->second.second << endl))
			sTree.match(sTree.recurs(it->second.first), sTree.recurs(it->second.second));
	return (this->_weight);
}
