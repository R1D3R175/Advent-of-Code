#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

void get_input(ifstream& in, vector<string>& v) {
	string line;
	
	getline(in, line);
	
	int i = 0;
	while(line[i] != '|') ++i;
	
	stringstream ss(line.substr(i+1, line.length()-i+1));

	while(ss >> line) v.push_back(line);
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	int c = 0;

	vector<string> signals;
	
	while(!in.eof()) {
		get_input(in, signals);
		
		for(string &s : signals) {
			if(s.length() == 2 || 
			    s.length() == 3 ||
			    s.length() == 4 ||
			    s.length() == 7) ++c;
		}
		
		signals.clear();
	}
	
	out << c;
	
	in.close();
	out.close();
}
