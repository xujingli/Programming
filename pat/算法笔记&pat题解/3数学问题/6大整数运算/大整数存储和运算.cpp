//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���ַ������룬�ٷ�ת�Ŵ浽d[]�����С� 
struct bign{
	int d[1000];
	int len;
	bign(){			//�����캯������ʼ���ṹ�� 
		memset(d,0,sizeof(d));
		len = 0;
	}
}; 

void print(bign a){
	for(int i=a.len-1;i>=0;i--)
		printf("%d",a.d[i]);
}

//���ַ������룬�ٰ��ַ�����ŵ�bign�ṹ���� 
bign change(char str[]){	//������ת��Ϊbign 
	bign a;
	a.len= strlen(str);		//bign�ĳ��Ⱦ����ַ����ĳ���
	for(int i=0;i<a.len;i++){
		if(str[a.len-1-i]>='0' && str[a.len-1-i]<='9') 
			a.d[i] = str[a.len-1-i] - '0';
		else
			a.d[i] = str[a.len-1-i];
	} 
	return a;
}

//�Ƚ������ṹ�壺1)len��һ���Ļ���ֱ���жϣ�2)lenһ������d[len-1]��d[0]����һλ�������嶼��
int compare(bign a,bign b){	//�Ƚ�a��b��С��a����ȡ�aС�ֱ𷵻�1��0��-1 
	if(a.len > b.len)	return 1;	//a��
	else if(a.len < b.len) return -1;	//aС
	else{
		for(int i=a.len-1;i>=0;i--){
			if(a.d[i] > b.d[i])	return 1;	//ֻҪ��һλa����a��
			else if(a.d[i] < b.d[i]) return -1;
		}
		return 0;	//�������
	} 
} 

//�ӷ� ����Ҫָ�����ǣ�����д��Ҫȷ�����������ǷǸ����������һ��Ϊ����ҪתΪ���� 
bign add(bign a, bign b){
	//print(a); print(b);
	bign res;
	int carry=0;			//��λ��־ 
	for(int i=0;i<a.len || i<b.len ;i++){
		int temp = a.d[i] + b.d[i] +carry;
		carry = temp / 10;
		res.d[res.len++] = temp % 10;
	}
	if(carry != 0){			//�������λ�Ƿ��н�λ 
		res.d[res.len++] = carry;
	}
	return res;
}

//���� 
bign minus(bign a,bign b){		//a,bΪ�Ǹ����� ����a-b�ľ���ֵ�����������Լ��ж�
//����������������λ�ĸ�λ��һ������λ��10�ٽ��м������㡣
//���һ��Ҫע��������λ�����ж����0��Ҫ��ȥ���ǣ�����ҲҪ��֤���������һλ 
	bign res;
	if(compare(a,b)==-1){		//���a<b���򽻻�λ�� 
		bign temp = a;
		a = b;
		b = temp;
	} 
	
	for(int i=0;i<a.len || i<b.len;i++){
		if(a.d[i] < b.d[i]){
			a.d[i+1]--;
			a.d[i] += 10;
		}
		res.d[res.len++] = a.d[i] - b.d[i];
	} 
	while(res.len-1 >=1 && res.d[res.len-1] == 0)
		res.len--;			//while(res.len -1 >=1)�����ٱ���һλΪ���λ��ȥ����λ��0 
	return res;
}

//ȡbign��ĳλ��int��������ˣ������λ��ӣ����õĽ���ĸ�λ����Ϊ��λ�Ľ������λ������Ϊ��λ 
bign multi(bign a,int b){		//�߾��ȳ˷� 
	bign res;
	int carry = 0;
	for(int i=0;i<a.len;i++){
		int temp = a.d[i] * b + carry;
		res.d[res.len++] = temp%10;		//��λ��Ϊ��λ�Ľ�� 
		carry = temp/10;				//��λ������Ϊ�µĽ�λ 
	}
	while(carry != 0){					//�ͼӷ���һ�����˷��Ľ�λ���ܲ�ֹһλ�������while 
		res.d[res.len++] = carry % 10;
		carry /= 10; 
	}
	return res;
}

bign divide(bign a,int b,int& r){		//�߾��ȳ�����rΪ���� 
	bign res;
	res.len = a.len; 	//��������ÿһλ���̵�ÿһλ��һһ��Ӧ�ģ������������
	for(int i=a.len-1; i>=0;i--){	//�Ӹ�λ��ʼ 
		r = r * 10 + a.d[i];		//����һλ�����������������
		if(r < b)	res.d[i] = 0;
		else{						//���� 
			res.d[i] = r / b;		//�� 
			r %= b;					//��������� 
		} 
	} 
	
	//��ȥ����λ��0,ͬʱ���ٱ���һλ 
	while(res.len -1 >= 1 && res.d[res.len-1] == 0){
		res.len--;
	} 
	
	return res;
}

int main(){
	char str1[1000],str2[1000];
	scanf("%s%s",str1,str2);
	bign a = change(str1);
	bign b = change(str2);
	
	printf("a+b=");			//�ӷ� 
	print(add(a,b));
	printf("\n");

	printf("a-b=");
	print(minus(a,b));
	printf("\n");
	
	int m = 10;
	printf("a*10=");
	print(multi(a,m));
	printf("\n");
	
	printf("a/10=");
	int r=0;
	print(divide(a,m,r));
	printf("������������%d\n",r);
	
	return 0;
}

