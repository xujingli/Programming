# [107. Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)

> Given a binary tree, return the *bottom-up level order* traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
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
> return its bottom-up level order traversal as:
>
> ```
> [
>   [15,7],
>   [9,20],
>   [3]
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
> var levelOrderBottom = function(root) {
>     
> };
> ```
>

## Solution 1 : 反转数组 array reverse()

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrderBottom = function(root) {
    let res = [];
    Traverse(root,0);
    return res.reverse()
    
    function Traverse(root,level){
        if(root === null) return;
        if(level >= res.length)
            res[level] = [];
        res[level].push(root.val);
        Traverse(root.left,level+1)
        Traverse(root.right,level+1)
    }
};
Runtime: 52 ms, faster than 92.77% of JavaScript online submissions for Binary Tree Level Order Traversal II.
Memory Usage: 34.7 MB, less than 100.00% of JavaScript online submissions for Binary Tree Level Order Traversal II.
```

## 反转数组之外的方法 BFS

就是把每一层的数值，放到res的开头，使用unshift()

```javascript
var levelOrderBottom = function(root) {
	let queue = [root];
	let res = [];
    if(root === null) return res;
    while(queue.length !== 0){
        let len = queue.length;
        let tmp = []
        for(let i=0;i<len;i++){
            let front = queue.shift()
            if(front.left) queue.push(front.left)
            if(front.right) queue.push(front.right)
            tmp.push(front.val)
        }
        res.unshift(tmp);
    }
    return res;
};
```

## DFS

```javascript
var levelOrderBottom = function(root) {
    let res = [];
    Traverse(root,0);
    return res
    
    function Traverse(root,level){
        if(root === null) return;
        if(level >= res.length)
            res.unshift([]) // 在res头部增加一个数组 res.length += 1
            //res[level] = [];
        // res[level].push(root.val);
        res[res.length - level -1].push(root.val)
        Traverse(root.left,level+1)
        Traverse(root.right,level+1)
    }
};
```

