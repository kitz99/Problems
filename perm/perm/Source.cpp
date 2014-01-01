#include <fstream>
#include <algorithm>
std::ifstream fin ( "permut.in" );
std::ofstream fout ( "permut.out" );
long long n;
long long a[100010], b[100010];
int main(){
	fin >> n;
	for (int i = 0; i < n; i++)
		fin >> a[i];
	for (int i = 0; i < n; i++)
		fin >> b[i];
	std::sort( a, a + n );
	std::sort( b, b + n );
	long long s = 0;
	for (int i = 0; i < n; i++)
		s += a[i] * b[i];
	fout << s << "\n";
	fout.close();
	fin.close();
	return 0;
} 
