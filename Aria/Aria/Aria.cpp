# include <cstdio>
# include <cmath>
# include <fstream>
# include <iomanip>
# define x first
# define y second
std::ifstream f ("aria.in");
std::ofstream g ("aria.out");
std::pair<double, double> V[100005];
int N;
double sol;
int main () 
{
    f >> N;
    for (int i = 0; i < N; ++i)
        f >> V[i].x >> V[i].y; 
    V[N] = V[0];
    for (int i = 0; i < N; ++i)
        sol += (V[i].x * V[i + 1].y - V[i + 1].x * V[i].y);
     g<<std::fixed<<std::setprecision(7)<<fabs(sol*0.5);
}