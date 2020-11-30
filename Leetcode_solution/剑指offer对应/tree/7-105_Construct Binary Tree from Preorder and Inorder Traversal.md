# [105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

[toc]

> Given preorder and inorder traversal of a tree, construct the binary tree.
>
> **Note:**
> You may assume that duplicates do not exist in the tree.
>
> For example, given
>
> ```
> preorder = [3,9,20,15,7]
> inorder = [9,3,15,20,7]
> ```
>
> Return the following binary tree:
>
> ```
>  3
> / \
> 9  20
>  /  \
> 15   7
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
>  * @param {number[]} preorder
>  * @param {number[]} inorder
>  * @return {TreeNode}
>  */
> var buildTree = function(preorder, inorder) {
>     
> };
> ```
>



# 特别注意

题目中说，不存在数值相同的节点，才采用如下的方法。

如果存在？



## solution 1

以下是之前写过的C语言代码

```C++
//给定一颗二叉树的 先序遍历序列 和 中序遍历序列
//当前先序序列区间是[preL,preR],中序遍历区间是[inL,inR] 
node* Create(int preL,int preR,int inL,int inR){
	if(preL > preR){
		return NULL;		//先序序列的长度小于等于0时，直接返回 
	}
	node* root = new node;	//新建一个节点，用来存放当前二叉树的根节点
	root->data = pre[preL];	//新节点的数据域为根节点的值
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==pre[preL]){	//在中序遍历序列中寻找in[k] == pre[preL]的节点 
			break;
		}
	} 
	int numLeft = k-inL;		//左子树的节点个数
	
	//则左子树：先序遍历区间是[preL+1,preL+numLeft] 中序遍历区间是[inL,k-1]
	//返回左子树的根节点指针，赋值给root的左指针
	root->lchild = create(preL+1,preL+numLeft,inL,k-1);
	
	//右子树：先序遍历区间是[preL+numLeft+1,preR] 中序遍历区间是[k+1,inR]
	//返回右子树的根节点指针，赋值给root的右指针
	root->rchild = create(preL+numLeft+1,preR,k+1,inR); 
	
	return root;		//返回根节点 
}
```

核心思想是，找到每次找到根节点，然后分出左子树的“中序遍历和前序遍历的元素”、右子树的“中序遍历和前序遍历的元素”

受到这段代码的启发，有如下的JS代码

```javascript
var buildTree = function(preorder, inorder) {
    if(preorder.length === 0 ) return null;
    const root = new TreeNode(preorder[0]);
    
    const index = inorder.indexOf(preorder[0]); //则左子树包含index个节点。所以，对于前序序列，[1,index]属于左子树，[index+1,end]为右子树；对于中序遍历节点，[0,index-1]属于左子树，[index,end]为右子树
    root.left = buildTree(preorder.slice(1,index+1),inorder.slice(0,index));
    root.right = buildTree(preorder.slice(index+1),inorder.slice(index+1));
    
    return root;
};
```

> Runtime: 108 ms, faster than 45.27% of JavaScript online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
>
> Memory Usage: 127.2 MB, less than 50.00% of JavaScript online submissions for Construct Binary Tree from Preorder and Inorder Traversal.

缺陷：1、时间复杂度可能是O(n^2)； 

## 更优时间复杂度

分析：上面的indexOf操作，复杂度为O(n)，也就是寻找inorder中的元素，如果把这一搜索过程降为O(1)，则会大大节省时间。——map

有因为遍历的顺序原因，所以前序遍历序列总是依次向后的。

```javascript
let preindex,map;
var buildTree = function(preorder, inorder) {
    preindex = 0;
    map = {};
    inorder.forEach((el,i) => {
    	map[el] = i;
    })
    return dfs(0, inorder.length-1,preorder);
};

let dfs = (left, right, preorder) => {
	if(left > right) return null;
	let root = new TreeNode(preorder[preindex++]);
	
	let index = map[root.val];
	root.left = dfs(left, index-1, preorder);
	root.right = dfs(index+1,right, preorder);
	return root;
}
```

总结：用map代替每次的indexOf寻找，可使得时间复杂度降低到O(n)

> Runtime: 60 ms, faster than 99.63% of JavaScript online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
>
> Memory Usage: 36.9 MB, less than 100.00% of JavaScript online submissions for Construct Binary Tree from Preorder and Inorder Traversal.

```javascript
var buildTree = function(preorder, inorder) {
    let preindex = 0,map = {};
    inorder.forEach((ele,i) => {
        map[ele] = i;
    })
    return DFS(0,inorder.length-1);
    
    function DFS(left,right){ // inorder的左右
        if(left > right) return null;
        let root = new TreeNode(preorder[preindex++]);
        let index = map[root.val];
        root.left = DFS(left,index-1);
        root.right = DFS(index+1,right);
        return root;
    }
};
```



**以下第二种写法没有看懂！**

### 第二种写法：

[Simple O(n) without map](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34543/Simple-O(n)-without-map)

```javascript
var buildTree = function(preorder, inorder) {
    p = i = 0
    build = function(stop) {
        if (inorder[i] != stop) {
            var root = new TreeNode(preorder[p++])
            root.left = build(root.val)
            i++
            root.right = build(stop)
            return root
        }
        return null
    }
    return build()
};
```

> `preorder: [1, 2, 4, 5, 3, 6]
> inorder: [4, 2, 5, 1, 6, 3]`
>
> 重建树的方法是这样的：
>
> 1. Use the first element of `preorder`, the `1`, as root.
> 2. Search it in `inorder`.
> 3. Split `inorder` by it, here into `[4, 2, 5]` and `[6, 3]`.
> 4. Split the rest of `preorder` into two parts as large as the `inorder` parts, here into `[2, 4, 5]` and `[3, 6]`.
> 5. Use `preorder = [2, 4, 5]` and `inorder = [4, 2, 5]` to add the left subtree.
> 6. Use `preorder =`[3, 6]`and`inorder = `[6, 3]` to add the right subtree.
>

