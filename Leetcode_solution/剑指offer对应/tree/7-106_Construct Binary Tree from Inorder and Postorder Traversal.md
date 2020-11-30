# [106. Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

> Given inorder and postorder traversal of a tree, construct the binary tree.
>
> **Note:**
> You may assume that duplicates do not exist in the tree.
>
> For example, given
>
> ```
> inorder = [9,3,15,20,7]
> postorder = [9,15,7,20,3]
> ```
>
> Return the following binary tree:
>
> ```
>     3
>    / \
>   9  20
>     /  \
>    15   7
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
>  * @param {number[]} inorder
>  * @param {number[]} postorder
>  * @return {TreeNode}
>  */
> var buildTree = function(inorder, postorder) {
>     
> };
> ```

## Solution 1

```javascript
var buildTree = function(inorder, postorder) {
    let len = postorder.length;
    if(len === 0) return null;
    let root = new TreeNode(postorder[len-1]);
    let index = inorder.indexOf(root.val);
    root.left = buildTree(inorder.slice(0,index),postorder.slice(0,index));
    root.right = buildTree(inorder.slice(index+1),postorder.slice(index,len-1))
    return root;
};
```

## 更优解

```javascript
var buildTree = function(inorder, postorder) {
    let map = {},postindex = postorder.length-1;
    inorder.forEach((el,i)=>{
        map[el] = i;
    })
    return DFS(0,inorder.length-1);
    
    function DFS(left,right){
        if(left > right) return null;
        let root = new TreeNode(postorder[postindex--]);
        let index = map[root.val]
        root.right = DFS(index+1,right);
        root.left = DFS(left,index-1); // 注意这里颠倒了顺序，因为观察后续遍历序列可知，依次为右子树的根节点。
        return root;
    }
};
```

