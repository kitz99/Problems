#include <cstdio>
#define max(a,b) (a > b) ? a : b

int A[400500], a, b;
inline void update(int nod, int st, int dr){
	if(st == dr){
		A[nod] = b;
		return;
	}
	int m = (st + dr) / 2;
	if(a <= m) {
		update(2*nod, st, m);
	}
	else{
		update(2*nod+1, m+1, dr);
	}
	A[nod] = max(A[2 * nod], A[2 * nod + 1]);
}
inline int query(int nod, int st, int dr){
	if(a <= st && b >= dr)
		return A[nod];
	int m = (st + dr) / 2;
	int max1 = -1, max2 = -1;
	if(a <= m) max1 = query(2*nod, st, m);
	if(b > m) max2 = query(2*nod + 1, m+1, dr);
	return max(max1, max2);
}
int main(){
	int n = 0, m = 0;
	FILE *fin, *fout;
	fin = fopen("arbint.in", "r");
	fout = fopen("arbint.out", "w");

	fscanf(fin, "%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		fscanf(fin, "%d", &b); 
		a = i; update(1, 1, n);
	}
	int op;
	for(register int i = 0; i < m; i++){
		fscanf(fin, "%d %d %d", &op, &a, &b); 
		if(op == 1) update(1, 1, n);
		else fprintf(fout, "%d\n", query(1, 1, n) ); 
	}
	return 0;
}