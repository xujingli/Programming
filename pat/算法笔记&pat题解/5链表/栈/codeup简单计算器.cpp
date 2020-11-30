//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <iostream> 
#include <string>
#include <stack>
#include <queue>
#include <map> 
using namespace std;

struct node{
	double num;	//������ 
	char op;	//������ 
	bool flag;	//true��ʾ��������false��ʾ������ 
};
string str;
stack<node> s;	//������ջ
queue<node> q;	//��׺���ʽ����
map<char,int> op;	//�����������ȼ������С�
 
void Change(){	//����׺���ʽת��Ϊ��׺���ʽ 
	//double num;
	node temp;
	for(int i=0; i<str.length();){
		if(str[i]>='0' && str[i]<='9'){	//���������
			temp.flag = true;			//���������
			temp.num = str[i++]-'0';	//��¼����������ĵ�һ����λ
			while(i<str.length() && str[i]>='0' && str[i]<='9')
				temp.num = temp.num * 10 + (str[i++]-'0');	//�������������
			q.push(temp);		//�����������ѹ���׺���ʽ���� 
		} 
		else{	//����ǲ����� 
			temp.flag = false;	//����ǲ����� 
			while(!s.empty() && op[str[i]] <= op[s.top().op]){	//ջ����������Ҫ�ȼ��㡣���ȷŵ���׺���ʽ������������㣩 
				q.push(s.top());
				s.pop();
			} 
			temp.op = str[i];
			s.push(temp);		//�Ѳ�����ѹ�������ջ 
			i++; 
		}
	} 
	//���������ջ�л��в��������Ͱ�����������׺���ʽ������
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	} 
}

double Cal(){		//�����׺���ʽ 
	double temp1,temp2;
	node cur,temp;
	while(!q.empty()){		//ֻҪ��׺���ʽ�ǿ� 
		cur = q.front();	//cur��¼����Ԫ��
		q.pop(); 
		if(cur.flag == true) s.push(cur);	//����ǲ�������ֱ��ѹ���ջ
		else{				//����ǲ����� 
			temp2 = s.top().num;	//�����ڶ������� 
			s.pop();
			temp1 = s.top().num;	//������һ������
			s.pop();
			temp.flag = true;		//��ʱ��¼������
			if(cur.op == '+') temp.num = temp1+temp2;
			else if(cur.op == '-') temp.num = temp1-temp2;
			else if(cur.op == '*') temp.num = temp1*temp2;
			else temp.num = temp1 / temp2;	
			s.push(temp);			//�Ѹò�����ѹ��ջ�� 
		} 
	}
	return s.top().num;
}

int main(){
	op['+'] = op['-'] =1;
	op['*'] = op['/'] =2;	//�趨���������ȼ� 
	while(getline(cin,str), str != "0"){
		string::iterator it;
		for(it = str.end(); it !=str.begin() ; it--){
			if(*it == ' ') str.erase(it);	//�ѱ��ʽ�Ŀո�ȫ��ɾȥ 
		}
		while(!s.empty()) s.pop();	//��ʼ��ջ
		Change();				//����׺���ʽת��Ϊ��׺���ʽ
		printf("%.2f\n",Cal());		//�����׺���ʽ 
	}

	return 0;
}

