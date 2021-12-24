#include <fstream>
#include <vector>
#include <string>
using namespace std;

int LEN, SIZE;

inline void deleter(vector<string> &x, char y, int z)
{
    if (x.size() == 1)
        return;

    for (int i = x.size() - 1; i >= 0; i--)
        if (x[i][z] != y)
            x.erase(x.begin() + i);

    SIZE = x.size();
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    string t;
    vector<string> s1;

    while (in >> t)
        s1.push_back(t);

    LEN = s1[0].length();
    SIZE = s1.size();

    vector<string> s2 = s1;

    int c0, c1;

    for (int i = 0; i < LEN; i++)
    {
        c0 = c1 = 0;
        for (int j = 0; j < SIZE; j++)
        {
            (s1[j][i] - '0') ? (c1++) : (c0++);
        }

        if (c0 > c1)
            deleter(s1, '0', i);
        else
            deleter(s1, '1', i);
    }

    SIZE = s2.size();
    for (int i = 0; i < LEN; i++)
    {
        c0 = c1 = 0;
        for (int j = 0; j < SIZE; j++)
        {
            (s2[j][i] - '0') ? (c1++) : (c0++);
        }

        if (c1 < c0)
            deleter(s2, '1', i);
        else
            deleter(s2, '0', i);
    }

    out << stoi(s1[0], 0, 2) * stoi(s2[0], 0, 2);

    in.close();
    out.close();
}