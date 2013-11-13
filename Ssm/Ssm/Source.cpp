#include <fstream>
#
std::ifstream f ("ssm.in");
std::ofstream g ("ssm.out");
int N, Smax = -int(2e9), S, start, stop, sum, j;
int main()
{
	f >> N;
	for (int i = 1; i <= N; i++){
		f >> S;
	    if(sum < 0) {sum = S; j = i;} 
		else sum += S;
		if(sum > Smax) {Smax = sum; start = j; stop = i;}
	}
	g << Smax << " " << start << " " << stop;
	return 0;
}