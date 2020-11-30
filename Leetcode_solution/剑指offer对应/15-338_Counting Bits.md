# [338. Counting Bits](https://leetcode.com/problems/counting-bits/)

[toc]

> Given a non negative integer number **num**. For every numbers **i** in the range **0 ≤ i ≤ num** calculate the number of 1's in their binary representation and return them as an array.
>
> **Example 1:**
>
> ```
> Input: 2
> Output: [0,1,1]
> ```
>
> **Example 2:**
>
> ```
> Input: 5
> Output: [0,1,1,2,1,2]
> ```
>
> **Follow up:**
>
> - It is very easy to come up with a solution with run time **O(n\*sizeof(integer))**. But can you do it in linear time **O(n)** /possibly in a single pass?
> - Space complexity should be **O(n)**.
> - Can you do it like a boss? Do it without using any builtin function like **__builtin_popcount** in c++ or in any other language.
>
> ```javascript
> /**
>  * @param {number} num
>  * @return {number[]}
>  */
> var countBits = function(num) {
>     
> };
> ```

## solution 

时间复杂度： O(n*sizeof(integer))   空间复杂度： O(n)

```javascript
/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
	if(num<0) return [];
	let res = [0]
	for(let i=1;i<=num;i++){
		res.push(NumberOf1(i))
	}
    return res;
    
	function NumberOf1(n){
        let count=0
        while(n){
            ++count;
            n = n & (n-1)
        }
        return count;
    }
};
```





## 时间复杂度O(n) ，空间复杂度O(n)的解法：

### 思考1：

注意到：可以记住前一个数m的状态。

- 如果下一个数是2的整数次方（含有唯一一个0 ，所以(n-1)&n ===0），则只有一个1 。
- 如果下一个数不是2的整数次方。
  - 如果前一个数的末尾是0，那么n的1的个数是前一个1的个数加一。
  - 那么如果前一个数的末尾是1  ???

比如：前一个数是101， 下一个数是110，不是2的整数次方，前一个数的末尾是0，所以1的个数和101的个数相同是2。   

如果前一个数的末尾是1，比如：10101111   、1011 (不可能是全1，因为已经被处理了) 怎么办？

如10101111 把倒数第一个0后面的所有1的个数减去得到2，再加上1，得到3 （10110000）

所以关键是：怎样找到一个数，右边第一个0之后的1的个数？？并且是O(1)复杂度？——不太可能有O(1)解

```javascript
/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    if(num<0) return []
    let res = [0]
    let priorcount = 0;
    for(let i=1;i<=num;i++){
        if(isIntegerPowerOf2(i)){
            res.push(1)
            priorcount = 1;
        }else {
            if(((i-1) & 1) === 0){ //前一个数末尾是0
                res.push(++priorcount)
            }else{
                
            }
        }
    }
    return res;
    
    function isIntegerPowerOf2(n){
        if((n & (n-1)) === 0)
            return true;
        return false
    }
};
```

### 思考2: 

10111 中1的个数，等于1011中1的个数加上1。

```javascript
/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    if(num < 0) return [];
    
  	let res = [0];
    for(let i=1;i<=num;i++){
        res.push(res[i>>1] + (i & 1))
    }
    return res;
};
```

这是最优写法

