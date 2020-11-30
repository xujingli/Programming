# [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/description/)

[toc]

> Write a function to find the longest common prefix string amongst an array of strings.
>
> If there is no common prefix, return an empty string `""`.
>
> **Example 1:**
>
> ```
> Input: ["flower","flow","flight"]
> Output: "fl"
> ```
>
> **Example 2:**
>
> ```
> Input: ["dog","racecar","car"]
> Output: ""
> Explanation: There is no common prefix among the input strings.
> ```
>
> **Note:**
>
> All given inputs are in lowercase letters `a-z`.
>
> ```
> /**
>  * @param {string[]} strs
>  * @return {string}
>  */
> var longestCommonPrefix = function(strs) {
> 	
> };
> ```

## solution:

把第一个字符串当做当前公共子串cp. 当cp.length == 0时，返回""

从第二个开始，查找它与cp的公共前缀的长度。

最后返回cp

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
	let len = strs.length
    if(len === 0) return ""
    if(len === 1) return strs[0]

	var cp = strs[0];
	for(let i=1;i<len;i++){
		let count = 0;
		let temp = strs[i];
		let templen = temp.length
		let cplen = cp.length   
		
		for(let j = 0;j<cplen && j<templen;j++){
			if(temp[j] === cp[j])
				count++;
			else
				break;
		}
		
		if(count === 0)
			return "";
		else
			cp = cp.slice(0,count);
	}
	return cp;
};
```

## solution: reduce

```javascript
var longestCommonPrefix = function(strs) {
	if(strs === undefined || strs.length === 0) return "";
    
    return strs.reduce((prev, next) =>{
    	let i = 0;
    	while(prev[i] && next[i] && prev[i] === next[i]) i++;
    	return prev.slice(0,i);
    })
};
```



## LeetCode Solution小结

### 水平扫描： 

$LCP(S_1...S_2) = LCP(LCP(LCP(S_1,S_2),S_3),...S_n)$

算法思想：寻找$LCP(S_1...S_i)$当它为空时，算法结束。在n次迭代后，返回$LCP(S_1...S_n)$

```javascript
var longestCommonPrefix = function(strs) {
	if(strs.length === 0) return "";
	let prefix = strs[0];
	for(let i=1;i<strs.length;i++){
		while(strs[i].indexOf(prefix) != 0){
			prefix = prefix.slice(0,prefix.length-1);
			if(prefix.length ===0) return "";
		}
	}
	return prefix;
}; 
```

### 垂直扫描

**如果最后一个$S_n$很短，那么前面的比较有些是不必要的** 优化方法是: **按列扫描**

此方法即便在最差情况下也和水平扫描一样。其他情况下一定优于水平扫描。

```javascript
var longestCommonPrefix = function(strs) {
	if(strs.length ===0) return "";
	let c;
	for(let i=0;i<strs[0].length;i++){
		c = strs[0][i];
		for(let j=1;j<strs.length;j++){
			if(i === strs[j].length || strs[j][i] !=c)
				return strs[0].slice(0,i);
		}
	}
	return strs[0];
};
```

### 分治法

```javascript
var longestCommonPrefix = function(strs) {
	if(strs.length ===0) return "";
	return longestCommonPrefix(strs,0,strs.length-1);
};

var longestCommonPrefix = function(strs,l,r){
	if(l === r)	return strs[l];
	else{
		let mid = (l+r) / 2;
		let lcpLeft = longestCommonPrefix(strs,1,mid);
		let lcpRight= longestCommonPrefix(strs,mid+1,r);
		return commonPrefix(lcpLeft, lcpRight);
	}
}

var commonPrefix(left,right){
	
}
```



