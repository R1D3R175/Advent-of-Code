#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

void get_input(ifstream& in, vector<int> &f) {
    string input;
    in >> input;

    replace(input.begin(), input.end(), ',', ' ');

    stringstream n(input);

    int x;
    while(n >> x) f.push_back(x);
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    vector<int> fish;

    get_input(in, fish);

    for(int i = 0; i < 80; ++i) {
        int N = fish.size();

        for(int f = 0; f < N; ++f) {
            if(fish[f] == 0) {
                fish.push_back(8);
                fish[f] = 6;
                continue;
            }

            --fish[f];
        }
    }

    out << fish.size();

    in.close();
    out.close();
}