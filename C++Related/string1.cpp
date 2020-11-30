//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

int main(){
	string str;
	cin >> str;
	cout << str <<endl;
	
	printf("%s\n",str.c_str());			//转换为字符数组输出
	 
	string::iterator it;
	for(it=str.begin();it!=str.end();it++)
		printf("%c",*it);
	printf("\n");
	//以上是输入输出实例 
	
	string str2 = "hello ",str3 = "world" ,str4;
	str4 = str2 + str3;
	str2 += str3;
	printf("str4:%s\n",str4.c_str());
	printf("str2:%s\n",str2.c_str());
	
	str4.insert(0,"xjl ");
	printf("str4:%s\n",str4.c_str());
	
	printf("substr4:%s\n",str4.substr(0,3).c_str());
	
	if(str4.find(str3)!=string::npos){
		printf("fond \"%s\" from str4 at pos :%d\n",str3.c_str(),str4.find(str3));
	}

	return 0;
}

