#  56. Merge Intervals 

[toc]

> Given a collection of intervals, merge all overlapping intervals.
>
> **Example 1:**
>
> ```
> Input: [[1,3],[2,6],[8,10],[15,18]]
> Output: [[1,6],[8,10],[15,18]]
> Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
> ```
>
> **Example 2:**
>
> ```
> Input: [[1,4],[4,5]]
> Output: [[1,5]]
> Explanation: Intervals [1,4] and [4,5] are considered overlapping.
> ```
>
> **NOTE:** input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
>
> ```
> /**
>  * @param {number[][]} intervals
>  * @return {number[][]}
>  */
> var merge = function(intervals) {
>     
> };
> ```

## Solution:

### 思路一：

1. 按第一个元素大小排序
2. 如果a\[i\]\[1\] > a\[i+1\]\[0\] 则存在重叠，且合并
   1. 根据a\[i\]\[1\]和a\[i+1\]\[1\]的大小决定右侧边界
   2. 应考虑在原数组上进行操作。

```
var merge = function(intervals) {
	let len=intervals.length
	if(len <=1 ) return intervals
	
	intervals.sort(comp);
	
	let res = []
	res.push(intervals[0])
	let count = 1;
	
	for(let i=1;i<len;i++){
		if(res[count-1][1] >= intervals[i][0]){ //存在重叠
			if(res[count-1][1] < intervals[i][1])
				res[count-1][1] = intervals[i][1]
		}else{
			res.push(intervals[i])
			count++;
		}
	}
	return res
};
function comp(a,b){
	if(a[0] < b[0]) return -1
	if(a[0] > b[0]) return 1;
	else return 0;
}
```

> Runtime: 76 ms, faster than 68.80% of JavaScript online submissions for Merge Intervals.
>
> Memory Usage: 36.8 MB, less than 100.00% of JavaScript online submissions for Merge Intervals.
>
> Oh, My God!!!!!!!!!!!