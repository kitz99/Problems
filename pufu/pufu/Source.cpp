#include <fstream>
#include <string>
std::ifstream fin ("pufu.in");
std::ofstream fout("pufu.out");
int main(){
	int T, N;
	fin >> T;
	std::string x;
	int ciocolata, sare, cascaval;
	for(int i = 1; i <= T; i++){
		ciocolata = sare = cascaval = 0;
		fin >> N;
		for(int j = 1; j <= N; j++){
			fin >> x;
			if(x.compare("ciocolata") == 0) ciocolata++;
			if(x.compare("cascaval") == 0) cascaval++;
			if(x.compare("sare") == 0) sare++;
		}
		fout << ciocolata << " " << cascaval << " " << sare << "\n";
	}
	fout.close();
	return 0;
}