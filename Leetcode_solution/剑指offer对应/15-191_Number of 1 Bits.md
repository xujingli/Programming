# [191. Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)

[toc]

> Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the [Hamming weight](http://en.wikipedia.org/wiki/Hamming_weight)).
>
> **Example 1:**
>
> ```
> Input: 00000000000000000000000000001011
> Output: 3
> Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
> ```
>
> **Example 2:**
>
> ```
> Input: 00000000000000000000000010000000
> Output: 1
> Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
> ```
>
> **Example 3:**
>
> ```
> Input: 11111111111111111111111111111101
> Output: 31
> Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
> ```
>
> 
>
> **Note:**
>
> - Note that in some languages such as Java, there is no unsigned integer type. In this case, the input will be given as signed integer type and should not affect your implementation, as the internal binary representation of the integer is the same whether it is signed or unsigned.
> - In Java, the compiler represents the signed integers using [2's complement notation](https://en.wikipedia.org/wiki/Two's_complement). Therefore, in **Example 3** above the input represents the signed integer `-3`.
>
> **Follow up**:
>
> If this function is called many times, how would you optimize it?
>
> ```javascript
> /**
>  * @param {number} n - a positive integer
>  * @return {number}
>  */
> var hammingWeight = function(n) {
> };		
> ```

## solution

```javascript
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    let count = 0
    while(n){
        ++count;
        n = (n-1) & n //位操作时，自动将数值转换为32位整数进行操作
    }
    return count;
};
```



## 更优解法

```javascript
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
const hammingWeight = function (n) {
  return n.toString(2).replace(/0/g, '').length
};
```







## 书上的指导 P100

> 实现一个函数，输入一个整数，输出该整数二进制表示中1的个数。

思路一：

> 先判断整数二进制表示中最右边一位是不是1；接着把输入的整数右移一位，此时原来处于右二数就被移到了最右边了，再判断是不是1； 这样每次移动一位，指导整个整数变成0为止。
>
> 判断最右边的数是不是1的方法：只要把整数和1做 位与 运算，看结果是不是0就知道了
>
> **注意**：除法的效率要比移位运算低得多。所以直接除以2的效率是很低的。
>
> **但是** 如果输入一个负数，比如 0x8000000 右移一位就会变成0xC0000000. 如果一直做右移运算，那么最终整个数字就会变成0xFFFFFFFF，于是程序就陷入了死循环。 
>
> 解决方案一： JS中的 “>>>” 操作应该可以解决这个问题。
>
> 解决方案二：不右移输入的数字。首先把n和1做与运算，判断n的最低位是不是1。接着把1左移一位得到2，再和n做与运算，就能判断右边第二位是不是1.......这样的做法，32位的整数就需要循环32次。

思路二：

> 分析把一个数减去1的情况。如果一个整数不等于0，那么该整数的二进制表示中至少有一位是1.
>
> 假设这个数最右边一位是1，那么减去1时，最后一位变成0，而其他所有位都保持不变。
>
> 如果最后一位不是1。假设最右边的1 在第m位。那么减去1时，第m位由1变为0. 而第m位之后的所有0都变成1.第m位之前的所有位保持不变。 比如：1100. 减去1后变为 1011
>
> 接下来把这个整数和它减去1后的结果做与运算。->相当于把原来整数最右边的1变成0. 比如： 1100 和 1011做与操作，得到: 1000

```
function NumberOf1(n){
	let count = 0;
	while(n){
		++count;
		n = (n-1) & n;
	}
	return count;
}
```



## 相关：

**用一条语句判断一个整数是不是2的整数次方。**

> 一个整数如果是2的整数次方，那么它的二进制表示中有且只有一位是1，而其他位都为0.
>
> 按照前面的分析，把这个整数减去1之后，再和它自己做与运算，这个整数中唯一的1就变为0



**输入两个整数m和n.计算需要改变m的二进制表示中的多少位才能得到n。（海明距离）**

>分为两步：1、计算两个数的异或  2、统计异或结果中1的位数。

