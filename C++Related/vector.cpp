//耐心细致，仔细分析
//原文：http://blog.csdn.net/duan19920101/article/details/50617190/ 
//C++中vector的使用方法
/*
在c++中，vector是一个（十分有用的）容器

作用：vector是一个能够存放任意类型的动态数组，能够增加和压缩数据。（像容器那样存放各种类型的对象）
		vector是一个多功能的能够操作各种数据结构和算法的模板类和函数库

注意：
	1.如果要表示的向量长度较长（需要为向量内部保存很多数），容易导致内存泄漏，而且效率很低
	2.vector作为函数的参数或者返回值时，需要注意它的写法：
			double Distance(Vector<int>&a,Vector<int>&b),其中"&"绝对不能少
 
实例1：vector<int>test;
	//建立一个vector，int为数组元素的数据类型，test为动态数组名
	简单的使用方法如下：
	vector<int>test;//建立一个vector
	test.push_back(1);
	test.push_back(2);//把1和2压入vector，这样test[0]就是1,test[1]就是2
实例2：
	vector<vector<Point2f> > points; //定义一个二维数组
	points[0].size();  //指第一行的列数

基本操作：
	(1)头文件#include <vector>.
	(2)创建vector对象，vector<int> vec;
	(3)尾部插入数字：vec.push_back(a);
	(4)使用下标访问元素，cout<<vec[0]<<endl;记住下标是从0开始的。
	(5)使用迭代器访问元素.
		vector<int>::iterator it;
		for(it=vec.begin();it!=vec.end();it++)
	    	cout<<*it<<endl;
	(6)插入元素：    vec.insert(vec.begin()+i,a);//在第i+1个元素前面插入a;
	(7)删除元素：    vec.erase(vec.begin()+2);//删除第3个元素
					vec.erase(vec.begin()+i,vec.end()+j);//删除区间[i,j-1];区间从0开始
	(8)向量大小:vec.size();
	(9)清空:vec.clear();
*/

/*
重要说明:
	vector的元素不仅仅可以是int,double,string,还可以是结构体，
	但是要注意：结构体要定义为全局的，否则会出错。
*/ 	

//#define p1	//define p1 即为例子 
#ifdef p1

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

typedef struct rect{
	int id;
	int length;
	int width;
	
	//对于向量元素是结构体的，可在结构体内部定义比较函数，下面按照id,length,width升序排序。 
	bool operator< (const rect &a) const{
		if (id!=a.id)
			return id<a.id;
		else{
			if(length!=a.length)
				return length<a.length;
			else
				return width<a.width;
		} 
	} 
}Rect; 
 
int main(){
	vector<Rect> vec;
	Rect rect;
	rect.id=1;
	rect.length=2;
	rect.width=3;
	
	vec.push_back(rect);
	vector<Rect>::iterator it=vec.begin();
	
	cout<<(*it).id<<' '<<(*it).length<<' '<<(*it).width<<endl;  

	return 0;
}

#endif

/*
算法
	(1) 使用reverse将元素翻转：需要头文件#include<algorithm>
				reverse(vec.begin(),vec.end());将元素翻转，即逆序排列！
				(在vector中，如果一个函数中需要两个迭代器，一般后一个都不包含)
	
	(2)使用sort排序：需要头文件#include<algorithm>，
				sort(vec.begin(),vec.end());(默认是按升序排列,即从小到大).
		可以通过重写排序比较函数按照降序比较，如下：
		定义排序比较函数：
		bool Comp(const int &a,const int &b)
		{
	    	return a>b;
		}
		调用时:sort(vec.begin(),vec.end(),Comp)，这样就降序排序。
*/

//#define p2

#ifdef p2
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool Comp(const int &a,const int &b)
{
   	return a>b;
}

int main(){
	vector<float> vecClass;
	vecClass.push_back(3.5);
	vecClass.push_back(2.7);
	vecClass.push_back(1.2);	
	int nSize=vecClass.size();
	
	//打印方法一： 
	for(int i=0;i<nSize;i++)
		cout<< vecClass[i] <<"   " ;
	cout <<endl;
	
	//打印方法二：
	for(int i=0;i<nSize;i++)
		cout<< vecClass.at(i) <<"   " ;
	cout <<endl;
	
	sort(vecClass.begin(),vecClass.end(),Comp);
	//打印方法三：
	vector<float>::iterator it;
	for(it=vecClass.begin();it!=vecClass.end();it++)
	   	cout<<*it<<"   ";
	cout<<endl;
	
	//
	
	return 0;
}

#endif

/*二维数组 */
#define p3

#ifdef p3

#include <vector>   
#include <iostream>   
using namespace std; 
 
int main()  
{  
    int out[3][2] = { 1, 2,   
             		  3, 4,  
            		  5, 6 };  
    vector <int*> v1;  
  
    v1.push_back(out[0]);  
    v1.push_back(out[1]);  
    v1.push_back(out[2]);  
  
    cout << v1[0][0] << endl;//1  
    cout << v1[0][1] << endl;//2  
    cout << v1[1][0] << endl;//3  
    cout << v1[1][1] << endl;//4  
    cout << v1[2][0] << endl;//5  
    cout << v1[2][1] << endl;//6  
  
    return 0;  
} 
#endif

//************************来自课本上的例子分析******************
//#define p5
#ifdef p5
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void outputVector( const vector<int> &array){//display the vector
	int i;
	for(i=0;i<array.size();i++){
		cout<< setw(12) <<array[i];
		
		if((i+1)%4==0)		//每行输出4个数字 
			cout<<endl;
	}
	
	if(i%4!=0)				//严谨！考虑到最后一行如果少于四个元素的话，打印完还要补一个换行符 
		cout<<endl;
}

void inputVector( const vector<int> &array){//input vector contents
	for(int i=0;i<array.size();i++)
		cin >> array[i];
} 

int main(){
	vector<int> integers1(7);
	vector<int> integers2(10);		//创建一个有10个元素的数组 
	
	cout << "Size of vector integers1 is " << integers1.size() <<endl;
	cout << "vector after initialization:" <<endl;
	outputVector(integers1);
	
	cout << "Size of vector integers2 is " << integers2.size() <<endl;
	cout << "vector after initialization:" <<endl;
	outputVector(integers2);
	
	cout << "\nEnter 17 integers:"<<endl;
	inputVector(integers1);
	inputVector(integers2);
	
	cout << "\nAfter input, the vectors contain:\n" << "integers1:"<<endl;
	outputVector(integers1);
	cout << "integers2:"<<endl;
	outputVector(integers2);
	
}


#endif 
 



/****************我是华丽的分割线*******************************
****                                                      ******
****		以下是vector动态数组的一个小应用（pat B1015） ****** 
****                                                      ******
***************************************************************/

//#define p4 
#ifdef p4

#endif
