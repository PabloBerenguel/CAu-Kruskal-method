#include<bits/stdc++.h>
using namespace std;

class subTree
{
	private:
	 vector<pair<int, int>> _value;

  public:
  subTree(int n);
	int recurs(int i);
	void match(int x, int y);
};
