# [9 Palindrome Number ]( https://leetcode.com/problems/palindrome-number/ )

[toc]

>Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
>
>**Example 1:**
>
>```
>Input: 121
>Output: true
>```
>
>**Example 2:**
>
>```
>Input: -121
>Output: false
>Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
>```
>
>**Example 3:**
>
>```
>Input: 10
>Output: false
>Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
>```
>
>**Follow up:**
>
>Could you solve it without converting the integer to a string?
>
>```
>class Solution {
>public:
>    bool isPalindrome(int x) {
>
>        }
>    };
>    ```
>
>

**注意点**

- 函数参数是int类型，但是要考虑到$2^{31}-1 = 2147483647$ 。反过来就会越界！不能直接计算回文数然后比较
- 所以适合转换成string型或者其他方法



## C中[char、char\*] 与C++中[char\*与string]

1. C语言中：char *定义一个字符串。

   **c中的char\* 定义字符串，不能改变字符串内的字符的内容，但却可以把另外一个字符串付给它 **

   ```
   #include "stdio.h"
    
   int main()
   {
   	char* str1 = "hello world\n";
   	str1 = "aa";
   	str1[1] = "a";	//报错
   
   	printf("%s",str1);
   }
   ```

2. C++中，char* 定义一个字符串（与C不同的是，需要包含头文件<iostream>）;**string是封装好的字符串类（本质是一个类）**需要include <string> 它是C++STL的一部分。

   ```
   // C++中使用char*定义字符串，同样不能改变字符串内的字符的内容，但却可以把另外一个字符串付给它
   #include<iostream>
   using namespace std;
   int main()
   {
   	char* pstr = "hello world";
   	pstr = "aa";
   	pstr[1] = "a";	//报错
    
   	cout<<pstr<<endl;
   }
   ```

   ```
   //C++中string的定义字符串，同样不能改变字符串内的字符，但却可以把另外一个字符串付给它
   #include<iostream>
   #include<string>
    
   using namespace std;
    
   int main()
   {
   	string str1;
   	str1= "hello world";
   	str1="aa";
   	str1[1]="a";
   	cout<<str1<<endl;
   }
   ```

   

3. [**C++ 字符串 string 类成员函数与方法 小结**]( https://blog.csdn.net/u013630349/article/details/46438399 )
   
   -  begin() end() //提供类似STL的迭代器支持 ——本题可能要用到
   
4. [C++字符串处理方法char* 与 string对比 的总结]( https://haoqchen.site/2018/09/09/string-and-char/ )

   

## solution: 转换成字符串

由于string内部较复杂，所以使用char *数组

**字符串** 注意初始化操作。初始化为'\\0'。sprintf(char数组，数字)可以转换为字符串。

```
#include <string>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x ==0) return true;
        
        char reverse[15], original[15];
        memset(reverse,'\0',sizeof(reverse));
        sprintf(original,"%d",x);	//将数字转为字符串
        int i = 0;
        while(x){
        	reverse[i++] = (x % 10 + 48);
        	x /= 10;
        }
        
        if(strcmp(reverse,original) == 0) return true;
        else return false;
    }
};
```

## Solution:  比较前一半和后一半

**比如** 12**21** 只需要转换**21**到12再比较

**关键是**如何确定“一半”位置在哪里。

空间上只用了一个int数字。时间上：除以10然后迭代的次数:$log_{10}n$

```
class Solution {
public:
    bool isPalindrome(int x) {
		if(x<0 || (x % 10 ==0 && x!=0)) //末尾为0肯定是不行的！
			return false;
		int revertedNumber = 0;
		//0->出循环
		//1->0 1 ->出循环
		//10->1 0 -> 0 1->出循环。而此时x=0 revertedNumber=1 会返回true.所以应该把结尾为0的数字首先去除，防止干扰。
		//123321 ->12332  1 ->1233 12-> 123 123->出循环
		//1234321->123432 1 ->12343 12->1234 123->123 1234->出循环
		while(x > revertedNumber){
			revertedNumber = revertedNumber * 10 + x % 10;
			x /= 10;
		}
		if(x == revertedNumber || x == revertedNumber / 10)
			return true;
		return false;
    }
};
```

**小结：首先去除一些不可能的解是很必要的，也防止这些特殊解，干扰算法**