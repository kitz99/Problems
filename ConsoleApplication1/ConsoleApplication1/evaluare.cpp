#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
ifstream f ("evaluare.in");
ofstream g ("evaluare.out");
stack <string> S;
char en[100005];
string enp[100005], fp[100005];
int k, k1; 
stack <int> st;
void prelucrare(){
	int j = 0;
	int nr;
	for(register int i = 0; i < strlen(en); i++){
		if(en[i] >= '0' && en[i] <= '9'){
			j = i;
			nr = 0;
			while(en[j] >= '0' && en[j] <= '9'){
				nr = nr*10 + (en[j] - 48);
				j++;
			}
			enp[k++] = to_string(nr);
			i = j;
		}
		if(en[i] == '+' || en[i] == '-' || en[i] == '*' || en[i] == '/' || en[i] == '(' || en[i] == ')')
			enp[k++] = en[i];
	}

}
inline bool isOperand(string s){
	if(s == "+" || s == "-" || s  == "*" || s == "/" || s == "(" || s == ")")
		return false;
	return true;
}
inline bool isOperator(string s){
	if(s == "+" || s == "-" || s  == "*" || s == "/")
		return true;
	return false;
}
inline int priority(string s){
	if(s == "+" || s == "-") return 1;
	if(s == "*" || s == "/") return 2;
	if(s == ")" || s == ")") return 0;
}
void formaPoloneza(){
	for(int i = 0; i < k; i++){
		if(isOperand(enp[i])){
			fp[k1++] = enp[i];
		}
		else 
			if( enp[i] == "(" )
				S.push(enp[i]);
			else 
				if (enp[i] == ")"){
					while( !S.empty() && isOperator(S.top() ) ){
						fp[k1++] = S.top();
						S.pop();
					}
					S.pop(); 
				}
				else 
					if(isOperator(enp[i])){
						while(!S.empty() && (priority(S.top()) >= priority(enp[i])) && isOperator(S.top())){
							fp[k1++] = S.top();
							S.pop();
						}
						S.push(enp[i]);
					}
	}
	while(!S.empty()){
		fp[k1++] = S.top();
		S.pop();
	}
}
int calc(int lt, int rt, string op){
	if(op == "+") return lt + rt;
	if(op == "-") return lt - rt;
	if(op == "*") return lt * rt;
	if(op == "/") return lt / rt;
}
int evaluare(){
	for(int i = 0; i < k1; i++){
		if(isOperand(fp[i])) {
			int n = stoi( fp[i] );
			cout<<n<<"\n";
			st.push(n);
		}
		else{
			int rt = st.top();
			st.pop();
			int lt = st.top();
			st.pop();
			int rez = calc(lt, rt, fp[i]);
			st.push(rez);
		}
	}
	return st.top();
}
int main()
{

	f>>en;
	cout << en << "\n";
	prelucrare();
	formaPoloneza();
	int rez = evaluare();
	g << rez << "\n";
	return 0;
}