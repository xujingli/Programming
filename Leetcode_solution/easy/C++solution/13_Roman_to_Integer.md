# [13. Roman to Integer]( https://leetcode.com/problems/roman-to-integer/ )

[toc]

>Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.
>
>```
>Symbol       Value
>I             1
>V             5
>X             10
>L             50
>C             100
>D             500
>M             1000
>```
>
>For example, two is written as `II` in Roman numeral, just two one's added together. Twelve is written as, `XII`, which is simply `X` + `II`. The number twenty seven is written as `XXVII`, which is `XX` + `V` + `II`.
>
>Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used: 
>
>- `I` can be placed before `V` (5) and `X` (10) to make 4 and 9. 
>- `X` can be placed before `L` (50) and `C` (100) to make 40 and 90. 
>- `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.
>
>Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
>
>**Example 5:**
>
>```
>Input: "MCMXCIV"
>Output: 1994
>Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
>```

```
class Solution {
public:
    int romanToInt(string s) {
        
    }
};
```

## 题意解读：

**此题读不懂题意就会绕很大弯路**：只有六种数字组合IV、IX、XL、XC、CD、CM()。结合七个单独的数字，可以构成一些组合。求这些组合实际表示的数字。

## Solution:

**由题意知：通常左大右小；如果左边的数字小于右边的数字，那么就要右边数字减去左边这个值加到sum**:

>  比如：MCMXCIVI   M>=C没有问题 sum+= M，向后跳一步; C<M 有问题 sum += (M-C)，向后跳两步; X <C有问题 sum+=(C-X)，向后跳两步; I <V有问题，sum+=(V-I)，向后跳两步。I是最后一个元素，直接加上它。
>
>  时间复杂度：O(n)  空间复杂度:O(n);

```
#include <unordered_map>
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int sum = 0;
        
        for(int i=0,len = s.length();i<len;){
        	if((i+1) < len){
        		if(mp[s[i]] >= mp[s[i+1]]){ //向后跳一步
        			sum += mp[s[i++]];
        		}
        		else{	//向后跳两步
        			sum += (mp[s[i+1]] - mp[s[i]]);
        			i += 2;
        		}
        	}
        	else{   //最后一个元素
        		sum += mp[s[i++]];
        	}
        }
        
        return sum;
    }
};
```



### 方法改进1：

由题可知：总共有6+7种组合。那么对于string，**优先查找**两个字母的组合，如果不存在两字母组合，则查找单个字母的值。两个字母 i+=2;一个字母i+=1.

```
class Solution {
public:
    int romanToInt(string s) {
    	int sum = 0;
        for(int i=0,len = s.length();i<len;i++){
        	if(mp.find(s.substr(i,2)) != mp.end()){ //s.substr(pos,n) 返回pos后面n个字符组成的串
        		sum += mp[s.substr(i++,2)]; //注意++操作，相当于向后跳了两格
        	}
        	else{
        		sum += mp[s.substr(i,1)];
        	}
        }
        return sum;
    }
private:
	unordered_map<string, int> mp = { {"I",1}, {"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",1000},{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900}};
};
```



**但是时空速度还是太慢！！**

### 方法改进2：

**简单思想：当小的罗马数字出现在大的罗马数字前一个的时候，sum减去这个小的值**

**字符在计算机中以ASCII码的形式存储，当字符作为数组下标时，其表示的下标值为该字符的ASCII码的十进制值**

```
class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        int map[256];
        map['I']=1;map['V']=5;map['X']=10;map['L']=50;map['C']=100;map['D']=500;map['M']=1000;
		
		for(int i=0,len = s.length();i<len;i++){
			if((i+1) < len && map[s[i]] < map[s[i+1]]) sum -= map[s[i]];
			else sum += map[s[i]];
		}
		return sum;
    }
};
```
