//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

const int maxn = 1010;
int arr[maxn];		//保存题目中给的出栈顺序
stack<int> st;		//定义栈st,用以存放int型元素 

int main(){
	int m,n,T;
	scanf("%d%d%d",&m,&n,&T);
	while(T--){		//循环执行T次 
		while(!st.empty())
			st.pop();		//清空栈
			
		for(int i=1;i<=n;i++) {	//读入数据 
			scanf("%d",&arr[i]);
		}
		int current = 1;	//指向出栈序列中的待出栈元素
		bool flag = true;
		
		for(int i=1;i<=n;i++){
			st.push(i);		//把i压入堆栈
			if(st.size() > m){	//如果此时栈中元素个数大于容器m,则序列非法 
				flag = false;
				break; 
			}
			while(!st.empty() && st.top() == arr[current]){
				st.pop();	//反复 出栈并令current++
				current++; 
			} 
		} 
		
		if(st.empty() == true && flag == true){
			printf("YES\n");		//栈空且falg==true时表明合法 
		}else{
			printf("NO\n");
		} 
	}

	return 0;
}

