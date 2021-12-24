#include <fstream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> Coord;

Coord getter(string s)
{
	int c = 0;
	while (s[c] != ',')
		++c;

	return Coord(stoi(s.substr(0, c)), stoi(s.substr(c + 1, s.length())));
}

inline void sorter(Coord &c1, Coord &c2, bool x)
{
	if (!x)
	{
		if (c1.first > c2.first)
		{
			int t = c1.first;
			c1.first = c2.first;
			c2.first = t;
		}
	}
	else
	{
		if (c1.second > c2.second)
		{
			int t = c1.second;
			c1.second = c2.second;
			c2.second = t;
		}
	}
}

void filler(vector<vector<int>> &m, Coord c1, Coord c2, int &c)
{
	bool x = true;
	if (c1.first != c2.first)
	{
		x = false;
		if (c1.second != c2.second)
			return;
	}

	sorter(c1, c2, x);

	if (!x)
	{
		for (int i = c1.first; i <= c2.first; ++i)
		{
			m[c1.second][i]++;
			if (m[c1.second][i] == 2)
				++c;
		}
	}
	else
	{
		for (int i = c1.second; i <= c2.second; ++i)
		{
			m[i][c1.first]++;
			if (m[i][c1.first] == 2)
				++c;
		}
	}
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	vector<Coord> start;
	vector<Coord> end;

	string line;

	int i = 0, N = 0, r = 0;
	while (getline(in, line))
	{
		i = 0;
		while (line[i] != '-')
			++i;

		start.emplace_back(getter(line.substr(0, i - 1)));
		if (start.back().first > N)
			N = start.back().first;
		if (start.back().second > N)
			N = start.back().second;

		end.emplace_back(getter(line.substr(i + 3, line.length())));
		if (end.back().first > N)
			N = end.back().first;
		if (end.back().second > N)
			N = end.back().second;
	}

	vector<vector<int>> m(N + 1, vector<int>(N, 0));

	for (int i = 0; i < start.size(); ++i)
		filler(m, start[i], end[i], r);

	out << r;

	in.close();
	out.close();
}