#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

void get_input(ifstream &in, vector<int> &c)
{
	string S;
	in >> S;

	replace(S.begin(), S.end(), ',', ' ');

	getline(in, S);

	stringstream ss(S);

	int x;
	while (ss >> x)
	{
		c.push_back(x);
	}
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	vector<int> crabs;

	get_input(in, crabs);

	sort(crabs.begin(), crabs.end());

	int k = crabs[crabs.size() / 2];
	int c = 0;

	for (int &i : crabs)
		c += abs(k - i);

	cout << c;

	in.close();
	out.close();
}
