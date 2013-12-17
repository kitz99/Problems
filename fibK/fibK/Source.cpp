#include <fstream>
#define MOD 666013
std::ifstream fin ("kfib.in");
std::ofstream fout ("kfib.out");
int n, A[3][3], B[3][3], aux[3][3];

void mult(int a[3][3],int b[3][3])
{
    for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			aux[i][j] = 0;

      for(int i=1;i<=2;i++)
          for(int j=1;j<=2;j++)
             for(int k=1;k<=2;k++)
                 aux[i][j] = ((aux[i][j] + 1LL * a[i][k] * b[k][j]) % MOD);

	for(int i = 0; i < 3; i ++)
		for(int j = 0; j < 3; j ++)
			a[i][j] = aux[i][j];
}

void lgPow(int k){
	B[1][1] = A[1][1]; B[1][2] = A[1][2];
	B[2][1] = A[2][1]; B[2][2] = A[2][2];

	while(k)
    {
        if(k%2)
        {
            mult(B, A);
            k--;
        }
        mult(A, A);
        k/=2;
    }
 
}
int main(){
	fin >> n;
	A[1][2] = A[2][2] = A [2][1] = 1;
	lgPow(n-2);
	fout << B[2][2] << "\n";
	return 0;
}