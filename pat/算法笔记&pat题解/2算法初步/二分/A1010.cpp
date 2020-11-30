//���ڣ�2018/6/13 ʱ�䣺16:35-15:15 19/25
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm> 
using namespace std;

//#define p1
#define p2
//p2ʹ�ö��ַ� 

/*******************************p2*********************************************/
#ifdef p2

typedef long long LL;
LL Map[256];			//0~9/a~z��0~35��Ӧ
LL inf = (1LL << 63) - 1;		//long long�����ֵ��2^63-1,ע�������

void init(){
	for(char c='0';c <= '9';c++){
		Map[c] = c - '0';		//��'0'~'9'ӳ�䵽0~9 
	}
	for(char c='a';c <= 'z';c++){
		Map[c] = c - 'a' +10;	//��'a'~'z'ӳ�䵽10~35 
	}
}

LL convertNum10(char a[],LL radix,LL t){	//��aת��Ϊʮ���ƣ�tΪ�Ͻ� 
	LL ans=0;
	int len = strlen(a);
	for(int i=0;i<len;i++){
		ans = ans * radix + Map[a[i]];		//����ת�� 
		if(ans < 0 || ans > t)	return -1;  //����򳬹�N1��ʮ���� 
	} 
	return ans;
}

int cmp(char N2[],LL radix,LL t){			//N2��ʮ������t�Ƚ� 
	int len = strlen(N2);
	LL num = convertNum10(N2, radix ,t);	//��N2ת��Ϊʮ����
	if(num < 0)	return 1;				//������϶���N2 > t 
	if(t > num) return -1;				//t�ϴ󣬷���-1
	else if(t == num)	return 0;		//��ȣ�����0
	else	return 1; 
}

int findLargestDigit(char N2[]){		//�������λ
	int ans = -1,len = strlen(N2);
	for(int i=0;i<len;i++){
		if(Map[N2[i]] > ans){
			ans = Map[N2[i]];
		}
	} 
	return ans+1;						//������λΪans,˵���������ĵ�����ans+1 
}

int binarySearch(char N2[],LL left,LL right,LL t){	//�������N2�Ľ��� 
	LL mid;
	while(left < right){
		mid = (left + right)/2;
		int flag = cmp(N2,mid,t);		//�ж�N2ת��Ϊʮ���ƺ���t�Ƚ�
		if(flag == 0) return mid;		//�ҵ��⣬����mid
		else if(flag == -1) left = mid+1;		//�����������������
		else	right = mid-1;			//����������������� 
	}
	return -1;
}

char N1[15],N2[15],temp[15];
int tag,radix;

int main(){
	init();
	scanf("%s %s %d %d",N1,N2,&tag,&radix);
	if(tag == 2){
		strcpy(temp,N1);
		strcpy(N1,N2);
		strcpy(N2,temp);
	} 
	LL t = convertNum10(N1,radix,inf);		//��N1��radix����ת��Ϊʮ����
	LL low = findLargestDigit(N2);			//�ҵ�N2����λ����λ��һ�����ɶ����½�
	LL high = max(low,t) + 1;				//�Ͻ� 
	LL ans = binarySearch(N2, low, high, t);	//����
	if(ans == -1)	printf("Impossible\n");
	else	printf("%lld\n",ans); 
	
	
	return 0;
} 

#endif
/****************************************************************************/

/*******************************p1*********************************************/
#ifdef p1
long long CtoD(char n[],int radix){	//��radix������n[]ת��Ϊʮ���Ʒ��� 
	int k=strlen(n);
	//printf("%d\n",k);
	long long dnum=0;		//ת�����ʮ������
	long long r=1; 
	for(int i=k-1;i>=0;i--){
		if(n[i]>='0' && n[i]<='9')
			dnum+=r*(n[i]-'0');
		else if(n[i]>='a' && n[i]<='z')
			dnum+=r*(n[i]-'a'+10);
		r= r*radix;
	}
	return dnum;
}

int main(){
	char n1[15],n2[15];
	int tag,radix;
	long long dnum1,dnum2;		//ת��Ϊʮ�������洢,���ɴ�36^10,�����long long 
	
	scanf("%s",n1);
	getchar();		//��ȡ�м�Ŀո� 
	scanf("%s",n2); 
	getchar();
	scanf("%d",&tag);
	scanf("%d",&radix);
	
	if(tag == 2){
		char temp[15];
		strcpy(temp,n1);
		strcpy(n1,n2);
		strcpy(n2,temp);
	}
	
	int flag=0;			//�ж��Ƿ���� 
	dnum1=CtoD(n1,radix);		//���ַ�������radix�������֣�ת��Ϊʮ������ 
	
	int r=2; 
	//����n2����ַ�����ȷ��һ�¿�����С���� 
	for(int i=0;i<strlen(n2);i++){
		if(n2[i]>='0' && n2[i]<='9'){		//���� 
			r = (r > (n2[i]-'0'+1) ? r : (n2[i]-'0'+1));
		}
		else if(n2[i]>='a' && n2[i]<='z'){		//���� 
			r = (r > (n2[i]-'a'+10+1) ? r : (n2[i]-'a'+10+1));
		}			
	}		//�Ѿ�ȷ������С�Ŀ��ܽ��� 
/**/	
	for(int i=r;i<=36;i++){
		dnum2=CtoD(n2,i);
		//printf("%s %d %lld\n",n2,r,dnum2);
		if(dnum2 == dnum1){
			flag=1;
			printf("%d",i);
			break;
		}
		if(dnum2 > dnum1)
			break;
	}
	
	if(flag == 0)
		printf("Impossible"); 

	return 0;
}

#endif
/****************************************************************************/

