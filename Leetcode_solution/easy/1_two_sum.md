# [Two Sum]( https://leetcode.com/problems/two-sum/ )

[toc]

> Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.
>
> You may assume that each input would have **exactly** one solution, and you may not use the same element twice.
>
> > Example:
> >
> > > 	Given nums = [2, 7, 11, 15], target = 9,
> > > 	Because nums[0] + nums[1] = 2 + 7 = 9,
> > > 	return [0, 1].

```javascript
var twoSum = function(nums, target) {
    
};
```

## solution: 快排 + 前后指针

- 对数组进行快速排序(复杂度为O(nlogn))，然后在有序数组寻找。利用前后双指针。

- 但是输出的是原来数组的下标，而不是排好序的数组下标。

- - 这样排序就不能直接在原来的数组上，需要复制一个副本。空间复杂度为O(n)

```javascript
var twoSum = function(nums, target) {
    let cpy = [...nums];
	cpy.sort((a,b) => a-b);
	let len = cpy.length;
	let i=0,j=len-1;
	
	while(i<j){
		if(cpy[i]+cpy[j] > target){
			j--
		}else if(cpy[i]+cpy[j]<target){
			i++;
		}else{
			break;
		}
	} //找到排序后数组中的两个下标。两个值是cpy[i],cpy[j]
    
    let res = [],count = 0;
    for(let k=0;k<len;k++){
        if(nums[k] === cpy[i] || nums[k] === cpy[j]){
            res[count++] = k;
            if(count === 2)
                break;
        }
    }
    return [res[0],res[1]];
};
```

## solution 映射表

1. **JS map方法**  见C++ solution中的此题

   key: 数组值 ， value: 数组下标

```javascript
var twoSum = function(nums, target) {
    var mp = new Map();
    for(let i = 0;i<nums.length;i++){
    	if(mp.has(target - nums[i]))
    		return [i,mp.get(target-nums[i])];
    	else
    		mp.set(nums[i],i);
    }
};
```

2. **JS object**

   1. JS中数组表示有序数据的集合，而对象表示无序数据的集合。

      ```
      var a={"城市":"北京","面积":16800,"人口":1600}; 
      a["城市"]//输出 "北京"
      ```

```javascript
let twoSum = function (nums, target) {
    let hash = {};
    for(let i=0;i<nums.length;i++){
        let n = nums[i];
        if(hash[target-n] !== undefined){
            return [i,hash[target-n]];
        }
        hash[n] = i;
    }
    return;
};
```

### 综合最优解 : hasOwnProperty

```javascript
let twoSum = function (nums, target) {
    let hash = {};
    for(let i=0;i<nums.length;i++){
        let n = nums[i];
        if(hash.hasOwnProperty(target-n)){
            return [i,hash[target-n]];
        }
        hash[n] = i;
    }
    return;
};
√ Accepted
  √ 29/29 cases passed (48 ms)
  √ Your runtime beats 99.78 % of javascript submissions
  √ Your memory usage beats 92.54 % of javascript submissions (34.4 MB)
```

