# [57. Insert Interval](https://leetcode.com/problems/insert-interval/)

[toc]

> Given a set of *non-overlapping* intervals, insert a new interval into the intervals (merge if necessary).
>
> You may assume that the intervals were initially sorted according to their start times.
>
> **Example 1:**
>
> ```
> Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
> Output: [[1,5],[6,9]]
> ```
>
> **Example 2:**
>
> ```
> Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
> Output: [[1,2],[3,10],[12,16]]
> Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
> ```
>
> **NOTE:** input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
>
> ```
> /**
>  * @param {number[][]} intervals
>  * @param {number[]} newInterval
>  * @return {number[][]}
>  */
> var insert = function(intervals, newInterval) {
>     
> };
> ```
>

题目条件：无重叠的区间；这些区间都按照第一个值升序排列。



## Thought 1:

以 Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8] 为例。

step 1: 把完全在范围[4,8]左侧，即所有元素都小于4的区间push到结果里。

step 2: 在范围内部的。比如[3,5] 那么就把newInterval扩展到 \[min(3,4), max(5,8)\]  = \[3, 8\] 

​			现在的newInterval =  \[3, 8\] 

​			遇到[6,7]  再扩展到 [3,8]

​			遇到[8,10] 扩展到 [3,10]

​			将[3,10] push到结果

step 3: 在范围右侧的，所有元素大于10 push到结果里面

空间复杂度：O(n), 时间复杂度 O(n)

![](/image/57_example.png)



```
/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
	  let res = []
	  let index = 0;
	  let len = intervals.length
	  while(index < len && intervals[index][1] < newInterval[0]){
	  		res.push(intervals[index++])
	  }
	  while(index < len && intervals[index][0] <= newInterval[1]){
	  		newInterval = [Math.min(intervals[index][0],newInterval[0]),Math.max(intervals[index][1],newInterval[1])]
	  		index++
	  }
	  res.push(newInterval)
	  
	  while(index < len && intervals[index][0] > newInterval[1]){
	  		res.push(intervals[index++])
	  }
	  return res
};
```





## 更优写法

> Runtime: 60 ms, faster than 91.48% of JavaScript online submissions for Insert Interval.
>
> Memory Usage: 35.8 MB, less than 100.00% of JavaScript online submissions for Insert Interval.

分析：

以 Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8] 为例。

遍历intervals

step 1: 如果区间最大值小于 4 ，则把这个区间直接push到结果里

step 2: 对于4 在 [3,5] 之间，所有， 更新newInterval为 [3, max(8,5)]

​				[6,7] 不进行任何操作。忽略它，因为它在[3,8]内部

​				因为 8在 [8,10]区间，所以更新newInterval为 [min(8,3), 10] 为 [3,10]

step3 : 如果某个区间的第一个元素值大于10 ，说明之后的每个区间都在外部。返回  之前push的，加上[3,10]，加上之后的。



时间上，忽略了中间的一些区间，比如：【3,5】，只要找到开头和结尾的元素就行。可能解构赋值，比一个一个push要快，也要节省空间。

```
/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
  if (intervals.length < 1) return [newInterval];

  let N = newInterval, ans = [];
  for (let i = 0; i < intervals.length; i++) {
    const I = intervals[i];
    if (I[1] < N[0]) ans.push(I);
    else if (I[0] <= N[0] && I[1] >= N[0]) {
      N = [I[0], Math.max(I[1], N[1])];
    } else if (I[0] <= N[1] && I[1] >= N[1]) {
      N = [Math.min(I[0], N[0]), I[1]];
    } else if (N[1] < I[0]) {
      return [...ans, N, ...intervals.slice(i)];
    }
  }
  return [...ans, N];
}
```



模仿：

```
/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
    if(intervals.length < 1) return [newInterval]
    
    let N = newInterval, ans = [] //名称太长，不如简化
    for(let i=0;i<intervals.length;i++){
    	const I = intervals[i]
    	if(I[1] < N[0]) ans.push(I)
    	else if(I[0] <= N[0] && N[0] <= I[1])
    		N = [I[0], Math.max(I[1],N[1])]
    	else if(I[0] <= N[1] && N[1] <= I[1])
    		N = [Math.min(I[0],N[0]), I[1]]
    	else if(N[1] < I[0]){
    		return [...ans,N, ...intervals.slice(i)]
    	}
    }
    return [...ans, N];
};
```

