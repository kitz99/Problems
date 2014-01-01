#include <fstream>
std::ifstream fin("cmmdc.in");
std::ofstream fout("cmmdc.out");
int cmmdc(long long a, long long b) {
	while (a != b) {
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	if (a == 1) return 0;
	return a;
}
int main(){
	long long a, b;
	fin >> a >> b;
	fout << cmmdc(a, b);
	fin.close();
	fout.close();
	return 0;
}