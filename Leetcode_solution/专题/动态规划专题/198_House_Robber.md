#  198. [House Robber](https://leetcode.com/problems/house-robber/ )

[toc]

> You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.
>
> Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight **without alerting the police**.
>
> **Example 1:**
>
> ```
> Input: [1,2,3,1]
> Output: 4
> Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
>              Total amount you can rob = 1 + 3 = 4.
> ```
>
> **Example 2:**
>
> ```
> Input: [2,7,9,3,1]
> Output: 12
> Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
>              Total amount you can rob = 2 + 9 + 1 = 12.
> ```
>
> ```
> var rob = function(nums) {
>     
> };
> ```



## solution 动态规划

状态转移方程为：$dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]) ( i > 1)  (dp[1] = nums[0] ,dp[0] = 0)$ 

$dp[i+1] = max(dp[i], dp[i-1]+nums[i]) ( i > 1)  (dp[0] = 0,dp[1]=nums[0])$ 

**注意：这里dp数组比nums数组多一位** 

```
//空间复杂度是O(n) 时间是O(n)
var rob = function(nums) {
	let len=nums.length
	if(len == 0)
		return 0;
		
	let dp = [] //长度为len+1
	dp[0] = 0
	dp[1] = nums[0]
	for(let i=1;i<len;i++){
		dp[i+1] = Math.max(dp[i],dp[i-1]+nums[i])
	}
	return dp[len];
};
```

**参考下面的优化方法后的代码**

```
//空间复杂度是O(1) 时间是O(n)
var rob = function(nums) {
	let len=nums.length
	if(len == 0)
		return 0;

	let prev1 = 0,prev2 = nums[0] //分别表示dp[i-1] 和 dp[i]
	for(let i=1;i<len;i++){
		let tmp = prev2
		prev2 = Math.max(prev2,prev1+nums[i])
		prev1 = tmp
	}
	return prev2;
};
```



## [Solution参考]( https://leetcode.com/problems/house-robber/discuss/?currentPage=1&orderBy=most_votes&query= )

[From good to great. How to approach most of DP problems.]( https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems. )

### 找出递归关系

**rob(i) = Math.max( rob(i - 2) + currentHouseValue, rob(i - 1) ) **

### 递归(top-down)

```
public int rob(int[] nums) {
    return rob(nums, nums.length - 1);
}
private int rob(int[] nums, int i) {
    if (i < 0) {
        return 0;
    }
    return Math.max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
}
```

此过程存在很多重复计算的问题，需要优化

### 递归+备忘(top-down)

```
int[] memo;	//备忘
public int rob(int[] nums) {
    memo = new int[nums.length + 1];
    Arrays.fill(memo, -1);
    return rob(nums, nums.length - 1);
}

private int rob(int[] nums, int i) {
    if (i < 0) {
        return 0;
    }
    if (memo[i] >= 0) {
        return memo[i];
    }
    int result = Math.max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
    memo[i] = result;
    return result;
}
```

这就用了O(n)时间，和O(n)空间；再尝试去除递归栈

### 迭代 + 备忘（bottom-up）

```
public int rob(int[] nums) {
    if (nums.length == 0) return 0;
    int[] memo = new int[nums.length + 1];
    memo[0] = 0;
    memo[1] = nums[0];
    for (int i = 1; i < nums.length; i++) {
        int val = nums[i];
        memo[i+1] = Math.max(memo[i], memo[i-1] + val);
    }
    return memo[nums.length];
}
```

这就是我第一次想到的解决方案。

### 迭代 + 2个变量(bottom-up)

注意到上面只用到了memo[i]和memo[i-1]，所以没有必要设置一个数组，只需要两个变量即可。

 这种优化是在斐波那契数列的创建和其他一些问题 中也常用到

```
public int rob(int[] nums) {
    if (nums.length == 0) return 0;
    int prev1 = 0;
    int prev2 = 0;
    for (int num : nums) {
        int tmp = prev1;
        prev1 = Math.max(prev2 + num, prev1);
        prev2 = tmp;
    }
    return prev1;
}
```

