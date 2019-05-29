#include "Forest.hpp"
#include<bits/stdc++.h>
using namespace std;

bool onlyDigit(string str){
	if (str.size() == 0)
		return (false);
  int i = 0;
  while (i < str.length()){
    if (isdigit(str[i]))
      i++;
    else
      return (false);
  }
  return (true);
}

int main(int ac, char **av)
{
 if (ac>1){
	 cout << "Running with the sample gave in the homework." << endl;
	 Forest forest;
	 forest.add(1, 2, 3);
	 forest.add(1, 5, 2);
	 forest.add(2, 3, 1);
	 forest.add(2, 6, 5);
	 forest.add(3, 4, 4);
	 forest.add(3, 7, 1);
	 forest.add(4, 8, 6);
	 forest.add(5, 6, 1);
	 forest.add(5, 9, 3);
	 forest.add(6, 7, 5);
	 forest.add(6, 10, 4);
	 forest.add(7, 8, 8);
	 forest.add(7, 11, 2);
	 forest.add(8, 12, 6);
	 forest.add(9, 10, 2);
	 forest.add(9, 13, 2);
	 forest.add(10, 11, 4);
	 forest.add(10, 14, 6);
	 forest.add(11, 12, 6);
	 forest.add(11, 15, 4);
	 forest.add(12, 16, 4);
	 forest.add(13, 14, 3);
	 forest.add(14, 15, 5);
	 forest.add(15, 16, 7);

	 cout << endl << "Results: "  << endl;
	 ac = forest.algo(subTree(24));
	 cout << endl << "The total weight is " << ac << endl;
	}
 else {
	vector<int> result;

	string x = "";
	string y = "";
	string w = "";
	bool end = false;

	cout << "Please enter all links as asked, when finish enter 'end'." << endl << "Run with the argument 'sample' to use the sample showed in the homework." << endl;

	while (end != true){
		x = "";
		y = "";
		w = "";

		cout << "New link:" << endl;
		cout << "From: ";
		while (onlyDigit(x) == false && end == false && x != "end"){
			getline(std::cin, x);
			if (onlyDigit(x) == false && x != "end")
				cout << "Please enter a valid tree number." << endl << "From: ";
			}
		if (x == "end")
			end = true;
		if (end != true)
			cout << "To: ";
		while (onlyDigit(y) == false && end == false && y != "end" || y == x){
			getline(std::cin, y);
			if (onlyDigit(y) == false && y != "end" || y == x)
				cout << "Please enter a valid tree number." << endl << "To: ";
			}
		if (y == "end")
			end = true;
		if (end != true)
			cout << "Weight: ";
		while (onlyDigit(w) == false && end == false && w != "end"){
			getline(std::cin, w);
			if (onlyDigit(w) == false && w != "end")
				cout << "Please enter a valid tree number." << endl << "Weight: ";
			}
		if (w == "end")
			end = true;
		if (end != true){
			result.push_back(std::stoi(x));
			result.push_back(std::stoi(y));
			result.push_back(std::stoi(w));
			cout << "New link created." << endl;
			cout << endl;
			}
		}
	if (result.size() < 2)
		cout << "Forest is too small." << endl;
	else {
		cout << "Resume:" << endl;
		Forest forest;
		for (int i = 0; i < result.size(); i += 3){
				cout << "Link from: " << result[i] << " to: " << result[i + 1] << " with a weight of: " << result[i + 2] << endl;
				forest.add(result[i], result[i+1], result[i+2]);
			}
			cout << endl << "Results: "  << endl;
			ac = forest.algo(subTree(result.size()));
			cout << endl << "The total weight is " << ac << endl;
		}
	}
	return (0);
}
