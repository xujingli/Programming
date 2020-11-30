/*
题意：

考察点：
思路：
易错点：
*/
#include <stdlib.h>
#include <stdio.h>
#include <set>
using namespace std;

int main(){
	set<int> st;
	st.insert(3);
	st.insert(4);
	st.insert(5);
	st.insert(2);
	
	st.erase(5);
	set<int>::iterator it;
	for(it=st.begin();it!=st.end();it++){
		printf("%d ",*it);
	}
	if = st.find(2);
	printf("\n%d",*it);

	return 0;
}

