#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int x = 0, y = 0, c = 0;
    
    in >> x;
    
    for(int i = 0; i < 2000; i++) {
        in >> y;
        
        if(y > x) c++;

        x = y;
    }
    
    out << c;

    in.close();
    out.close();
}