#include <fstream>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    string s;
    int i;

    int x = 0, y = 0;

    while (in >> s >> i)
    {
        if (s == "forward")
            x += i;
        else if (s == "up")
            y -= i;
        else
            y += i;
    }

    out << x * y;

    in.close();
    out.close();
}