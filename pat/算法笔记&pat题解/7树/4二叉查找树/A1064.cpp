//���ڣ�2018/ ʱ�䣺
//BST������������� ���� ��С���������� 
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 1010;

//nΪ�ڵ�����number���ڴ�Žڵ�Ȩֵ��CBT���ڴ����ȫ������
//index��С����ö��number���� 
int n,number[maxn],CBT[maxn],index=0;

void inOrder(int root){
	if(root > n)	return;
	inOrder(root * 2);		//���������ݹ�
	CBT[root] = number[index++];	//���ڵ㴦��ֵnumber[index]���������=����������� 
	inOrder(root * 2 + 1); 
} 

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&number[i]);
	}
	sort(number,number+n);		//��С�������� ���õ�BST��������Ľ�� 
	
	inOrder(1);					//1��λΪ���ڵ�
	for(int i=1;i<=n;i++){
		printf("%d",CBT[i]);
		if(i<n) printf(" ");
	} 

	return 0;
}

