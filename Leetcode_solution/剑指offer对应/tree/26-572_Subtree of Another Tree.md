# [572. Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/)

> Given two non-empty binary trees **s** and **t**, check whether tree **t** has exactly the same structure and node values with a subtree of **s**. A subtree of **s** is a tree consists of a node in **s** and all of this node's descendants. The tree **s** could also be considered as a subtree of itself.
>
> **Example 1:**
> Given tree s:
>
> ```
>      3
>     / \
>    4   5
>   / \
>  1   2
> ```
>
> Given tree t:
>
> ```
>    4 
>   / \
>  1   2
> ```
>
> Return **true**, because t has the same structure and node values with a subtree of s.
>
> 
>
> **Example 2:**
> Given tree s:
>
> ```
>      3
>     / \
>    4   5
>   / \
>  1   2
>     /
>    0
> ```
>
> Given tree t:
>
> ```
>    4
>   / \
>  1   2
> ```
>
> Return **false**.
>
> ```javascript
> /**
>  * Definition for a binary tree node.
>  * function TreeNode(val) {
>  *     this.val = val;
>  *     this.left = this.right = null;
>  * }
>  */
> /**
>  * @param {TreeNode} s
>  * @param {TreeNode} t
>  * @return {boolean}
>  */
> var isSubtree = function(s, t) {
>     
> };
> ```

## Solution

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} s
 * @param {TreeNode} t
 * @return {boolean}
 */
var isSubtree = function(s, t) {
    let result = false;
    if(s && t){
        if(s.val === t.val) result = isEqual(s,t)
        if(!result) result = (isSubtree(s.left,t) || isSubtree(s.right,t))
    }
    return result;
};

let isEqual = function(s,t){
	if(s === null && t === null)
        return true;
    else if(s && t && s.val === t.val)
        return (isEqual(s.left,t.left) && isEqual(s.right,t.right))
    else
        return false;
}

Runtime: 76 ms, faster than 85.03% of JavaScript online submissions for Subtree of Another Tree.
Memory Usage: 38.6 MB, less than 100.00% of JavaScript online submissions for Subtree of Another Tree.
```

