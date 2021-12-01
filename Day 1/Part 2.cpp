#include <fstream>
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int x = 0, y = 0, z = 0, c = 0, tmp1 = 0, tmp2 = 0;

    in >> x >> y >> z;

    for(int i = 0; i < 1997; i++) { // 1997 we already took 3 input variables before the for cycle
        tmp1 = x + y + z;
        
        x = y;                          
        y = z;
        in >> z;

        tmp2 = x + y + z;

        if(tmp1 < tmp2) c++;
    }
    
    out << c;
    
    in.close();
    out.close();
}