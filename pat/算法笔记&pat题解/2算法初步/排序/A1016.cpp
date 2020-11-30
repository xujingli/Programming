//���ڣ�2018/4/25 ʱ��10:05- 11:23	����˳����������򲿷�
//						11:23-14:14 15/25 ���˶�����ʹ𰸴���
//						14:14-14:31 Ѱ������δ�� 
//					4/29 11:00-11:42 AC
//������ѣ�ǰ��������ʱ�򣬻���40��������ͷ���������û��������Ѿ�ɥʧ������
/*
AC�ĵã�������Ϊ֮ǰ���ǲ���ȫ��count����if����У����Ҫ����ȥ��count���Ͳ����һ����
		���԰�count����ÿ��ѭ���ĺ��档ÿ�κ���һλ 
*/ 
/*
���⻨��4��Сʱ������ǰ���컨��40���ӣ��ܹ�����5��Сʱ����Ȼû�н��
�ܽ�ԭ��1.η�ѣ�������ô������Ŀ����ô���Ӿ�η�塣
			2.�����棬���������ʱ��Ͳ����棬д�����߰��㣬���ڵ����ҵ�û��˼·��ʱ����������һ��ֽ��������˷�ʱ��
			3.�ṹ�����򣬷���һ��С���� �������ַ�����Ƚϲ���ֱ����"==",Ӧ����strcmp(string1,string2)
			4. ��̹��ױ�����һ���ܼ򵥵Ķ�����Ҫ���Ǻó�ʱ�䣬�ټ����ô���ʵ�֣�Ҫ���ܳ�ʱ�䡣����������Ҫ��ϰ��
			5.���һ��Ҫע��ʱ�䣬�����Լ��ӿ��ٶȡ������������֣�˼ά�����й�
			6.�������ˣ��������������������������������� 
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct record{
	char name[21];
	char mon[3],day[3],hour[3],min[3],word[10];
	char dt[12];	//date and time.0 1 Ϊ�·ݣ�3 4Ϊ���� 6 7 ΪСʱ 9 10Ϊ���� 
}records[1005];

bool cmp(record a,record b){
	//if(a.name == b.name){		//������ģ�����ȥ�ɣ������̶ֳȣ��������ֵͼ����󣡣����������������������������������������˴��40���Ӵ��󣬻���Ϊ�Լ������߼�д���ˣ������㵽�׸�ʲô���������𣿾�������������󣿣�����������Ҫ���ʲô�أ�
 	if(strcmp(a.name,b.name)== 0 ){
		if(strcmp(a.day,b.day)==0){//��ͬ����
			if(strcmp(a.hour,b.hour)==0){
				return strcmp(a.min,b.min)<0;
			} else
				return strcmp(a.hour,b.hour)<0;	//����ʱ��˳���������� 
		}else
			return strcmp(a.day,b.day)<0;		//����˳���������� ����Ϊ��Ŀ���Ѿ������ˣ�ÿ����¼����ͬһ���µģ����Բ��ö��·����� 
	}else
		return strcmp(a.name,b.name)<0;		//�����ֵ����������� 
}

int toll[25];		//����ʱ��εķ��ã����ȫ�ֱ��� ,toll[24]���ǰ��24��֮�� 

int t(int d1,int h1,int m1,int d2,int h2,int m2){	//������d1:h1:m1 - d2:h2:m2�ķ��ã����ݸ���ʱ��εķ��� 
	int total=0;
	//printf("\n%d:%d  %d:%d\n",h1,m1,h2,m2);
	if(d1==d2){				//��ͬ��һ�� 
		if(h1==h2){
			total=toll[h1]*(m2-m1);
		}else{
			for(int i=h1;i<=h2;i++){
				if(i==h1)
					total+=toll[i]*(60-m1);
				else if(i==h2)
					total+=toll[i]*m2;
				else
					total+=60*toll[i];
			}
		}
		return total;
	} 
	
	return t(d1,h1,m1,d1,23,60)+t(d2,0,0,d2,h2,m2)+(d2-d1-1)*(60*toll[24]);		//��ͬ�죬�����һ��+��n��+���˼��� 
}

int m(int d1,int h1,int m1,int d2,int h2,int m2){	//������d1:h1:m1 - d2:h2:m2���ܵķ��� 
	//printf("%d\n",60-m1+(h2-h1-1)*60+m2); 
	if(d1==d2)
		return 60-m1+(h2-h1-1)*60+m2; 
	else{											//�˴��õ��ݹ��˼�룡�ܺ� 
		return m(d1,h1,m1,d1,23,60)+m(d2,0,0,d2,h2,m2)+(d2-d1-1)*(60*24);
	}
}

int main(){	
	toll[24]=0;				//toll[24]����ܷ��� 
	for(int i=0;i<24;i++){	//ÿ��ʱ��εķ��ã�0:00-1:00�ķ���Ϊtoll[o]��23:00-0:00�ķ���Ϊtoll[23] 
		scanf("%d",&toll[i]);
		toll[24]+=toll[i]; 
	}		
	
	int N;			//N<=1000
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%s %s %s",records[i].name,records[i].dt,records[i].word);
		records[i].mon[0]=records[i].dt[0];
		records[i].mon[1]=records[i].dt[1];
		
		records[i].day[0]=records[i].dt[3];
		records[i].day[1]=records[i].dt[4];
		
		records[i].hour[0]=records[i].dt[6];
		records[i].hour[1]=records[i].dt[7];
		
		records[i].min[0]=records[i].dt[9];
		records[i].min[1]=records[i].dt[10];
	}
	
	sort(records,records+N,cmp);			//����������ݽ������� 
	
	//�����ȵõ��ж��ٸ��ˣ�ÿ�����ж�������¼ 
	int num=0;		//��ͬ������
	int nr[1005];	//ÿ���˵ĺ��ж�������¼��0-num-1 ��¼
	memset(nr,0,sizeof(int)*1005); 
	char temp[21];
	strcpy(temp,records[0].name);
	nr[num]++;		// ��ͬ��������һ����¼����һ 
	for(int i=1;i<N;i++){
		if(strcmp(temp,records[i].name) ==0 ){
			nr[num]++;			//���������ͬ�����Ӽ�¼�� 
		}
		else{ 
			nr[++num]++;		//���������ͬ������������Ҳ���Ӽ�¼�� 
			strcpy(temp,records[i].name);//����temp 
		} 
	} 
	num++;			//��������һ����Ϊ�����ټ���1 
	
	//������� 
	int count=0;	//����ָ��һ��һ�������ƶ����������м�¼ 
	for(int i=0;i<num;i++){
		int flag=1;		//����Ѱ����Եĵ绰��¼ 
		int totaltoll=0;	//ÿһ���˵��ܷ��á� 
		
		int k=0;		//�������ơ���һ������Եĵ绰��¼ʱ������������·ݡ���Ҳ��֤�ˡ���������Чͨ����¼���˲��ᱻ����� 
		//printf("nr[i]:%d");
		for(int j=0;j<nr[i];j++){
			//printf("count:%d\n",count);
			if(strcmp(records[count].word,"on-line")==0){ 
				//printf("count:%d\n",count); 
				//count++; 
				flag=0;
			} 
			else if(strcmp(records[count].word,"off-line")==0 && flag==0){				
				if(k==0){
					printf("%s %s\n",records[count].name,records[count].mon);
					k++;
				}
				//count++;
				flag=1;
				
				printf("%s:%s:%s %s:%s:%s ",records[count-1].day,records[count-1].hour,records[count-1].min,records[count].day,records[count].hour,records[count].min);
				int d1,h1,m1,d2,h2,m2;	//d1:h1:m1  d2:h2:m2  ת����int�� 
				d1= (records[count-1].day[1]-48)+(records[count-1].day[0]-48)*10;
				h1= (records[count-1].hour[1]-48)+(records[count-1].hour[0]-48)*10;
				m1= (records[count-1].min[1]-48)+(records[count-1].min[0]-48)*10;
				d2= (records[count].day[1]-48)+(records[count].day[0]-48)*10;
				h2= (records[count].hour[1]-48)+(records[count].hour[0]-48)*10;
				m2= (records[count].min[1]-48)+(records[count].min[0]-48)*10;
				//printf("\n%d:%d  %d:%d\n",h1,m1,h2,m2);
				int mins=m(d1,h1,m1,d2,h2,m2);			//�����ܵ�ʱ�� 
				int tolls=t(d1,h1,m1,d2,h2,m2);			//�����ܷ���
				totaltoll+=tolls;
				printf("%d $%.2f\n",mins,tolls/100.0);
			} 
			count++;//ָ�����һλ 
		} 
		//�������˵��ܷ���
		if(totaltoll!=0)
			printf("Total amount: $%.2f\n",totaltoll/100.0); 
	}
	/* 
	printf("\n");
	for(int i=0;i<N;i++){
		printf("%s %s:%s:%s:%s %s\n",records[i].name,records[i].mon,records[i].day,records[i].hour,records[i].min,records[i].word);
	}
	printf("%d\n",num); 
	for(int i=0;i<num;i++)
		printf("%d\n",nr[i]);
	*/
	return 0;
}
