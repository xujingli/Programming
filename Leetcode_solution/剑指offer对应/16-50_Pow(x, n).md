# [50. Pow(x, n)](https://leetcode.com/problems/powx-n/)

[toc]

> Implement [pow(*x*, *n*)](http://www.cplusplus.com/reference/valarray/pow/), which calculates *x* raised to the power *n* (x^n).
>
> **Example 1:**
>
> ```
> Input: 2.00000, 10
> Output: 1024.00000
> ```
>
> **Example 2:**
>
> ```
> Input: 2.10000, 3
> Output: 9.26100
> ```
>
> **Example 3:**
>
> ```
> Input: 2.00000, -2
> Output: 0.25000
> Explanation: 2^(-2) = 1/(2^2) = 1/4 = 0.25
> ```
>
> **Note:**
>
> - -100.0 < *x* < 100.0
> - *n* is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
>
> ```javascript
> /**
>  * @param {number} x
>  * @param {number} n
>  * @return {number}
>  */
> var myPow = function(x, n) {
> };
> ```



## solution:

**思考：动态规划**：

注意：写成如下会超时。因为增加了时间和空间复杂度。

```javascript
    if((n & 1) === 0) //偶数
        return myPow(x,n/2) * myPow(x,n/2);
    else return myPow(x,(n-1)/2) * myPow(x,(n-1)/2) * x;
```

如下形式。节约时间和空间

```javascript
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if(n===0) return 1;
    if(n===1) return x;
    if(n<0) return 1/myPow(x,-1 * n);
    
    if((n & 1) === 0) //偶数
        return myPow(x * x,n/2);
    else return myPow(x * x,(n-1)/2) * x;
};
Runtime: 56 ms, faster than 82.35% of JavaScript online submissions for Pow(x, n).
Memory Usage: 33.8 MB, less than 82.35% of JavaScript online submissions for Pow(x, n).
```

更优雅的写法：

```javascript
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if(n===0) return 1;
    if(n===1) return x;
    if(n<0) return 1/myPow(x,-1 * n);
    return (n&1)===0 ? myPow(x*x,n/2) : myPow(x * x,(n-1)/2) * x;
};
```



### 也可有如下操作：！！

```javascript
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    return Math.pow(x,n)
};
```







## 书上参考 P110



动态规划