# [103. Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

> Given a binary tree, return the *zigzag level order* traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
>
> For example:
> Given binary tree `[3,9,20,null,null,15,7]`,
>
> ```
>     3
>    / \
>   9  20
>     /  \
>    15   7
> ```
>
> 
>
> return its zigzag level order traversal as:
>
> ```
> [
>   [3],
>   [20,9],
>   [15,7]
> ]
> ```
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
>  * @param {TreeNode} root
>  * @return {number[][]}
>  */
> var zigzagLevelOrder = function(root) {
>     
> };
> ```
>

## Solution  DFS

参考：32-102_Binary Tree Level Order Traversal的第二个解法。只要不同行采取不同的插入方式即可。

偶数行(0 2 4...)从尾插入，奇数行(1 3 5...)从头插入。

```javascript
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var zigzagLevelOrder = function(root) {
    let res = []
    traverse(root,0);
    return res;
    
    function traverse(root,level){
        if(root === null) return;
        if(level>=res.length)
            res[level] = [];
        if(level % 2 === 0)
        	res[level].push(root.val);
        else
            res[level].unshift(root.val);
        traverse(root.left,level+1);
        traverse(root.right,level+1);
    }
};
```

