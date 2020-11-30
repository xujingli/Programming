//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

const int maxn = 100;

bool judge(char num[],int len){
	bool point = false; 
	bool n = false;		//�ж���.��֮ǰ�Ƿ������� 
	for(int i=0;i<len;i++){
		if(num[i]!='-' && num[i]!='.'&&(num[i]>'9' || num[i]<'0'))
			return false;	//�����˷����ֵ���������
		if(num[i] == '-' && i!=0)
			return false;	//���˵�һ��λ�ã�����λ�ó���'-' 
		if(num[i] == '.' && len-1-i >2)	//С����󳤶ȴ���2 
			return false;
		if(num[i]=='.' && point == false){
			if(n == false)	//С����ǰ��û������
				return false; 
			point = true;
			continue;					//��һ�γ���'.' 
		}
		if(num[i] == '.' && point == true)		//�ڶ��γ��� '.'
			return false;
			
		if(num[i] <='9' && num[i]>='0'){
			n = true;
			continue;
		}
		
	}
	return true;
}

double sTod(char num[],int len){
	double m = 0,n=0;	//�������֣�С������ 
	bool isneg = false;
	bool before = true;	//��С����ǰ�� 
	double t;			//���� 
	for(int i=0;i<len;i++){
		if(num[i] == '-' && i==0){
			isneg = true;		//����
			continue;
		}
			
		if(num[i] == '.'){
			before = false;
			t = 0.1;
			continue;
		}
		if(before == true){
			m = m*10+(num[i]-'0');
		}
		if(before == false){
			n = n + (num[i]-'0') * t;
			t /= 10;
		}
	}
	if(isneg == true)
		return (-1)*(m+n);
	else
		return m+n;
}

int main(){
	int n;
	scanf("%d",&n);
		
	int count = 0;
	double total = 0;
	for(int i=0;i<n;i++){
		char num[maxn];
		scanf("%s",num);
		int len = strlen(num);
		
		if(judge(num,len) == false){
			printf("ERROR: %s is not a legal number\n",num);
		} else{
			double n = sTod(num,len);
			if(n < -1000 || n > 1000)
				printf("ERROR: %s is not a legal number\n",num);
			else{
				count++;
				total += sTod(num,len);
			}
		}
	} 
	
	if(count == 0){
		printf("The average of 0 numbers is Undefined\n");
	} else if(count == 1){
		printf("The average of 1 numbers is %.2f",total);
	} else
		printf("The average of %d numbers is %.2f",count,total/count);

	return 0;
}

