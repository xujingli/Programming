# [46. Permutations](https://leetcode.com/problems/permutations/)

> Given a collection of **distinct** integers, return all possible permutations.
>
> **Example:**
>
> ```
> Input: [1,2,3]
> Output:
> [
>   [1,2,3],
>   [1,3,2],
>   [2,1,3],
>   [2,3,1],
>   [3,1,2],
>   [3,2,1]
> ]
> ```
>
> ```javascript
> /**
>  * @param {number[]} nums
>  * @return {number[][]}
>  */
> var permute = function(nums) {
>     
> };
> ```

## Solution

第一步，求所有可能出现在第一个位置的字符，即把第一个字符和后面的所有字符交换。

第二步，固定第一个字符，求后面所有字符的排列。

​		然后，仍然把后面的字符分成两部分......

递归的思路。

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    let res = [];
    
    let permutations = (current, remaining) => {
        if(remaining.length <= 0) res.push(current.slice());
        else{
            for(let i=0;i<remaining.length;i++){
                current.push(remaining[i]);
                permutations(current.slice(),)
            }
        }
    }
    permutations([],nums);
    return res;
};
```

