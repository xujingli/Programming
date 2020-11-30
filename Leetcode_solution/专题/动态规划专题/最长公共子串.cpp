#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

int lengthofLCString(string X,string Y){
	int c[X.length()+1][Y.length()+1];
	memset(c,0,sizeof(c));	//初始化为0 
	int maxlen = 0;
	int maxindex = 0;
	for(int i=1;i<=X.length();i++){
		for(int j=1;j<=Y.length();j++){
			if(X[i-1] == Y[j-1]){
				c[i][j] = c[i-1][j-1] + 1;
				if(c[i][j] > maxlen){
					maxlen = c[i][j];
					maxindex = i;
				}
			}
		}
	}
	for(int i=maxindex-maxlen;i<maxindex;i++)
		printf("%c",X[i]);	//输出 
	printf("\n");
	return maxlen;
} 

int main(){
	string X = "acbacaa";
	string Y = "cabca";
	
	printf("%d\n",lengthofLCString(X,Y));
	
	return 0;
}
