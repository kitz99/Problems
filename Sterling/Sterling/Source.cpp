#include <fstream>
#define MOD 98999
#define SIZE 201

std::ifstream fin ("stirling.in");
std::ofstream fout ("stirling.out");

int n, m, s[SIZE][SIZE], S[SIZE][SIZE];
int t;

int main(){
	s[1][1] = 1;
	for(int i = 2; i < SIZE; i++)
		for(int j = 1; j <= i; j++)
			s[i][j] = (s[i-1][j-1] - (i - 1) * s[i-1][j]) % MOD;
	S[1][1] = 1;
	for(int i = 2; i < SIZE; i++)
		for(int j = 1; j <= i; j++)
			S[i][j] = (S[i-1][j-1] + j * S[i-1][j]) % MOD;

	fin >> t;
	while( t != 0){
		int x, n, m;
		fin >> x >> n >> m;
		if(x == 1) fout << s[n][m] << "\n";
		else fout << S[n][m] << "\n";
		t--;
	}
	fout.close();
	return 0;
}