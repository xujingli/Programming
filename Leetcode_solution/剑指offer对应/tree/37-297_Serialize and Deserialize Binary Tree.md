# [297. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)

> Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
>
> Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
>
> **Example:** 
>
> ```
> You may serialize the following tree:
> 
>     1
>    / \
>   2   3
>      / \
>     4   5
> 
> as "[1,2,3,null,null,4,5]"
> ```
>
> **Clarification:** The above format is the same as [how LeetCode serializes a binary tree](https://leetcode.com/faq/#binary-tree). You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
>
> **Note:** Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
>
> ```javascript
> /**
>  * Definition for a binary tree node.
>  * function TreeNode(val) {
>  *     this.val = val;
>  *     this.left = this.right = null;
>  * }
>  */
> 
> /**
>  * Encodes a tree to a single string.
>  *
>  * @param {TreeNode} root
>  * @return {string}
>  */
> var serialize = function(root) {
>     
> };
> 
> /**
>  * Decodes your encoded data to tree.
>  *
>  * @param {string} data
>  * @return {TreeNode}
>  */
> var deserialize = function(data) {
>     
> };
> 
> /**
>  * Your functions will be called as such:
>  * deserialize(serialize(root));
>  */
> ```
>

## Solution 1 （有缺陷）

类似于“由前序遍历 中序遍历 重构二叉树” 或者 “后序遍历 中序遍历 重构二叉树”。

将二叉树转换为前序遍历 中序遍历 序列； 再由二者转换回去

```javascript
// 前序遍历 + 中序遍历
var serialize = function(root) {
    let res = ""
    inorder(root);
    preorder(root);
    return res.slice(0,res.length-1); // 删除最后一个 ","
    
    function inorder(root){
        if(root === null ) return;
        inorder(root.left)
        res += root.val
        res += ","
        inorder(root.right)
    }
    function preorder(root){
        if(root === null) return;
        res += root.val
        res += ","
        preorder(root.left)
        preorder(root.right)
    }
};

var deserialize = function(data) {
    let arr = data.split(",")
    let inorder = arr.slice(0,arr.length/2);
    let preorder = arr.slice(arr.length/2)
    let preindex = 0,map = {};
    inorder.forEach((el,i) => {
        map[el] = i;
    })
    return DFS(0,inorder.length-1);
    
    function DFS(left,right){
        if(left > right) return null;
        let root = new TreeNode(preorder[preindex++]);
        let index = map[root.val]
        root.left = DFS(left,index-1)
        root.right = DFS(index+1,right);
        return root;
    }
};
```

**缺陷：** 1. 该方法要求二叉树不能有重复的节点。比如: “1，2，2” ——报错



```javascript
var serialize = function(root) {
    let data = [];
    
    function preorder(root){
        if(root === null){
            data.push(null)
            return;
        }
        data.push(root.val)
        preorder(root.left);
        preorder(root.right);
    }
    
    preorder(root);
    return data;
};

var deserialize = function(data) {    
    function DFS(){ // 1 功能是 根据前序遍历data 输出一个二叉树
        if(data.length === 0) return; // 2 结束条件
        
        let val = data.shift();
        if(val === null) return null;        
        let node = new TreeNode(val);
        node.left = DFS();
        node.right = DFS();
        
        return node;
    }
	return DFS();
};
```

## 结论：

对递归求解二叉树相关问题，非常不熟悉



## 参考：

前序遍历得到："1,2,4,#,#,#,3,5,#,#,6,#,#"

1. 第一个读出的数字是1，这是根节点的值。
2. 接下来读出的是2，根据前序遍历规则，这是根节点的左子节点的值
3. 同理，4是2的左子节点的值
4. 接下来读出两个"#"，表明4的左右子节点均为null，因此4是一个叶节点。
5. 接下来回退到值为2的节点，重建它的右节点。 由于它的下一个字符是"#"，所以2的右子节点为null。再回退到值为1的节点，重建它的右子节点。 —— (最重要的部分)
6. 下一个字符是"3", 因此1的右子节点是3
7. 3的左子节点是5
8. 接下来读出两个"#"，说明5是一个叶子节点，回退到3，3的右子节点是6。由于6后面是两个"#"，所以6是叶子节点。

