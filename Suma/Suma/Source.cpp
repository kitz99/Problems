#include <fstream>
std::ifstream fin("suma.in");
std::ofstream fout("suma.out");
unsigned long long n, S;
int p;
int main(){
	fin >> n >> p;
	unsigned long long s1, s2, s3;
	//n = n % p;
	s1 = (n * (n - 1)) % p;
	s2 = (n + 1) % p;
	s3 = (s1 * s2) % p;
	S = s3 / 3; 
	S = S % p;
	fout << S << "\n";
	return 0;
}