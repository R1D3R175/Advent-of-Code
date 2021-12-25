#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <sstream>
using namespace std;

void get_input(ifstream &in, unordered_map<int, unsigned long long> &m)
{
    string input;
    in >> input;

    replace(input.begin(), input.end(), ',', ' ');

    stringstream n(input);

    int x;
    while (n >> x)
        m[x]++;
}

inline unsigned long long sum(unordered_map<int, unsigned long long> &um)
{
    unsigned long long s = 0;

    for (int i = 0; i <= 8; ++i)
        s += um[i];

    return s;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    unordered_map<int, unsigned long long> fish;
    for (int i = -1; i <= 8; ++i)
        fish[i] = 0;

    get_input(in, fish);

    for (int i = 0; i < 256; ++i)
    {
        for (int k = 0; k <= 8; ++k)
        {
            unsigned long long t = fish[k - 1];
            fish[k - 1] = fish[k];
            fish[k] = t;
        }

        fish[6] += fish[-1];
        fish[8] += fish[-1];
        fish[-1] = 0;
    }

    out << sum(fish) << endl;

    in.close();
    out.close();
}