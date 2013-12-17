#include <fstream>
#include <vector>
#define SIZE 100005
std::ifstream fin("bfs.in");
std::ofstream fout("bfs.out");
int N, M, L, Start;
std::vector <int> A[SIZE];
int G[SIZE], S[SIZE], Cost[SIZE];
void BFS(int nod)
{
    int i, j;
    for(int i = 0; i < SIZE; i++) 
		Cost[i] = -1;
    L = 1;
    Cost[nod] = 0;
    S[L] = nod;
    for (i = 1; i <= L; i++)
        for (j = 0; j < G[S[i]]; j++)  
            if (Cost[A[S[i]][j]] == -1)
            {
                S[++L] = A[S[i]][j];
                Cost[S[L]] = Cost[S[i]] + 1;
            }
}   
int main(){
	fin >> N >> M >> Start;
	for (int i = 1; i <= M; i++) 
    {
		int x, y;
        fin >> x >> y;
        A[x].push_back(y);
    }

	for (int i = 1; i <= N; i++) 
        G[i] = A[i].size();
 
    BFS(Start);
 
    for (int i = 1; i <= N; i++) 
        fout << Cost[i] << " ";
    fout << "\n";
	return 0;
}