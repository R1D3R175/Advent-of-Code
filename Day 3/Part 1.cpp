#include <fstream>
#include <vector>
#include <string>
using namespace std;

#define LEN 12
#define SIZE 1000

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    string t;
    vector<string> s;

    while(in >> t) s.push_back(t);

    string gamma = "", epsilon = "";

    int c0, c1;

    for(int i = 0; i < LEN; i++) {
        c0 = c1 = 0;
        for(int j = 0; j < SIZE; j++) {
            (s[j][i]-'0') ? (c1++) : (c0++);
        }

        if(c0 > c1) {
            gamma += '0';
            epsilon += '1';
        } else {
            gamma += '1';
            epsilon += '0';
        }
    }

    out << stoi(gamma, 0, 2) * stoi(epsilon, 0, 2) << endl;
       
    in.close();
    out.close();
}