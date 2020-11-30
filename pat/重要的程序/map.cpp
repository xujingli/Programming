/*
题意：

考察点：
思路：
易错点：
*/
#include <stdlib.h>
#include <stdio.h>
#include <map> 
using namespace std;

int main(){
	map<char,int> mp;
	mp['c'] = 5;
	mp['c'] = 10;
	mp['m'] = 20;
	mp['a'] = 30;
	mp['p'] = 40;
	
	map<char,int>::iterator it;
	it = mp.find('c');
	for(it=mp.begin();it!=mp.end();it++){
		printf("%c %d\n",it->first,it->second);
	}
	it = mp.find('a');
	
	return 0;
}

