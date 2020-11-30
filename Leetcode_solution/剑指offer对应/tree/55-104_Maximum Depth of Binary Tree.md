# [104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

> Given a binary tree, find its maximum depth.
>
> The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
>
> **Note:** A leaf is a node with no children.
>
> **Example:**
>
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
> return its depth = 3.
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
>  * @return {number}
>  */
> var maxDepth = function(root) {
>     
> };
> ```
>
> 

## Solution 深度遍历

```javascript
var maxDepth = function(root) {
    let depth = 0;
    DFS(root,0);
    return depth;
    
    function DFS(root,level){
        if(root === null){
            if(depth < level) depth = level;
            return;
        } 
        DFS(root.left,level+1)
        DFS(root.right,level+1)
    }
};
```



```javascript
var maxDepth = function(root) {
    if(root === null) return 0;
    
    let nLeft = maxDepth(root.left);
    let nRight = maxDepth(root.right);
    
    return (nLeft > nRight) ? (nLeft+1) : (nRight+1);
};

更完美--->
    
var maxDepth = function(root) {
    if(root === null) return 0;
    return Math.max(maxDepth(root.left),maxDepth(root.right)) + 1
};
```

