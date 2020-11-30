//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

const int maxn = 1010;
int arr[maxn];		//������Ŀ�и��ĳ�ջ˳��
stack<int> st;		//����ջst,���Դ��int��Ԫ�� 

int main(){
	int m,n,T;
	scanf("%d%d%d",&m,&n,&T);
	while(T--){		//ѭ��ִ��T�� 
		while(!st.empty())
			st.pop();		//���ջ
			
		for(int i=1;i<=n;i++) {	//�������� 
			scanf("%d",&arr[i]);
		}
		int current = 1;	//ָ���ջ�����еĴ���ջԪ��
		bool flag = true;
		
		for(int i=1;i<=n;i++){
			st.push(i);		//��iѹ���ջ
			if(st.size() > m){	//�����ʱջ��Ԫ�ظ�����������m,�����зǷ� 
				flag = false;
				break; 
			}
			while(!st.empty() && st.top() == arr[current]){
				st.pop();	//���� ��ջ����current++
				current++; 
			} 
		} 
		
		if(st.empty() == true && flag == true){
			printf("YES\n");		//ջ����falg==trueʱ�����Ϸ� 
		}else{
			printf("NO\n");
		} 
	}

	return 0;
}

