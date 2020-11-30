# [905_Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity/)

> Given an array `A` of non-negative integers, return an array consisting of all the even elements of `A`, followed by all the odd elements of `A`.
>
> You may return any answer array that satisfies this condition.
>
> **Example 1:**
>
> ```
> Input: [3,1,2,4]
> Output: [2,4,3,1]
> The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
> ```
>
>  **Note:**
>
> 1. `1 <= A.length <= 5000`
> 2. `0 <= A[i] <= 5000`
>
> ```
> /**
>  * @param {number[]} A
>  * @return {number[]}
>  */
> var sortArrayByParity = function(A) {
>     
> };
> ```



## solution 1

```
1. 遍历，如果是奇数，后面的数字向前移动一位，最后一位放上这个奇数
复杂度:O(n^2)
```

## Solution 2

双指针：前后指针。

一个指向第一个元素，另一个指向最后一个元素。

首元素只向后移动，尾元素只向前移动。相遇时停止。

当首尾指针指向不同元素：

​	首元素一直向后移动，直到遇到奇数；

​		尾元素一直向前移动，直到遇到偶数；

​			交换两个元素。

时间复杂度：O(n) ; 空间复杂度O(1)

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParity = function(A) {
    let len = A.length;
    if(len <= 1) return A;
    
    let start = 0, end = len-1;
    while(start < end){
        while((A[start] & 1) === 0 && start < end){ // 偶数
            ++start
        } // start指向一个奇数
        while((A[end] & 1) === 1 && start < end){ // 奇数
            --end;
        } // end指向一个偶数
        
        // let tmp = A[start]
        // A[start] = A[end]
        // A[end] = tmp
        if(start !== end){
            A[start] ^= A[end]
            A[end] ^= A[start]
            A[start] ^= A[end] // 最快方法
        }
        ++start
        --end
    }
   	return A;
};
```



## 最简洁Solution

偶数排在前面，奇数排在后面。

偶数%2  ===  0; 奇数 % 2 === 1

时间复杂度:O(nlogn)，空间复杂度O(1)

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParity = function(A) {
    return A.sort((a, b) => { return a % 2 - b % 2; }); 
}; 
```

以下代码更为简洁：

但是filter两次遍历了数组，复杂度为O(2*n),空间复杂度为O(n)

```javascript
var sortArrayByParity = function(A) {
    return [...A.filter(v => v % 2 === 0), ...A.filter(v => v % 2 !== 0)];
};
```



## 高效 JS Solutions:

The `unshift()` method adds one or more elements to the beginning of an array and returns the new length of the array.

```javascript
var sortArrayByParity = function(A) {
    const result =[];
    A.forEach((x)=> x % 2 === 0 ? result.unshift(x) : result.push(x));
    return result;
};
```



疑惑： JavaScript是如何实现这些函数的？V8? 复杂度情况如何？

