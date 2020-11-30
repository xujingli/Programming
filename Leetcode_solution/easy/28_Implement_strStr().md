

#  28. Implement strStr() 

[toc]

> Implement [strStr()](http://www.cplusplus.com/reference/cstring/strstr/).
>
> Return the index of the first occurrence of needle in haystack, or **-1** if needle is not part of haystack.
>
> **Example 1:**
>
> ```
> Input: haystack = "hello", needle = "ll"
> Output: 2
> ```
>
> **Example 2:**
>
> ```
> Input: haystack = "aaaaa", needle = "bba"
> Output: -1
> ```
>
> ```
> var strStr = function(haystack, needle) {
>     
> };
> ```
>
> **Clarification:**
>
> What should we return when `needle` is an empty string? This is a great question to ask during an interview.
>
> For the purpose of this problem, we will return 0 when `needle` is an empty string. This is consistent to C's [strstr()](http://www.cplusplus.com/reference/cstring/strstr/) and Java's [indexOf()](https://docs.oracle.com/javase/7/docs/api/java/lang/String.html#indexOf(java.lang.String)).

# solution

双指针

```
//时间复杂度O(n^2) 空间复杂度O(1)
var strStr = function(haystack, needle) {
    if(needle === "")
    	return 0;
    let i=0,j=0;
    let len1 = haystack.length,len2 = needle.length;
    
    if(len1 < len2)	//这一步判断非常重要
    	return -1;
    
    while(i<len1){
    	if(i + len2 > len1)	//当不可能有那么长的子串后，返回-1，很好的剪枝操作
    		return -1;
    	let tmp = i;
    	if(haystack[i] === needle[j]){
    		//从此i,j位置往后循环，一旦不相等，则j回到0，i回到刚刚位置。
    		//如果等到j到达末尾也没有遇到异常情况，则是他的子串，返回i的位置
    		while(j<len2){ //由于剪枝操作，只有j有超出len2的可能
    			if(haystack[i] === needle[j]){	//共同向后移动一个位置
    				i++;
    				j++;
    			}
    			else{
    				j = 0;
    				break;
    			}
    		}
    		if(j === len2)
    			return tmp
    	}
    	i = tmp + 1;
    }
    return -1	//没有操作，返回-1，说明没有这个子串
};
```

**以上解法，冗余而且很不优雅**

## Solution：暴力枚举

思考： “aaaabbbabab”(11)  "baba"(4)

```
var strStr = function(haystack, needle) {
	let m=haystack.length,n=needle.length;
	
	if(m<n) return -1; 	//剪枝
	
	for(let i=0;i<=m-n;i++){
		let j=0;
		for(;j<n;j++)
			if(haystack[i+j] != needle[j])
				break;
				
		if(j == n)
			return i;
	}
	return -1
};
```



## Solution: KMP

[KMP算法理解_阮一峰](http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html)

