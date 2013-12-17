#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
std::ifstream fin("elmaj.in");
std::ofstream fout("elmaj.out");
int n;
int a[1000005];
int nr;
int sortMajority() {
    std::sort(a, a+n);
	int i = 0, j = 0;
    while (i < n) {
          j = i;
          while (j < n && a[j + 1] == a[i])
              j++;
		  int k = j - i + 1;
          if ( k > n/2){ 
			  nr = k;
              return a[i];
		  }
          i = j + 1;
    }
    return -1;
}
int main(){
	fin >> n;
	for(int i = 0; i < n; i++)
		fin >> a[i];
	int p = sortMajority();
	fout << p << " " << nr;
	return 0;
}