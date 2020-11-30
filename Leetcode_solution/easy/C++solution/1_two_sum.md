# [Two Sum]( https://leetcode.com/problems/two-sum/ )

[toc]

> Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.
>
> You may assume that each input would have **exactly** one solution, and you may not use the same element twice.
>
> > Example:
> >
> > > 	Given nums = [2, 7, 11, 15], target = 9,
> > > 	Because nums[0] + nums[1] = 2 + 7 = 9,
> > > 	return [0, 1].

```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
    }
};
```



## solution : 快排+遍历寻找(双指针)

**注意的是，返回数组下标，所以需要拷贝一个副本。找到两个值，再在原数组中查找下标**

时间复杂度为O(nlogn) ——快排，空间复杂度为O(n)——需要复制一个副本

```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> cpy;
        cpy = nums;
        sort(cpy.begin(),cpy.end());
        int v1,v2;
        for(int i=0,j=(cpy.size()-1);i<j;){
        	if((cpy[i] + cpy[j]) > target)
        		j--;
        	else if((cpy[i] + cpy[j]) < target)
        		i++;
        	else{
        		v1 = cpy[i];
        		v2 = cpy[j];
        		break;
        	}
        }
        
        //寻找在原来数组中的下标
        vector<int> res;
        for(int i=0;i<nums.size();i++){
        	if(nums[i]==v1 || nums[i] == v2){
        		res.push_back(i);
        		if(res.size() == 2)
        			break;
        	}
        }
        return res;
    }
};
```

## Solution : 映射表

**注意的是：数组里面可能会有负数。不能直接打表**

```
//错误代码
#include <map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        vector<int> res;
        for(int i=0,len=nums.size();i<len;i++){
        	hash[nums[i]] = i;
        }
        
        for(int i=0,len=nums.size(); i<len;i++){
        	int val2 = target - nums[i];
        	
        	if(hash.find(val2) != hash.end()){
        		res.push_back(hash[val2]);
        		res.push_back(i);
        		return res;
        	}
        }
        return res;
    }
};
//错误代码
```

**坑：每个值只能使用一次！比如[3,2,4]  6  不能使用两次位置0； 另外：[3,3] 6 也要使用[0,1]**

**map也不能把两个值映射到同一个值，所以上面的代码，试图直接先把所有的值映射到hash中，再查找，是有问题的**

```
#include <map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        vector<int> res;
      
        for(int i=0,len=nums.size(); i<len;i++){
        	int val2 = target - nums[i];
        	if(hash.find(val2) != hash.end() ){	//在映射表中找到了这个值
        		res.push_back(hash[val2]);
        		res.push_back(i);
        		return res;
        	}
        	hash[nums[i]] = i;	//映射表中没有target - nums[i]。那么将当前值nums[i]加入映射表。
        }
        return res;
    }
};
```

>  说明：比如nums = [3,2,4],  target = 6; hash表为空
>
> i = 0;   nums[0] = 3, target - nums[i] = 3 ; hash[3]不存在 。导致的变化：hash[3] = 0;
>
> i= 1; nums[1] = 2, target - nums[i] = 4; hash[4] 不存在。导致的变化： hash[2] = 1;
>
> i=2; nums[2] = 4, target - nums[2] = 2; hash[2]存在，导致变化：res = [hash[2],i] = [1,2]。返回

>再比如nums[3,3,3,3], target = 6; hash为空
>
>i=0; nums[0] = 3, target - nums[i] = 3, hash[3]不存在。导致变化： hash[3] = 0;
>
>i=1；nums[1] = 3, target - nums[1] = 3, hash[3]=0。导致变化：res = [hash[3],i] = [0,1]

**此方法总结:** 将nums从头到尾扫描。假设val是可能的值，第一遍扫描忽略了它。但是不要紧，将val加入到hash中，之后如果有target - val2 == val 的话，那么还是会找到val。并且它之前已经映射到hash中。

### 优化

1. 不需要vector<int> res; 直接返回两个数字即可
2. unordered_map 查找效率更高。[map与unordered_map]( https://zhuanlan.zhihu.com/p/48066839 )结论是： **在需要有序性或者对单次查询有时间要求的应用场景下，应使用map，其余情况应使用unordered_map。**

```

#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        
        for(int i=0,len=nums.size(); i<len;i++){
        	int val2 = target - nums[i];
        	if(hash.find(val2) != hash.end() ){	//在映射表中找到了这个值
        		return {hash[val2],i};
        	}
        	hash[nums[i]] = i;
        }
        return {};
    }
};
```



