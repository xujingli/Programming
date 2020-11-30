/*
//NOTICE: 这个程序是有问题的！n的范围为1 - 10。 
*/

#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 0x7fffffff;
int price[11] = {0,1,5,8,9,10,17,17,20,24,30};

//************ 钢条切割问题************** 
//#define CUT_ROD					*****
//#define MEMOIZATION_CUT_ROD		*****
//#define BOTTOM_UP_CUT_ROD			*****
//#define EXTENDED_BOTTOM_UP_CUT_ROD*****
//***************************************

#define MATRIX_MULTIPLY

#ifdef CUT_ROD

int cut_rod(int n){
	if(n == 0)	return 0;
	int q = -1 *INF;
	for(int i=1;i<=n;++i){
		q = max(q, price[i]+ cut_rod(n-i));
	}
	return q;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d",cut_rod(n));
	
	return 0;
}
#endif

#ifdef MEMOIZATION_CUT_ROD

int memorization_cut_rod_aux(int n, int r[]){
	int q;
	if(r[n] >= 0)	//如果记录中有，直接返回 
		return r[n];
	if(n==0)
		q = 0;
	else{
		q = -1 * INF;
		for(int i=1;i<=n;i++){
			q = max(q , price[i] + memorization_cut_rod_aux(n-i,r));
		}
	}
	r[n] = q;	//记录状态 
	return q;
}

int memoization_cut_rod(int n){
	int r[n+1];
	for(int i=0;i<=n;i++){
		r[i] = -1 * INF;
	}
	return memorization_cut_rod_aux(n,r);
}


int main(){
	int n;
	scanf("%d", &n);
	printf("%d",memoization_cut_rod(n));
	
	return 0;
}
#endif

#ifdef BOTTOM_UP_CUT_ROD

int bottom_up_cut_rod(int n){
	int r[n+1];
	r[0] = 0;
	for(int j=1;j<=n;j++){
		int q = -1 * INF;
		for(int i=1;i<=j;i++){
			q = max(q, price[i] + r[j-i]);
		}
		r[j] = q;
	}
	return r[n];
} 

int main(){
	int n;
	scanf("%d", &n);
	printf("%d",bottom_up_cut_rod(n));
	
	return 0;
}

#endif

#ifdef EXTENDED_BOTTOM_UP_CUT_ROD

int r[40],s[40];

void extended_bottom_up_cut_rod(int n){
	r[0] = 0;
	for(int j=1;j<=n;j++){
		int q = -1 * INF;
		for(int i=1;i<=j;i++){
			if(q < (price[i] + r[j-i])){
				q = price[i] + r[j-i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
} 

void print_cut_rod_solution(int n){
	extended_bottom_up_cut_rod(n);
	
	while(n > 0){
		printf("%d ",s[n]);
		n -= s[n];
	}
}

int main(){
	for(int i=1;i<11;i++){
		printf("i = %d, 方案: ",i);
		print_cut_rod_solution(i);
		printf(", 最大收益: %d",r[i]);
		printf("\n");
	}
	
	return 0;
}

#endif

#ifdef MATRIX_MULTIPLY
void matrix_multiply(vector<vector<int> > A, vector<vector<int> > B){
	if(A[0].size() != B.size()){ //A.columns != B.rows
		return;
	}
	else{
		vector<vector<int> > C(A.size(),vector<int>(B[0].size()));
		for(int i=0;i<A.size();i++){
			for(int j=0;j<B[0].size();j++){
				C[i][j] = 0;
				for(int k=0;k<A[0].size();k++){
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		
		for(int i=0;i<C.size();i++){
			for(int j=0;j<C[0].size();j++){
				printf(" %d",C[i][j]);
			}
			printf("\n");
		}
	}
}

int main(){
	
	vector<vector<int> > A(2,vector<int>(5)); //二维数组的行数为2，列数为5
	vector<vector<int> > B(5,vector<int>(3)); //二维数组的行数为5，列数为3
	
	int num1[2][5] = {1,2,3,4,5,
					6,7,8,9,10};
	int num2[5][3] = {1,2,3,
					4,5,6,
					7,8,9,
					10,11,12,
					13,14,15};
	for(int i=0;i<2;i++){
		for(int j=0;j<5;j++){
			A[i][j] = num1[i][j];
		}
	}
	
	for(int i=0;i<5;i++){
		for(int j=0;j<3;j++){
			B[i][j] = num2[i][j];
		}
	}
	
	matrix_multiply(A,B);
	
	return 0;
}
#endif


