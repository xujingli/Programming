# [230. Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/)

> Given a binary search tree, write a function `kthSmallest` to find the **k**th smallest element in it.
>
> **Note:**
> You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
>
> **Example 1:**
>
> ```
> Input: root = [3,1,4,null,2], k = 1
>    3
>   / \
>  1   4
>   \
>    2
> Output: 1
> ```
>
> **Example 2:**
>
> ```
> Input: root = [5,3,6,2,4,null,null,1], k = 3
>        5
>       / \
>      3   6
>     / \
>    2   4
>   /
>  1
> Output: 3
> ```
>
> **Follow up:**
> What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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
>  * @param {number} k
>  * @return {number}
>  */
> var kthSmallest = function(root, k) {
>     
> };
> ```
>

## Solution 1 中序遍历的第k个元素

时空复杂度都是O(n)

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
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(root, k) {
    let data = [];
    inorder(root);
    return data[k-1];
    
	function inorder(root){
        if(root === null) return;
        inorder(root.left);
        data.push(root.val);
        inorder(root.right);
    }
};
```

**改进：空间复杂度O(1)，时间复杂度O(n)**

```javascript
var kthSmallest = function(root, k) {
    let data;
    inorder(root);
    return data;
    
	function inorder(root){
        if(root === null) return;
        inorder(root.left);
        k--;
        if(k === 0){
            data = root.val;
            return;
        }
        inorder(root.right);
    }
};
Runtime: 60 ms, faster than 95.00% of JavaScript online submissions for Kth Smallest Element in a BST.
Memory Usage: 39.2 MB, less than 90.91% of JavaScript online submissions for Kth Smallest Element in a BST.
```

