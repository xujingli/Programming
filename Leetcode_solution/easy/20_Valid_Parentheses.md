# [20 Valid Parentheses](https://leetcode.com/problems/valid-parentheses/description/)

[toc]

> Given a string containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.
>
> An input string is valid if:
>
> 1. Open brackets must be closed by the same type of brackets.
> 2. Open brackets must be closed in the correct order.
>
> Note that an empty string is also considered valid.
>
> **Example 1:**
>
> ```
> Input: "()"
> Output: true
> ```
>
> **Example 2:**
>
> ```
> Input: "()[]{}"
> Output: true
> ```
>
> **Example 3:**
>
> ```
> Input: "(]"
> Output: false
> ```
>
> **Example 4:**
>
> ```
> Input: "([)]"
> Output: false
> ```
>
> **Example 5:**
>
> ```
> Input: "{[]}"
> Output: true
> ```
>
> ```
> var isValid = function(s) {
>     
> };
> ```



## Solution : 模拟堆栈

用一个字符串模拟堆栈

```
//时间复杂度 O(N) 空间复杂度O(N)
var isValid = function(s) {
    let len = s.length
    
    let stack = "";
    for(let i=0;i<len;i++){
    	let len = stack.length
    	if(s[i] === "(" || s[i] === "[" || s[i] === "{")
    		stack += s[i] //直接相加
    	else if( (s[i] === "]" && stack[len-1] ==="[" ) || (s[i] === ")" && stack[len-1] ==="(") ||(s[i] === "}" && stack[len-1] ==="{") )
    		stack = stack.slice(0,len-1) //去除最后一个元素（出栈）
    	else
    		return false
    }
    if(stack.length != 0)
    	return false
    return true
};
```



## 优化

```
var isValid = function(s) {
    var st = []
    for(var l of s)
    	if(( i = "({[]})".indexOf(l) ) > -1)
    		if(st[st.length-1]+i === 5)
    			st.length--;
    		else
    			st.push(i);
   	return st.length === 0
};
```

