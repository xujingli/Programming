//����ϸ�£���ϸ����
//ԭ�ģ�http://blog.csdn.net/duan19920101/article/details/50617190/ 
//C++��vector��ʹ�÷���
/*
��c++�У�vector��һ����ʮ�����õģ�����

���ã�vector��һ���ܹ�����������͵Ķ�̬���飬�ܹ����Ӻ�ѹ�����ݡ���������������Ÿ������͵Ķ���
		vector��һ���๦�ܵ��ܹ������������ݽṹ���㷨��ģ����ͺ�����

ע�⣺
	1.���Ҫ��ʾ���������Ƚϳ�����ҪΪ�����ڲ�����ܶ����������׵����ڴ�й©������Ч�ʺܵ�
	2.vector��Ϊ�����Ĳ������߷���ֵʱ����Ҫע������д����
			double Distance(Vector<int>&a,Vector<int>&b),����"&"���Բ�����
 
ʵ��1��vector<int>test;
	//����һ��vector��intΪ����Ԫ�ص��������ͣ�testΪ��̬������
	�򵥵�ʹ�÷������£�
	vector<int>test;//����һ��vector
	test.push_back(1);
	test.push_back(2);//��1��2ѹ��vector������test[0]����1,test[1]����2
ʵ��2��
	vector<vector<Point2f> > points; //����һ����ά����
	points[0].size();  //ָ��һ�е�����

����������
	(1)ͷ�ļ�#include <vector>.
	(2)����vector����vector<int> vec;
	(3)β���������֣�vec.push_back(a);
	(4)ʹ���±����Ԫ�أ�cout<<vec[0]<<endl;��ס�±��Ǵ�0��ʼ�ġ�
	(5)ʹ�õ���������Ԫ��.
		vector<int>::iterator it;
		for(it=vec.begin();it!=vec.end();it++)
	    	cout<<*it<<endl;
	(6)����Ԫ�أ�    vec.insert(vec.begin()+i,a);//�ڵ�i+1��Ԫ��ǰ�����a;
	(7)ɾ��Ԫ�أ�    vec.erase(vec.begin()+2);//ɾ����3��Ԫ��
					vec.erase(vec.begin()+i,vec.end()+j);//ɾ������[i,j-1];�����0��ʼ
	(8)������С:vec.size();
	(9)���:vec.clear();
*/

/*
��Ҫ˵��:
	vector��Ԫ�ز�����������int,double,string,�������ǽṹ�壬
	����Ҫע�⣺�ṹ��Ҫ����Ϊȫ�ֵģ���������
*/ 	

//#define p1	//define p1 ��Ϊ���� 
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
	
	//��������Ԫ���ǽṹ��ģ����ڽṹ���ڲ�����ȽϺ��������水��id,length,width�������� 
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
�㷨
	(1) ʹ��reverse��Ԫ�ط�ת����Ҫͷ�ļ�#include<algorithm>
				reverse(vec.begin(),vec.end());��Ԫ�ط�ת�����������У�
				(��vector�У����һ����������Ҫ������������һ���һ����������)
	
	(2)ʹ��sort������Ҫͷ�ļ�#include<algorithm>��
				sort(vec.begin(),vec.end());(Ĭ���ǰ���������,����С����).
		����ͨ����д����ȽϺ������ս���Ƚϣ����£�
		��������ȽϺ�����
		bool Comp(const int &a,const int &b)
		{
	    	return a>b;
		}
		����ʱ:sort(vec.begin(),vec.end(),Comp)�������ͽ�������
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
	
	//��ӡ����һ�� 
	for(int i=0;i<nSize;i++)
		cout<< vecClass[i] <<"   " ;
	cout <<endl;
	
	//��ӡ��������
	for(int i=0;i<nSize;i++)
		cout<< vecClass.at(i) <<"   " ;
	cout <<endl;
	
	sort(vecClass.begin(),vecClass.end(),Comp);
	//��ӡ��������
	vector<float>::iterator it;
	for(it=vecClass.begin();it!=vecClass.end();it++)
	   	cout<<*it<<"   ";
	cout<<endl;
	
	//
	
	return 0;
}

#endif

/*��ά���� */
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

//************************���Կα��ϵ����ӷ���******************
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
		
		if((i+1)%4==0)		//ÿ�����4������ 
			cout<<endl;
	}
	
	if(i%4!=0)				//�Ͻ������ǵ����һ����������ĸ�Ԫ�صĻ�����ӡ�껹Ҫ��һ�����з� 
		cout<<endl;
}

void inputVector( const vector<int> &array){//input vector contents
	for(int i=0;i<array.size();i++)
		cin >> array[i];
} 

int main(){
	vector<int> integers1(7);
	vector<int> integers2(10);		//����һ����10��Ԫ�ص����� 
	
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
 



/****************���ǻ����ķָ���*******************************
****                                                      ******
****		������vector��̬�����һ��СӦ�ã�pat B1015�� ****** 
****                                                      ******
***************************************************************/

//#define p4 
#ifdef p4

#endif
