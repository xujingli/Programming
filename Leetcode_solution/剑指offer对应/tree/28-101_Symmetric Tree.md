# [101. Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)

> Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
>
> For example, this binary tree `[1,2,2,3,4,4,3]` is symmetric:
>
> ```
>     1
>    / \
>   2   2
>  / \ / \
> 3  4 4  3
> ```
>
>  
>
> But the following `[1,2,2,null,3,null,3]` is not:
>
> ```
>     1
>    / \
>   2   2
>    \   \
>    3    3
> ```
>
>  
>
> **Note:**
> Bonus points if you could solve it both recursively and iteratively.
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
>  * @return {boolean}
>  */
> var isSymmetric = function(root) {
>     
> };
> ```



## solution 1

剑指offer的解释没有看懂，参考这一[链接](https://www.tianmaying.com/tutorial/LC101)

在对树的**深度优先搜索**中进行判断，即使用一个额外的指针`root2`：

- 当用于深度优先搜索的指针移动到左子树中时，`root2`就对应的移动到右子树当中
- 当用于深度优先搜索的指针移动到右子树中时，`root2`就对应的移动到左子树当中

这样，在`root2`不能够对应一个值，或者`root1`和`root2`指向的节点的值不一样的时候，我们就可以知道这棵树是不对称的。而当这样的过程正常的结束后，如果没有产生过错误，那么就说明这棵树是对称的~

```javascript
var isSymmetric = function(root) {
    if(root === null) return true
    return Symmetric(root,root);
    
    function Symmetric(root1,root2){
        if(root1.val !== root2.val) return false;
        if(root1.left){
            if(root2.right === null) return false; //不对称
            if(!Symmetric(root1.left,root2.right)) return false;
        }
        if(root1.right){
            if(root2.left === null) return false;
            if(!Symmetric(root1.right,root2.left)) return false;
        }
        return true;
    }
};

Runtime: 52 ms, faster than 96.79% of JavaScript online submissions for Symmetric Tree.
Memory Usage: 35.6 MB, less than 100.00% of JavaScript online submissions for Symmetric Tree.
```

## 更简洁写法：

A tree is symmetric if the left subtree is a mirror reflection of the right subtree.

![Push an element in stack](https://leetcode.com/media/original_images/101_Symmetric.png)

Therefore, the question is: when are two trees a mirror reflection of each other?

Two trees are a mirror reflection of each other if:

1. Their two roots have the same value.
2. The right subtree of each tree is a mirror reflection of the left subtree of the other tree.

![Push an element in stack](https://leetcode.com/media/original_images/101_Symmetric_Mirror.png)

This is like a person looking at a mirror. The reflection in the mirror has the same head, but the reflection's right arm corresponds to the actual person's left arm, and vice versa.

The explanation above translates naturally to a recursive function as follows.

```javascript
var isSymmetric = function(root) {
    return isMirror(root,root)
    
    function isMirror(root1,root2){
        if(root1 === null && root2 === null) return true; // 终止条件
        if(root1 === null || root2 === null) return false;
        return (root1.val === root2.val) && isMirror(root1.right,root2.left) && isMirror(root1.left,root2.right); // 子问题
    }
};
```

>一个问题只要同时满足以下**3** 个条件，就可以用递归来解决。
>
>1. 一个问题的解可以分解为几个子问题的解。
>
>何为子问题 ？就是数据规模更小的问题。 比如，前面说的你想知道你排在第几位的例子，你要知道，自己在哪一排的问题，可以分解为每个人在哪一排这样一个子问题。
>
>2. 这个问题分解之后的子问题，除了数据规模不同，求解思路完全一样
>
>比如前面说的你想知道你排在第几的例子，你求解自己在哪一排的思路，和前面一排人求解自己在哪一排的思路，是**一模一样**的。
>
>3. 存在递归终止条件
>
>比如前面说的你想知道你排在第几的例子，第一排的人不需要再继续询问任何人，就知道自己在哪一排，也就是 `f(1) = 1`，这就是递归的终止条件，找到终止条件就会开始进行“归”的过程。

