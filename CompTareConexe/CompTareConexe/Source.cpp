#include <fstream>
#include <vector>
#define SIZE 25000
std::ifstream file_in ("ctc.in");
std::ofstream file_out ("ctc.out");
int num_nodes, num_edges, **adj, x, y;
int nr,viz[SIZE], c[SIZE];
std::vector<int> a[SIZE];

void dfs(int p)
{
	int q;
	viz[p]=1; c[p] = nr;
	for(unsigned int i=0; i<a[p].size(); i++) 
	{
		q=a[p][i];
	    if(!viz[q]) dfs(q);
	}
}

int main()
{
	file_in >> num_nodes >> num_edges;
	adj = new int*[num_nodes + 1];
    for (int i = 0; i < num_nodes + 1; ++i)
		adj[i] = new int[num_nodes + 1];

	for(int i = 1; i <= num_edges; i++) 
	{
		file_in >> x >> y;
		adj[x][y] = 1;
	}
	for(int k = 1; k <= num_nodes; k++)
		for(int i = 1; i <= num_nodes;i++)
			for(int j = 1;j <= num_nodes; j++) 
				adj[i][j] = (adj[i][j] || (adj[i][k] && adj[k][j]));
	
	for(int i = 1; i <= num_nodes; i++)
		for(int j = 1; j <= num_nodes; j++)
			if(adj[i][j] && adj[j][i]) {a[i].push_back(j); a[j].push_back(i);}

	for(int i = 1; i <= num_nodes; ++i ) 
		if(!viz[i]) {nr++; dfs(i);}

	file_out << nr << "\n";
	for(int cmp=1;cmp<=nr;cmp++)
	{
		for(int i=1;i<=num_nodes;i++) 
			if(c[i] == cmp) file_out << i << " ";
		file_out << "\n";
    }
	return 0;
}