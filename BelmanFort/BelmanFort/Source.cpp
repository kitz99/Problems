#include<fstream>
#include<vector>
#include<queue>
#define inf 5000000
#define Mmax 50001
#define RI register int i
std::ifstream file_in ( "bellmanford.in" );
std::ofstream file_out ( "bellmanford.out" );
struct NOD { int x, c; };
std::vector < NOD > a[Mmax];
std::vector < int > d(Mmax,inf) ;
std::queue < int > q;
int n, m, x, y, z, nod, cost, aux;
void dijkstra()
{
    q.push(1);
    d[1]=0;
    while(!q.empty())
    {
        aux=q.front();q.pop();
        for(unsigned int i = 0; i < a[aux].size(); ++i)
        {
            cost=a[aux][i].c; nod=a[aux][i].x;
            if(d[nod]>d[aux]+cost) 
                {d[nod]=d[aux]+cost; q.push(nod);}
        }
    }
}
int main()
{
    file_in>>n>>m;
    NOD aux1;
    for(RI = 1; i <= m; ++i) 
    {
        file_in >> x>> y >> z;
        aux1.x = y;
        aux1.c = z;
        a[x].push_back(aux1);
    }
    dijkstra();
    for(RI = 1; i < n; ++i)
        if( d[i+1] != inf ) 
            file_out << d[i+1] << " "; 
        else file_out << "0 ";
    file_out << "\n";
    return 0;
}