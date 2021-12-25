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

int nth_triangle_ranged(int t1, int t2)
{
	int t = abs(t1 - t2);

	return (t * (t + 1)) / 2;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	vector<int> crabs;

	get_input(in, crabs);

	float c = 0;

	for (int &i : crabs)
		c += i;

	int k = c / crabs.size();

	int s = 0;
	for (int &i : crabs)
		s += nth_triangle_ranged(k, i);

	out << s;

	in.close();
	out.close();
}
