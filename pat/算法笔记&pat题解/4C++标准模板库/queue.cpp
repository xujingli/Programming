//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

struct fruit{
	string name;
	int price;
	friend bool operator < (fruit f1,fruit f2){
		return f1.price > f2.price;
	}
}f1,f2,f3; 

int main(){
	queue<int> q;
	for(int i = 1; i <= 5; i++){
		q.push(i);
	}		//入队顺序是 1 2 3 4 5 
	printf("%d \n",q.front());

	priority_queue<int> q1;
	//priority_queue<int, vector<int>, less<int> >q1; //less<int>表示数字大的优先级越大 
	priority_queue<int, vector<int>, greater<int> >q2;//greater<int>表示数字小的优先级越大 
	for(int i=1;i<=5;i++){
		q1.push(i);
		q2.push(i);
	}
	printf("top of q1: %d\ntop of q2: %d\n",q1.top(),q2.top());
	
	priority_queue<fruit> q3;
	f1.name = "apple";
	f1.price = 3;
	f2.name = "peach";
	f2.price = 4;
	f3.name = "banana";
	f3.price = 1;
	q3.push(f1);
	q3.push(f2);
	q3.push(f3);
	cout << q3.top().name << " " << q3.top().price << endl;
	
	return 0;
}

