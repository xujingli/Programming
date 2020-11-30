# 算法初步

[toc]

![算法复杂度 图示](image/big-o-graph.png)

## 数组排序

[参考](https://www.cnblogs.com/onepixel/p/7674659.html)

#### 注意点：

1. 思考边界情况

### 冒泡排序：

- 比较相邻的元素。如果第一个比第二个大，就交换它们两个；
- 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
- 针对所有的元素重复以上的步骤，除了最后一个；
- 重复步骤1~3，直到排序完成。



![](image/bubblesort.gif)

```
let bubbleSort = (inputArr) => {
	let len = inputArr.length;
	for(let i=0;i<len-1;i++){
		for(let j=0;j<len-1-i;j++){ //第0个——当前循环的最后一个
			if(inputArr[j] > inputArr[j+1]){
				let temp = inputArr[j+1];
				inputArr[j+1] = inputArr[j]
				inputArr[j] = temp
			}
		}
	}
	return inputArr;
}
```

### 插入排序：

- 从第一个元素开始，该元素可以认为已经被排序；
- 取出下一个元素，在已经排序的元素序列中从后向前扫描；
- 如果该元素（已排序）大于新元素，将该元素移到下一位置；
- 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
- 将新元素插入到该位置后；
- 重复步骤2~5。

![](image/insertsort.gif)

```
let insertionSort = (arr) => {
	let len = arr.length;
	for(let i=1;i<len;i++){	//第0个数字已经有序
		let tmp = arr[i],j=i;
		while(j>0 && tmp < arr[j-1]){
			arr[j] = arr[j-1];
			j--
		}
		arr[j] = tmp;
	}
	return arr;
}
```

### 选择排序

A[1] ~ A[n]，令i从1到n枚举，进行n趟操作，每趟从待排序部分[i, n]中选择最小的元素，令其与待排序部分的第一个元素A[i]进行交换，这样元素A[i]就会与当前有序的区间[1,i-1]形成新的有序区间[1,i]

![](image/selectionsort.gif)

```
let selectSort = (arr) => {
	let len = arr.length
	for(let i=0;i < len-1;i++){	//[0,i-1]有序，寻找[i,n-1]最小值，替换到i位置
		let minIndex=i;
		for(let j=i+1;j<len;j++){ //与插入排区别：选择排序是往后寻找最小值，插入是往前寻找合适的位置
			if(arr[j]<arr[minIndex]){
				minIndex = j;
			}
		}
		let tmp = arr[i]
		arr[i] = arr[minIndex];
		arr[minIndex] = tmp;
	}
	return arr;
}
```

**小结：思考边界情况，最难理解的也是边界情况**

### 快速排序

见《算法笔记》P142

**思路是：** 

	1. 调整序列中的元素，使当前序列最左端的元素在调整后满足：左侧所有元素均不超过该元素，右侧所有元素均大于该元素。
 	2. 对元素的左侧和右侧分别递归地进行调整，直到当前调整区间长度小于等于1

```
let Partition = (A, left, right) => {
	let tmp = A[left]
	while(left < right){
		while(left < right && A[right] > tmp) right--
		A[left] = A[right];
		while(left < right && A[left] <= tmp) left++
		A[right] = A[left];	//A[left] > tmp时...应该放到右边某位置
	}
	A[left] = tmp;
	return left;
}

let quickSort = (A, left,right) => {
	if(left < right){
		let pos = Partition(A,left,right)
		quickSort(A,left,pos-1);
		quickSort(A,pos+1,right);
	}
}
```

以上的时间复杂度是O(n^2)，主要原因是，当序列中元素接近有序时，主元没有把当前区间划分为两个长度接近的子空间。规避方法是：在A[left,right]中随即选取一个主元。然后以A[p]为主元进行划分。这样期望运行时间就是O(nlogn)

```
let Partition = (A, left, right) => {
	let p = Math.random() * (right-left) + left; //[left,right]
	p = Math.round(p)
	
	let t = A[p]
	A[p] = A[left]
	A[left] = t
	
	let tmp = A[left]
	while(left < right){
		while(left < right && A[right] > tmp) right--
		A[left] = A[right];
		while(left < right && A[left] <= tmp) left++
		A[right] = A[left];	//A[left] > tmp时...应该放到右边某位置
	}
	A[left] = tmp;
	return left;
}

let quickSort = (A, left,right) => {
	if(left < right){
		let pos = Partition(A,left,right)
		quickSort(A,left,pos-1);
		quickSort(A,pos+1,right);
	}
}
```

### 归并排序

采用分治法。将已经有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。

![](image/mergesort.gif)

```
//递归实现
function merge(A,L1,R1,L2,R2){
	let i=L1,j=L2;
	let temp = [];
	while(i<=R1 && j<=R2){
		if(A[i] <= A[j]){
			temp.push(A[i++])
		}else{
			temp.push(A[j++])
		}
	}
	while(i<=R1) temp.push(A[i++])
	while(j<=R2) temp.push(A[j++])
	
	for(let i=0;i<temp.length;i++){
		A[L1+i] = temp[i]
	}
}
function mergeSort(A,left,right){
	if(left<right){
		let mid = Math.floor((left + right) / 2);
		mergeSort(A,left,mid);
		mergeSort(A,mid+1,right);
		merge(A,left,mid,mid+1,right);
	}
}
```

### 堆排序

![](image/heapsort.gif)

**基本思想：** 按照“删除”的方法，删除首元素，并把删除后的元素与尾元素交换。从第一个元素开始向下调整。

**向下调整：** 保持根节点始终大于两个叶节点，一直往下

**向上调整：** 如果叶节点大于父节点，就交换位置，是的父节点始终大于子节点

**建堆：** 从n/2处开始**向下调整**。调整完成后，最大的元素就在根节点

**插入：** 把节点放在堆最后，从这个最后位置开始**向上调整**

**删除堆顶元素：** 第一个位置与最后一个位置交换，并从第一个位置**向下调整**

```
let heap = [],n = 10 //注意heap数组从1开始

function downAdjust(low,high){ //向下调整
	let i=low, j=i*2;
	while(j<=high){
		if(j+1<=high && heap[j+1] > heap[j]){
			j = j + 1;
		}
		if(heap[j] > heap[i]){
			//swap(heap[i],heap[j])
			let t = heap[i]
			heap[i] = heap[j]
			heap[j] = t
			
			i = j;
			j = i*2
		}else{
			break;
		}
	}
}

function upAdjust(low,high){
	let i = high, j = i / 2
	while(j>=low){
		if(heap[j] < heap[i]){
			//swap(heap[i],heap[j])
			let t = heap[i]
			heap[i] = heap[j]
			heap[j] = t
			
			i = j
			j = i / 2
		}else {
			break;
		}
	}
}

function createHeap(){
	for(let i=Math.floor(n/2);i>=1;i--)
		downAdjust(i,n)
}

function deleteTop(){
	heap[1] = heap[n--];
	downAdjust(1,n);
}

function insert(int x){
	heap[++n] = x;
	upAdjust(1,n);
}

function heapSort(){
	createHeap();
	for(let i=n;i>=1;i--){
		//swap(heap[i],heap[1])
		let t = heap[i]
		heap[i] = heap[1]
		heap[1] = t
		
		downAdjust(1,i-1);
	}
}
 
```

### 严重问题：以上的这些排序算法根本没有仔细推敲其边界或特殊情况！完全记不住



### 数组排序算法的复杂性

| 名称         | 最优     | 平均           | 最坏         | 内存   | 稳定 | 备注                                           |
| ------------ | -------- | -------------- | ------------ | ------ | ---- | ---------------------------------------------- |
| **冒泡排序** | n        | n^2            | n^2          | 1      | Yes  |                                                |
| **插入排序** | n        | n^2            | n^2          | 1      | Yes  |                                                |
| **选择排序** | n^2      | n^2            | n^2          | 1      | No   |                                                |
| **堆排序**   | n log(n) | n log(n)       | n log(n)     | 1      | No   |                                                |
| **归并排序** | n log(n) | n log(n)       | n log(n)     | n      | Yes  |                                                |
| **快速排序** | n log(n) | n log(n)       | n^2          | log(n) | No   | 在 in-place 版本下，内存复杂度通常是 O(log(n)) |
| **希尔排序** | n log(n) | 取决于差距序列 | n (log(n))^2 | 1      | No   |                                                |
| **计数排序** | n + r    | n + r          | n + r        | n + r  | Yes  | r - 数组里最大的数                             |
| **基数排序** | n * k    | n * k          | n * k        | n + k  | Yes  | k - 最长 key 的升序                            |





## 散列



## 递归



## 贪心



## 二分

### 二分查找

```
//日期：2018/ 时间：
#include <stdio.h>
#include <stdlib.h>

//A[]为严格递增序列，left为二分下界， right为二分上界，x为欲查询的数
//二分区间为左闭右闭[left,right]，传入的初值为[0,n-1]
int binarySearch(int A[],int left,int right,int x){
	int mid;
	while(left <= right){		//如果left>right就没办法形成闭区间了 
		mid = (right + left) / 2;	//取中点
		if(A[mid] == x)	return mid;	//找到x,返回下标
		else if(A[mid] > x) {		//中间的数大于x 
			right = mid - 1;		//往左子区间[left,mid-1]查找 
		}else{						//中间的数小于x 
			left = mid + 1;			//往右子区间[mid+1,right]查找 
		}
	}
	return -1;		//查找失败，返回-1 
} 

//如果递增序列A中的元素可能重复，求出序列中第一个大于等于x的位置L, 以及第一个大于x的位置R,
//这样元素x在序列中的存在区间就是左闭右开区间[L,R) 

//1、求序列中第一个大于等于x的元素的位置 
//二分的初始区间应该能覆盖到所有可能返回的结果，二分下界是0，二分上界是n而不是n-1，因为欲查元素可能比所有的元素都大 
//二分上下界为左闭右闭区间[left,right],传入初值为[0,n] 
int lower_bound(int A[],int left,int right,int x){
	int mid;
	while(left < right){		//对[left,right]来说，left==right意味着找到唯一的位置 
		mid = (left+right)/2;		//取中点
		if(A[mid] >= x){
			right = mid;		//往左子区间查找 
		}else{
			left = mid+1;
		}
	}
	return left; 
} 

//2、求序列中第一个大于x的元素的位置
//二分上下界为左闭右闭区间[left,right],传入初值为[0,n] 
int upper_bound(int A[],int left,int right,int x){
	int mid;
	while(left < right){
		mid = (left + right)/2;
		if(A[mid] > x){
			right = mid;
		}else{		//A[mid] <= x 
			left = mid+1;
		}
	}
	return left;
}

int main(){
	const int n=10; 
	int A[n] = {1,3,4,6,7,8,10,11,12,15};
	
	printf("%d %d\n",binarySearch(A,0,n-1,6),binarySearch(A,0,n-1,9));

	return 0;
}
```

```
function binarySearch(A, left, right, x){
	let mid;
	while(left <= right){
		mid = (left + right) / 2;
		if(A[mid] === x) return mid;
		else if(A[mid] > x){
			right = mid - 1
		}else if(A[mid] < x){
			left = mid + 1
		}
	}
	return -1;
}

//1、求序列中第一个大于等于x的元素的位置 
//二分的初始区间应该能覆盖到所有可能返回的结果，二分下界是0，二分上界是n而不是n-1，因为欲查元素可能比所有的元素都大 
//二分上下界为左闭右闭区间[left,right],传入初值为[0,n] 
function lower_bound(A, left, right, x){
	let mid;
	while(left < right){		//对[left,right]来说，left==right意味着找到唯一的位置 
		mid = (left+right)/2;		//取中点
		if(A[mid] >= x){
			right = mid;		//往左子区间查找 
		}else{
			left = mid+1;
		}
	}
	return left; 
} 

//2、求序列中第一个大于x的元素的位置
//二分上下界为左闭右闭区间[left,right],传入初值为[0,n] 
function upper_bound(A, left, right, x){
	let mid;
	while(left < right){
		mid = (left + right)/2;
		if(A[mid] > x){
			right = mid;
		}else{		//A[mid] <= x 
			left = mid+1;
		}
	}
	return left;
}
```





## two pointers



## 其他高效技巧与算法

