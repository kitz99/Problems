#include <fstream>
std::ifstream f ("rmq.in");
std::ofstream g ("rmq.out");
int v[100005], N, M, rmq[20][100005];
int lg[100005];
int main()
{
	f >> N >> M;
	for(int i = 1; i <= N; i++)
		f >> v[i];

    for (int i = 2; i <= N;i++)
        lg[i] = lg[i/2] + 1;
 
    for (int i=1;i<=N;i++)
        rmq[0][i] = v[i];
 
    for (int i = 1; (1 << i) <= N; i++)
        for (int j = 1; j <= N - (1 << i) + 1; j++){
			int l = 1 << (i - 1);
			rmq[i][j] = std::min( rmq[i-1][j] , rmq[i-1][j+l] );
        }
    int x, y, diff, sh;
    for (int i=1;i<=M;i++){
        f >> x >> y;
        diff = y - x + 1;
        int l = lg[diff];
        sh = diff - (1<<l);
        g<<std::min(rmq[l][x],rmq[l][x+sh]) << "\n"; 
	}
	return 0;
}