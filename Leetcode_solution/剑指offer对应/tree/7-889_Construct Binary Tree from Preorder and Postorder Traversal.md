# [889. Construct Binary Tree from Preorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/)

> Return any binary tree that matches the given preorder and postorder traversals.
>
> Values in the traversals `pre` and `post` are distinct positive integers.
>
>  **Example 1:**
>
> ```
>Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
> Output: [1,2,3,4,5,6,7]
> ```
> 
> **Note:**
>
>  - `1 <= pre.length == post.length <= 30`
>- `pre[]` and `post[]` are both permutations of `1, 2, ..., pre.length`.
> - It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.
>
> ```javascript
> /**
>  * Definition for a binary tree node.
> * function TreeNode(val) {
>  *     this.val = val;
>  *     this.left = this.right = null;
>  * }
>  */
> /**
>  * @param {number[]} pre
>  * @param {number[]} post
>  * @return {TreeNode}
>  */
> var constructFromPrePost = function(pre, post) {
>     
> };
> ```

## Solution 1

```javascript
var constructFromPrePost = function(pre, post) {
    let map = new Map();
    for(let i=0;i<post.length;i++)
        map.set(post[i],i)
    return DFS(0,pre.length-1,0,post.length-1);
    
    function DFS(preStart,preEnd,postStart,postEnd){
        if(preStart > preEnd || postStart>postEnd)
            return null;
        let root = new TreeNode(pre[preStart]);
        if(preStart + 1 <= preEnd){
            let deltaIndex = map.get(pre[preStart+1]) - postStart;
            root.left = DFS(preStart+1, preStart+1+deltaIndex, postStart, postStart+deltaIndex);
            root.right = DFS(preStart+1+deltaIndex+1, preEnd, postStart+deltaIndex+1, postEnd-1);
        }
        return root;
    }
};
```

​	