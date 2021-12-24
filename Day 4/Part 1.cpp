#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;

typedef pair<int, int> Coord;

vector<int> get_winners(string s) {
    vector<int> x;
    
    int last = 0;
    for(int i = 0; i < s.length(); ++i) 
        if(s[i] == ',') {
            x.emplace_back(stoi(s.substr(last, i-last)));

            last = i + 1;
        }
    
    return x;
}

inline void add_table(vector<vector<vector<int> > > &m) {
    m.emplace_back(vector<vector<int> >(5, vector<int>(5)));
}

int remaining_sum(vector<vector<int> > &m) {
    int sum = 0;

    for(vector<int>& v : m) 
        for(int& e : v) 
            sum += e;
    
    return sum;
}

bool is_winner(vector<vector<int> > &a) {
    for(int i = 0; i < 5; ++i) {
        bool row_check = true;
        bool col_check = true;

        for(int j = 0; j < 5; ++j) {
            if(a[i][j] != 0) row_check = false;

            if(a[j][i] != 0) col_check = false;
        }

        if(row_check || col_check) return true;
    }

    return false;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    string S;
    in >> S;

    vector<int> winners = get_winners(S);

    vector<vector<vector<int> > > tables;

    vector<unordered_map<int, Coord> > tracker(100);

    for(int z = 0; !in.eof(); ++z) {
        add_table(tables);
        for(int y = 0; y < 5; ++y) {
            for(int x = 0; x < 5; ++x) {
                in >> tables[z][y][x];

                // tracker[number][all tables with that number in] -> coords
                tracker[tables[z][y][x]].insert({ z, Coord(y, x) });
            }
        }
    }

    // can't have a winner with <=4 numbers extracted
    for(int i = 0; i < 4; ++i)
        for(auto const& pair : tracker[winners[i]]) 
            tables[pair.first][pair.second.first][pair.second.second] = 0;
        

    int res, winner;
    for(int i = 4; i < winners.size(); ++i) {
        for(auto const& pair : tracker[winners[i]]) {
            tables[pair.first][pair.second.first][pair.second.second] = 0;

            if(is_winner(tables[pair.first])) {
                res = winners[i];
                winner = pair.first;
                goto found; // holy shit, a goto OwO
            }
        }
    }

    found:
    out << res * remaining_sum(tables[winner]);

    in.close();
    out.close();
}