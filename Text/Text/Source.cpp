#include <fstream>
#include <ctype.h>
#include <cstring>

std::ifstream fin("text.in");
std::ofstream fout("text.out");
char c;
int len, cuv, k;
int main(){
	while (!fin.eof()){
		fin.get(c);
		k = 0;
		while (isalpha(c)){
			k = 1;
			len++;
			fin.get(c);
		}
		if (k == 1)
			cuv++;
	}
	fout << len / cuv;
	return 0;
}
