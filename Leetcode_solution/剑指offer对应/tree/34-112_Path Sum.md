# [112. Path Sum](https://leetcode.com/problems/path-sum/)

> Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
>
> **Note:** A leaf is a node with no children.
>
> **Example:**
>
> Given the below binary tree and `sum = 22`,
>
> ```
>       5
>      / \
>     4   8
>    /   / \
>   11  13  4
>  /  \      \
> 7    2      1
> ```
>
> return true, as there exist a root-to-leaf path `5->4->11->2` which sum is 22.
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
>  * @param {number} sum
>  * @return {boolean}
>  */
> var hasPathSum = function(root, sum) {
>     
> };
> ```
>

## Solution 1

递归需要多加练习。

本题主要要注意：

1. 题目条件说的是：从根节点到达叶节点。而不是到达图中的某个中间节点
2. "||"操作是“有真则真，全假则假”，所以用于本题

```javascript
var hasPathSum = function(root, sum) {
    if(root === null) return false;
    if(root.left === null && root.right === null){ // 到达叶节点
        return  sum - root.val === 0;
   	}
    return hasPathSum(root.left,sum - root.val) || hasPathSum(root.right,sum - root.val); 
};
```

