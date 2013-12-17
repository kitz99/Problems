#include <fstream>
#include <cstring>
#define NMax 2000005
std::ifstream f ("strmatch.in"); 
std::ofstream g ("strmatch.out");
int M, N;
char A[NMax], B[NMax];
int pi[NMax], pos[1024];

void prefix()
{int i, q = 0;
 for (i = 2, pi[1] = 0; i <= M; ++i){
      while (q && A[q+1] != A[i]) 
		  q = pi[q];
      if (A[q+1] == A[i]) ++q; 
	  pi[i] = q;
    }
}
 
int main()
{int i, q = -1, n = 0;
 f >> A >> B;
 while((A[M] >= 'A' && A[M] <= 'Z') || (A[M] >= 'a' && A[M] <= 'z') 
            || (A[M] >= '0' && A[M] <= '9') ) ++M;
 while((B[N] >= 'A' && B[N] <= 'Z') || (B[N] >= 'a' && B[N] <= 'z')
            || (B[N] >= '0' && B[N] <= '9')) ++N;
 for (i = M; i > 0; --i) 
	 A[i] = A[i-1]; 
 for (i = N; i > 0; --i) 
	 B[i] = B[i-1]; 
 A[0] = ' '; B[0] = ' ';  
 prefix();
 for (i = 1; i <= N; ++i){
	 while (q && A[q+1] != B[i]) 
		 q = pi[q];
     if (A[q+1] == B[i]) 
		 ++q;
     if (q == M){
		 q = pi[M];
         ++n;
         if (n <= 1000) 
			 pos[n] = i-M;    
    }   
 }       
 g << n << "\n";
 for (i = 1; i <= std::min(n, 1000); ++i) g<<pos[i]<<" ";
 g<<"\n"; 
 return 0;
}