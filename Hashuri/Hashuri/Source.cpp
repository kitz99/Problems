#include <cstdio>
#include <map>
//std::ifstream fin ("hashuri.in");
//std::ofstream fout ("hashuri.out");
int n, ind;
std::map <int, int> H;

int main(){
	FILE *fin = fopen("hashuri.in", "r");
	FILE *fout = fopen("hashuri.out", "w");
	//fin >> n; 
	fscanf(fin, "%d", &n);
	int op, val;
	for(int i = 0; i < n; i++){
		fscanf(fin, "%d %d", &op, &val); //fin >> op >> val;
		if(op == 1){
			if(H.find(val) == H.end()) H[val] = i;
		}
		if(op == 2){
			H.erase(val);
		}
		if(op == 3){
			fprintf(fout, "%d \n", (H.find(val) != H.end()) ); //fout << () << "\n";
		}
	}

	return 0;
}