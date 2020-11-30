# 53. Maximum Subarray 

[toc]

> Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
>
> **Example:**
>
> ```
> Input: [-2,1,-3,4,-1,2,1,-5,4],
> Output: 6
> Explanation: [4,-1,2,1] has the largest sum = 6.
> ```
>
> ```
> var maxSubArray = function(nums) {
>     
> };
> ```

[参考]( https://blog.csdn.net/lengxiao1993/article/details/52303492 )

## Solution: Kadane 算法

算法描述：

- 遍历该数组， 遍历之前设置了两个变量 max_ending_here, max_so_far
- 其中 max_ending_here 用于记录遍历过程中， 如果把当前元素 x 强制规定为子数列的最后一个元素时， 能找到的最大子数列的总和是多少
- 由于真正的最大子数列必然存在一个结尾元素， 所以只需要从每个位置计算出的 max_ending_here 中， 找到最大值， 就是全局的最大子数列的值。
- max_so_far 用于记录遍历过程中， 所发现的最大的 max_ending_here
- 一次遍历之后， 变量 max_so_far 中存储的即为最大子片段的和值。

```
var maxSubArray = function(nums) {
    let max_ending_here = max_so_far = nums[0]
    for(let i=1,len = nums.length;i<len;i++){
    	max_ending_here = Math.max(nums[i], max_ending_here + nums[i])
    	max_so_far = Math.max(max_so_far,max_ending_here)
    }
    return max_so_far;
};
```

**另一种写法**

```
//但是空间复杂度就低于前者了！
var maxSubArray = function(nums) {
    let n = nums.length;
    let dp = []
    dp[0] = nums[0]
    let max = dp[0]
    
    for(let i=1;i<n;i++){
    	dp[i] = Math.max(nums[i], dp[i-1] + nums[i])
    	max = Math.max(max,dp[i])
    }
    return max;
};
```



