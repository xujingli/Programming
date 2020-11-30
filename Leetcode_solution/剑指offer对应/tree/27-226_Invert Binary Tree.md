# [226. Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)

> Invert a binary tree.
>
> **Example:**
>
> Input:
>
> ```
>      4
>    /   \
>   2     7
>  / \   / \
> 1   3 6   9
> ```
>
> Output:
>
> ```
>      4
>    /   \
>   7     2
>  / \   / \
> 9   6 3   1
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
>  * @return {TreeNode}
>  */
> var invertTree = function(root) {
>     
> };
> ```

# Solution

依次反转每一层的节点。

```javascript
var invertTree = function(root) {
    if(root && (root.right || root.left)){
        //swap(root.left,root.right);
        let tmp = root.left;
        root.left = root.right;
        root.right = tmp
    }else
        return root;
    if(root.right) invertTree(root.right)
    if(root.left) invertTree(root.left)
    
    return root;
};
```



## 更高效

每次返回左右节点，交换它们

```javascript
var invertTree = function(root) {
    if (root == null) {
        return root;
    }
    
    var left = invertTree(root.left);
    var right = invertTree(root.right);
    
    root.right = left;
    root.left = right;
    
    return root;
};
Runtime: 52 ms, faster than 78.97% of JavaScript online submissions for Invert Binary Tree.
Memory Usage: 33.7 MB, less than 100.00% of JavaScript online submissions for Invert Binary Tree.
```



