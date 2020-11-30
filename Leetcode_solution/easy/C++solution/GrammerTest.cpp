//用来测试一些语法正确性
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int main(){
	int map[256];
    map['I']=1;map['V']=5;map['X']=10;map['L']=50;map['C']=100;map['D']=500;map['M']=1000;
    
    printf("%d\n",map['V']);
        
	return 0;
} 
