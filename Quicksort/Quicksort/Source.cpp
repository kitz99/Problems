#include <fstream>
#include <cstdlib>
#include <ctime>
std::ifstream fin ("algsort.in");
std::ofstream fout ("algsort.out");
int n, *v;
void quick(int left, int right){
	if(left >= right) 
		return;
	int m = v[left + rand() % (right - left)], l = left, r = right;
	while(l < r){
		while(v[l] < m) l++;

        while(v[r] > m) r--;

        if(l <= r){
           int aux = v[l];
           v[l] = v[r];
           v[r] = aux;
           l++; r--;
        }
    }
	quick(left, r);
    quick(l, right);
}
int main() {
	fin >> n;
	v = new int[n];
	for(int i = 0; i < n; i++)
		fin >> v[i];
	srand ((int)time(NULL));
	quick(0, n-1);
	for(int i = 0; i < n; i++)
		fout << v[i] << " ";
	fout << "\n";
	return 0;
}