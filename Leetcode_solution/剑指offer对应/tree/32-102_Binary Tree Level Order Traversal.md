# [102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)

> Given a binary tree, return the *level order* traversal of its nodes' values. (ie, from left to right, level by level).
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
> return its level order traversal as:
>
> ```
> [
>   [3],
>   [9,20],
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
> var levelOrder = function(root) {
>     
> };
> ```
>

## Solution 1

**层次遍历写法** 

```javascript
var levelOrder = function(root) {
    let arr = [];
    arr.push(root)
    while(arr.length !== 0){
        let front = arr.shift();
        console.log(front.val)
        if(front.left) arr.push(front.left);
        if(front.right) arr.push(front.right);
    }
};
```



### 广度遍历

遍历一层后，再到下一层。

```javascript
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if(root === null) return [];
    
    let q = [root]; 
    let res = [];
    while(q.length !== 0){
        let len = q.length;
        let tmp = []
        for(let i=0;i<len;i++){
            let current = q.shift();
            if(current.left) q.push(current.left);
            if(current.right) q.push(current.right);
            tmp.push(current.val);
        }
        res.push(tmp);
    }
    return res;
};
```

### 深度遍历 DFS

```javascript
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    let res = []
    traverse(root,0);
    return res;
    
    function traverse(root,level){
        if(root === null) return;
        if(level>=res.length)
            res[level] = [];
        res[level].push(root.val);
        traverse(root.left,level+1);
        traverse(root.right,level+1);
    }
};
```



