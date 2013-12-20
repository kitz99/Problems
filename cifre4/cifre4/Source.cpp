#include <fstream>
std::ifstream fin ("cifre4.in");
std::ofstream fout ("cifre4.out");
long long N, P, T; 
bool valid(long long X){
	while(X != 0){
		int c = X%10;
		if(c!=2 && c!=5 && c!=3 && c!=7) return false;
		X /= 10;
	}
	return true;
}
int main(){
	fin >> T;
	for(int i = 1; i <= T; i++){
		fin >> N >> P;
		long long X = -1; 
		bool ok = false;
		for(long long Q = 0; Q <= 50000000; Q++){
			X = P * Q + N;
			if(valid(X)) {
				fout << X << "\n";
				ok = true;
				break;
			}
		}
		if(ok == false) fout << "-1\n";
	}
	fout.close();
	return 0;
}