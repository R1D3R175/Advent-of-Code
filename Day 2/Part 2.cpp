#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    string s;
    int i;

    int x = 0, y = 0, a = 0;   

    while(in >> s >> i) {
        if(s == "forward") {
            x += i;
            y += a * i;
        } else if(s == "up") 
            a -= i;
        else
            a += i;
    }

    out << x * y;

    in.close();
    out.close();
}
