//日期：2018/ 时间：
//内部自动有序且不包含重复元素的容器 
#include <stdio.h>
#include <stdlib.h>
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
	for(it=st.begin();it!=st.end();it++)
		printf("%d ",*it);
	
	it = st.find(2);
	printf("\n%d",*it);
	


	return 0;
}
