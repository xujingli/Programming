//���ڣ�2018/6/15 ʱ�䣺16:55-17:25
#include <stdio.h>
#include <stdlib.h>
typedef long long LL;
const int maxn = 1000005;
LL s1[maxn],s2[maxn],s[maxn];

//#define p1
#define p2

#ifdef p2
int main(){
	int n1,n2;
	
	scanf("%d",&n1);
	for(int i=1;i<=n1;i++)
		scanf("%lld",&s1[i]); 
		
	scanf("%d",&n2);
	for(int i=1;i<=n2;i++)
		scanf("%lld",&s2[i]);
		
	int i=1,j=1;
	int len=1;				//s�д�źϲ����������len+1Ϊ�䳤�� 
	while(i<=n1 && j<=n2){
		if(s1[i]>s2[j]){
			s[len++]=s2[j];
			j++;
		}
		else{
			s[len++]=s1[i];
			i++;
		}
	}
	int mid = (n1+n2)%2==1 ? (n1+n2)/2+1 : (n1+n2)/2;
	
	printf("%d",s[mid]); 
	
	return 0;
}

#endif

#ifdef p1
int main(){
	int n1,n2;
	
	scanf("%d",&n1);
	for(int i=1;i<=n1;i++)
		scanf("%lld",&s1[i]); 
		
	scanf("%d",&n2);
	for(int i=1;i<=n2;i++)
		scanf("%lld",&s2[i]);
	
	int i=1,j=1;
	int mid = (n1+n2)%2==1 ? (n1+n2)/2+1 : (n1+n2)/2;		//i,j�ֱ�Ϊָ��s1,s2��ָ�롣mid������ָ��һ��Ҫ��󻬶��ľ���
	
	int count=0;
	LL median;
	while(i<=n1 && j<=n2){
		if(s1[i]>=s2[j]){		//�����ַ���������ָ���Ӧ��������Ƚϣ����ֽ�С�Ͱ���ѡΪ��ʱ���м��� 
			median=s2[j];		//�������������յ��м��� 
			count++;			//������һ 
			j++;
		}else{
			median=s1[i];
			count++;
			i++;
		}
		if(count == mid){		//�����ﵽmid�󣬼�������м��������ҳ��򷵻ء� 
			printf("%d",median);
			return 0;
		}
	} 
	
	while(i<=n1){
		median=s1[i];
		count++;
		i++;
		if(count == mid){		//�����ﵽmid�󣬼�������м��������ҳ��򷵻ء� 
			printf("%d",median);
			return 0;
		}
	}

	while(j<=n2){
		median=s2[j];
		count++;
		j++;
		if(count == mid){		//�����ﵽmid�󣬼�������м��������ҳ��򷵻ء� 
			printf("%d",median);
			return 0;
		}
	}

	return 0;
}
#endif

