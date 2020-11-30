# [946. Validate Stack Sequences](https://leetcode.com/problems/validate-stack-sequences/)

> Given two sequences `pushed` and `popped` **with distinct values**, return `true` if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.
>
>  
>
> **Example 1:**
>
> ```
> Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
> Output: true
> Explanation: We might do the following sequence:
> push(1), push(2), push(3), push(4), pop() -> 4,
> push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
> ```
>
> **Example 2:**
>
> ```
> Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
> Output: false
> Explanation: 1 cannot be popped before 2.
> ```
>
>  
>
> **Note:**
>
> 1. `0 <= pushed.length == popped.length <= 1000`
> 2. `0 <= pushed[i], popped[i] < 1000`
> 3. `pushed` is a permutation of `popped`.
> 4. `pushed` and `popped` have distinct values.
>
> ```javascript
> /**
>  * @param {number[]} pushed
>  * @param {number[]} popped
>  * @return {boolean}
>  */
> var validateStackSequences = function(pushed, popped) {
>     
> };
> ```

## Solution 1

思路：

对于popped中所有的元素w. 

​	先查看栈arr的最后一个元素是不是w. 如果是的话，直接pop

​	如果不是的话，将pushed中w之前的元素全部入栈，然后弹出w

```javascript
var validateStackSequences = function(pushed, popped) {
    let arr = [];
    let i = 0;
    for(;i<popped.length;i++){
        let w = popped[i]
        if(arr.length !== 0 && arr[arr.length-1] === w){
            arr.pop();
        }
        else{
            while(pushed.length!==0){
                let p = pushed.shift();
                if(p === w) break;
                else arr.push(p);
            }
        }
    }
    if(i===popped.length && arr.length===0) return true;
    return false;
};
```



## Solution 2

对于pushed中的每个元素，依次入栈。如果当前元素等于popped的首元素，立刻出栈，否则就没有机会了。

然后检查栈顶元素是否等于popped[0]，一旦等于，立刻出栈，只有一次机会

```javascript
var validateStackSequences = function(pushed, popped) {
    let n = pushed.length;
    let arr = [];
    let j=0; // 指向popped的元素
    for(let i=0;i<n;i++){
        arr.push(pushed[i]); // 对于pushed中的每一个元素 入栈
        while(arr.length !==0 && arr[arr.length-1]===popped[j] && j < n){ // 栈顶元素等于 popped[0] 立刻出栈
            arr.pop();
            j++;
        }
    }
    return j === n
};
```



## Solution 3 

更Javascript

```javascript
var validateStackSequences = function(pushed, popped) {
    const stack = [];
    return pushed.reduce((popIndex, curr) => {
        stack.push(curr);
        while(stack.length && popIndex < pushed.length && popped[popIndex] === stack[stack.length - 1]) {
            stack.pop();
            popIndex++;
        }
        return popIndex;
    }, 0) === pushed.length;
};
```

