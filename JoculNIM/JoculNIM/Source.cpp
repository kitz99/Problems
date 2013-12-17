#include <fstream>
std::ifstream fin ("nim.in");
std::ofstream fout ("nim.out");
int t, n, x;
int main(){
	fin >> t;
	for(int i = 0; i < t; i++){
		fin >> n;
		int s = 0;
		for(int j = 0; j < n; j ++){
			fin >> x;
			s = s ^ x;
		}

	    if(s != 0) fout << "DA\n";
		else fout << "NU\n";
	}
	return 0;
}