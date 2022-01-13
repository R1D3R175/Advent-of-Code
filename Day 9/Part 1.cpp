#pragma unroll
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    vector<vector<int>> m;

    // Input Parser
    while(!in.eof()) {
        string S;
        in >> S;

        vector<int> t;

        for(char &c : S) t.push_back(c-'0');

        m.push_back(t);
    }

    const int H = m.size();
    const int W = m[0].size();

    int c = 0;
    // Corners
    if(m[0][0] < m[0][1] && m[0][0] < m[1][0])                 c += 1 + m[0][0];
    if(m[0][W-1] < m[1][W-1] && m[0][W-1] < m[0][W-2])         c += 1 + m[0][W-1];
    if(m[H-1][0] < m[H-2][0] && m[H-1][0] < m[H-1][1])         c += 1 + m[H-1][0];
    if(m[H-1][W-1] < m[H-1][W-2] && m[H-1][W-1] < m[H-2][W-1]) c += 1 + m[H-1][W-1];

    // Up
    for(int i = 1; i < W-1; i++) {
        if(m[0][i] < m[0][i-1]      /* < */ && 
           m[0][i] < m[1][i]        /* v */ && 
           m[0][i] < m[0][i+1])     /* > */ c += 1 + m[0][i];

        if(m[H-1][i] < m[H-1][i-1]  /* < */ &&
           m[H-1][i] < m[H-2][i]    /* ^ */ &&
           m[H-1][i] < m[H-1][i+1]) /* > */ c += 1 + m[H-1][i];
    }

    
    for(int i = 1; i < H-1; i++) {
        // Right
        if(m[i][W-1] < m[i][W-2]    /* < */ &&
           m[i][W-1] < m[i-1][W-1]  /* ^ */ &&
           m[i][W-1] < m[i+1][W-1]) /* v */ c += 1 + m[i][W-1];

        // Left
        if(m[i][0] < m[i][1]        /* > */ &&
           m[i][0] < m[i-1][0]      /* ^ */ &&
           m[i][0] < m[i+1][0])     /* v */ c += 1 + m[i][0]; 

        for(int j = 1; j < W-1; j++) {
            // Insides
            if(m[i][j] < m[i-1][j]  /* ^ */ && 
               m[i][j] < m[i+1][j]  /* v */ && 
               m[i][j] < m[i][j-1]  /* < */ && 
               m[i][j] < m[i][j+1]) /* > */ c += 1 + m[i][j];
        }
    }

    out << c;

    in.close();
    out.close();
}