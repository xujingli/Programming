#  [75. Sort Colors](https://leetcode.com/problems/sort-colors/)

[toc]

> Given an array with *n* objects colored red, white or blue, sort them **[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** so that objects of the same color are adjacent, with the colors in the order red, white and blue.
>
> Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
>
> **Note:** You are not suppose to use the library's sort function for this problem.
>
> **Example:**
> 
> ```
> Input: [2,0,2,1,1,0]
>Output: [0,0,1,1,2,2]
> ```
>
> **Follow up:**
> 
> - A rather straight forward solution is a two-pass algorithm using counting sort.
>   First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
> - Could you come up with a one-pass algorithm using only constant space?
>
> ```
>/**
>  * @param {number[]} nums
>  * @return {void} Do not return anything, modify nums in-place instead.
>  */
> var sortColors = function(nums) {
>     
>  };
> ```
> 

## solution: Two pass

**two pass:**

时间复杂度：O(n), 空间复杂度O(1)

```
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
*/
var sortColors = function(nums) {
	let count1=count2=count0=0;
	
	let len = nums.length;
	for(let i=0;i<len;i++){
		if(nums[i] === 0) count0++;
		else if(nums[i] === 1) count1++;
		else if(nums[i] === 2) count2++;
	}
	for(let i=0;i<len;i++){
		if(i<count0) nums[i] = 0
		else if(i<(count0+count1)) nums[i] = 1
		else if(i<(count0+count1+count2)) nums[i] = 2
	}
};
```

## Solution: one pass

1、快速排序？空间复杂度:O(1)；时间复杂度O(nlogn)

```
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    quickSort(nums,0,nums.length-1)
};

function partition(nums,left,right){
    let p = Math.random() * (right-left) + left; //[left,right]
	p = Math.round(p)
	
	let t = nums[p]
	nums[p] = nums[left]
	nums[left] = t
    
    let tmp = nums[left]
    while(left<right){
        while(left<right && nums[right]>tmp) right--
        nums[left] = nums[right]
        
        while(left<right && nums[left]<=tmp) left++
        nums[right] = nums[left]
    }
    nums[left]=tmp
    return left
}

function quickSort(nums, left,right){
    if(left<right){
        let mid = partition(nums,left,right)
        quickSort(nums,left,mid-1)
        quickSort(nums,mid+1,right)
    }
}
```

如果n >= 4时，nlog(n) >= 2n，所以，快排的方法不是很好！



## 荷兰国旗问题

将乱序的红白蓝三色小球排列成有序的红白蓝三色的同颜色在一起的小球组。这个问题之所以叫荷兰国旗，是因为我们可以将红白蓝三色小球想象成条状物，有序排列后正好组成荷兰国旗。

2.问题分析：

思路如下：将前部和后部各排在数组的前边和后边，中部自然就排好了。具体的：

设置两个标志位begin和end分别指向这个数组的开始和末尾，然后用一个标志位current从头开始进行遍历：

1）若遍历到的位置为0，则说明它一定属于前部，于是就和begin位置进行交换，然后current向前进，begin也向前进（表示前边的已经都排好了）。

2）若遍历到的位置为1，则说明它一定属于中部，根据总思路，中部的我们都不动，然后current向前进。

3）若遍历到的位置为2，则说明它一定属于后部，于是就和end位置进行交换，由于交换完毕后current指向的可能是属于前部的，若此时current前进则会导致该位置不能被交换到前部，所以此时current不前进。而同1），end向后退1

![](/image/Dutchflagproblem1.jpg)

![](/image/Dutchflagproblem2.jpg)

```
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
*/
var sortColors = function(nums) {
	let len = nums.length
	let begin = 0, cur = 0, end = len - 1
	while(cur <= end){
		if(nums[cur] === 0) {
			swap(nums,cur,begin);
			++begin
			++cur
		}else if(nums[cur] === 1){
			++cur
		}else{
			swap(nums,end,cur)
			--end
		}
	}
};

function swap(A,a,b){
	let temp = A[a]
	A[a] = A[b]
	A[b] = temp
}
```

