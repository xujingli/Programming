#  121. Best Time to Buy and Sell Stock 

[toc]

> Say you have an array for which the $i^{th}$ element is the price of a given stock on day *i*.
>
> If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
>
> Note that you cannot sell a stock before you buy one.
>
> **Example 1:**
>
> ```
> Input: [7,1,5,3,6,4]
> Output: 5
> Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
>              Not 7-1 = 6, as selling price needs to be larger than buying price.
> ```
>
> **Example 2:**
>
> ```
> Input: [7,6,4,3,1]
> Output: 0
> Explanation: In this case, no transaction is done, i.e. max profit = 0.
> ```

>```
>var maxProfit = function(prices) {
>    
>};
>```

## Solution:暴力模拟

```
//空间O(1) 时间 O(n^2)
var maxProfit = function(prices){
	let i =0,j=1,len = prices.length;
	if(len<=1) return 0;	//没有可供交易的
	
	let max = prices[j] - prices[i]
	while(i<=len-2){
		while(j<=len-1){
			if(max < (prices[j] - prices[i]))
				max = prices[j] - prices[i];
			j++;
		}
		i++;
		j=i+1;
	}
	if(max < 0) return 0; //一天比一天价格低 没有交易
	return max;
}
```



## Solution：一次循环

维护三个值：目前的最最低谷，最低谷之后的最大值。前两者之差最大值

```
//空间O(1) 时间 O(n)
var maxProfit = function(prices){
	if(prices.length < 2) return 0;
	
	let minprice=prices[0]
	let maxprice = minprice;
	let max = 0;
	let len = prices.length
	
	for(let i=1;i<len;i++){
		if(prices[i]<minprice){
			minprice = prices[i];
			maxprice = minprice;
		}
		else if(prices[i]>maxprice){
			maxprice = prices[i];
			if([maxprice-minprice] > max)
				max = maxprice-minprice
		}
	}
	
	return max;
}
```



## Solution Kadane算法

The logic to solve this problem is same as "max subarray problem" using `Kadane's Algorithm`. 

All the straight forward solution should work, but if the interviewer twists the question slightly by giving the ***difference array of prices***, Ex: for `{1, 7, 4, 11}`, if he gives `{0, 6, -3, 7}`, you might end up being confused.

Here, the logic is to calculate the difference (`maxCur += prices[i] - prices[i-1]`) of the original array, and find a contiguous subarray giving maximum profit. If the difference falls below 0, reset it to zero.

```
var maxProfit = function(prices) {
	let maxCur = 0, maxSoFar=0
	for(let i=1,len=prices.length;i<len;i++){
		maxCur += (prices[i]-prices[i-1])	//maxCur = current maximum value
		maxCur = Math.max(0,maxCur);
		maxSoFar = Math.max(maxCur,maxSoFar);//maxSoFar = maximum value found so far
	}
	return maxSoFar;
};
```

