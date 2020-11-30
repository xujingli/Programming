# [331. Verify Preorder Serialization of a Binary Tree](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/)

> One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as `#`.
>
> ```
>      _9_
>     /   \
>    3     2
>   / \   / \
>  4   1  #  6
> / \ / \   / \
> # # # #   # #
> ```
>
> For example, the above binary tree can be serialized to the string `"9,3,4,#,#,1,#,#,2,#,6,#,#"`, where `#` represents a null node.
>
> Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm **without reconstructing the tree.**
>
> Each comma separated value in the string must be either an integer or a character `'#'` representing `null` pointer.
>
> You may assume that the input format is always valid, for example it could never contain two consecutive commas such as `"1,,3"`.
>
> **Example 1:**
>
> ```
> Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
> Output: true
> ```
>
> **Example 2:**
>
> ```
> Input: "1,#"
> Output: false
> ```
>
> **Example 3:**
>
> ```
> Input: "9,#,#,1"
> Output: false
> ```
>
> ```javascript
> /**
>  * @param {string} preorder
>  * @return {boolean}
>  */
> var isValidSerialization = function(preorder) {
>     
> };
> ```
>

## Solution 1

二叉树: 出度 === 入度。

复习: 二叉树节点个数 $  k = n_0 + n_1 + n_2$ 并且 $ k = 2n_2 + n_1 +1 $ ；所以有 $n_0 = n_2 + 1$

If we treat `null`'s as leaves, then the binary tree will always be **full**. A full binary tree has a good property that `# of leaves = # of nonleaves + 1`. Since we are given a pre-order serialization, we just need to find the **shortest** prefix of the serialization sequence satisfying the property above. If such prefix does not exist, then the serialization is definitely invalid; otherwise, the serialization is valid if and only if the prefix is the **entire** sequence.

如果把null节点当作叶子节点，那么这颗二叉树永远都是“满二叉树”。那么$ n_0 $就是所有叶子几点个数，$n_2$就是所有非叶子节点个数.满足: $leaves === nonleaves + 1$ 

由于给定的是前序遍历序列，我们只需要找到满足上式的最短前缀序列。如果这个前缀序列不存在，返回false；当且仅当这个前缀等于整个序列的时候，返回true

```javascript
/**
 * @param {string} preorder
 * @return {boolean}
 */
var isValidSerialization = function(preorder) {
    let leaves=0,nonleaves=0;
    let arr = preorder.split(",");
    let i = 0;
    for(;i<arr.length && leaves !== nonleaves+1;i++){
        if(arr[i] !== "#") nonleaves++;
        else leaves++;
    }
    return i===arr.length && leaves === nonleaves+1 // "" "#" "#,#,#"
};
```

## Solution 2

想法二：思考空位

We just need to remember how many empty slots we have during the process. 

Initially we have one ( for the root ).

for each node we check if we still have empty slots to put it in.

- a null node occupies one slot.
- a non-null node occupies one slot before he creates two more. the net gain is one.

```javascript
/**
 * @param {string} preorder
 * @return {boolean}
 */
var isValidSerialization = function(preorder) {
    let arr = preorder.split(",")
    let i=0,slot=1;
    for(;i<arr.length ;i++){
        if(slot <= 0) return false; // 如果过程当中空位数量小于等于0，false
        if(arr[i] === "#")  slot--;
        else slot++;
    }
    return slot === 0;
};
```

## 改进：

思考三：思考 边

Intuition:
1. In pre-order traversal, first visit the node, then traverse on left subtree, finally traverse on right subtree.
2. As there are always symbols for null nodes, the non-nodes in string must have left child and right child.
3. One non-null node produces 2 edges and consumes 1 edge which increase edge by 1 in total.
   And one null node produces 0 edges and consumes 1 edge which decrease edge by 1 in total.
   Each time we meet a node, we decrease the edges by 1 as it consumes one edge.
   If it's not null, then we increase 2 edges.
   If it's null, we repeat the process.
   
   If the serialization string is correct, the final edge number is 0 as there no more redundant edges. 
   Otherwise it's not correct.

满二叉树，非空节点产生两条边，消耗一条边（根节点除外，所以代码中，边数初始化为1，根节点消耗一条边后产生两条边）。空节点消耗一条边。

```javascript
/**
 * @param {string} preorder
 * @return {boolean}
 */
var isValidSerialization = function(preorder) {
    let nodes = preorder.split(",")
    let edges = 1;
    for(let node of nodes){
        if(edges <= 0) return false; // 边没有被消耗就已经小于0
        edges -= 1;
        if(node !== "#") edges += 2;
    }
    return edges === 0;
};
```



## 小结：

思考二叉树的“出度和入度”