#include <fstream>
#include <list>

std::ifstream fin ("submultimi.in");
std::ofstream fout ("submultimi.out");

std:: list<int> V;
int n;
void submultimi(std::list <int> l, int n){
	if(!l.empty()){
		std:: list<int>::iterator it;
        for(it = l.begin(); it != l.end(); ++it)
			fout << *it << " ";
		fout << "\n";
	}
	int aux = 1;
	if(!l.empty()){
            aux = l.back() + 1;
        }
        for(int i = aux; i <= n; i++){
            l.push_back(i); 
            submultimi(l, n);
			l.remove(l.back());
        }
}
int main(){
	fin >> n;
	submultimi(V, n);
	return 0;
}
