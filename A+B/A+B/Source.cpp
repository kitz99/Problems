#include <fstream>
std::ifstream fin("adunare.in");
std::ofstream fout("adunare.out");
int main(){
	int a, b;
	fin >> a >> b;
	fout << a + b << "\n";
	fin.close();
	fout.close();
	return 0;
}