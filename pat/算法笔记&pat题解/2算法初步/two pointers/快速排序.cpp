//日期：2018/ 时间：
/*随机数说明，需要包含头文件<time.h>或者<stdlib.h>. 
  首先在main()函数开头加上srand((unsigned)time(NULL));
  rand()函数产生一个范围是[0,RAND_MAX]的随机数。rand()/RAND_MAX就会产生一个[0,1]的随机数。
  想要生成大范围的随机数，就要用 (rand()/RAND_MAX)*(b-a) + a ，再进行四舍五入取整转换成int型
  最终(int)(round((rand()/RAND_MAX)*(b-a) + a)) ----------就产生了[a,b]范围内的随机数。闭区间 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <algorithm>
using namespace std;

//two pointer方法。 
//整序列中的元素，使当前序列最左端的元素调整后满足，最左侧所有元素都不超过该元素，右侧所有元素都大于该元素 
int Partition(int A[],int left,int right){
	int temp = A[left];		//将A[left]存放至临时变量temp
	while(left < right){
		while(left < right && A[right] > temp) right--;
		A[left]=A[right];
		while(left < right && A[left] <= temp ) left++;
		A[right]=A[left];
	} 
	A[left] = temp;
	return left;
}

//快排的思想是：1）调整序列中的元素，使当前序列最左端的元素调整后满足，最左侧所有元素都不超过该元素，右侧所有元素都大于该元素
//				2）对该元素的左侧和右侧分别进行递归，直到当前调整区间的长度不超过1
//left与right初值为序列首尾下标（例如1和n）
void quickSort(int A[],int left,int right){
	if(left < right){	//当前区间长度超过1 
		//将[left,right]按A[left]一分为二
		int pos = Partition(A, left,right);
		quickSort(A,left,pos-1);		//对左子区间递归进行快速排序
		quickSort(A,pos+1,right);		//对右子区间递归进行快速排序 
	}
} 

//快速排序产生复杂度为O(n^2) ，主要原因在于，当序列中元素接近有序时，主元没有把当前区间划分为两个长度接近的子区间 
//规避方法是：在A[left,right]中随机选取一个主元，
//因此不妨生成一个范围在[left,right]内的随机数p，然后以A[p]作为主元进行划分。
//具体做法是：将A[p]与A[left]交换，然后按照原先的Partition函数的写法即可
int randPartition(int A[],int left,int right){
	int p = (int)(round(1.0*rand()/RAND_MAX * (right-left) + left));
	swap(A[p],A[left]);			//include <algorithm>
	
	int temp = A[left];		//将A[left]存放至临时变量temp
	while(left < right){
		while(left < right && A[right] > temp) right--;
		A[left]=A[right];
		while(left < right && A[left] <= temp ) left++;
		A[right]=A[left];
	} 
	A[left] = temp;
	return left;
} 

int main(){
	

	return 0;
}

