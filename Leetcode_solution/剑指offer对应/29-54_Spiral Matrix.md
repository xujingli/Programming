# [54. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)

> Given a matrix of *m* x *n* elements (*m* rows, *n* columns), return all elements of the matrix in spiral order.
>
> **Example 1:**
>
> ```
> Input:
> [
>  [ 1, 2, 3 ],
>  [ 4, 5, 6 ],
>  [ 7, 8, 9 ]
> ]
> Output: [1,2,3,6,9,8,7,4,5]
> ```
>
> **Example 2:**
>
> ```
> Input:
> [
>   [1, 2, 3, 4],
>   [5, 6, 7, 8],
>   [9,10,11,12]
> ]
> Output: [1,2,3,4,8,12,11,10,9,5,6,7]
> ```
>
> ```javascript
> /**
>  * @param {number[][]} matrix
>  * @return {number[]}
>  */
> var spiralOrder = function(matrix) {
>     
> };
> ```
>

## Solution

This is a very simple and easy to understand solution. I traverse right and increment rowBegin, then traverse down and decrement colEnd, then I traverse left and decrement rowEnd, and finally I traverse up and increment colBegin.

时间复杂度：O(n*m) 空间复杂度O(n *m)

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    let res = [];
    if(matrix.length === 0) return res;
    
    let rowBegin = 0, rowEnd = matrix.length-1, colBegin = 0, colEnd = matrix[0].length-1;
    
    while(rowBegin <= rowEnd && colBegin <= colEnd){
        // Traverse Right
        for(let i=colBegin;i<=colEnd;i++)
            res.push(matrix[rowBegin][i]);
        rowBegin++;
        
        // Traverse Down
        for(let i=rowBegin;i<=rowEnd;i++)
            res.push(matrix[i][colEnd]);
        colEnd--;
        
        // Traverse right
        if(rowBegin <= rowEnd) // 因为上面以后rowBegin++操作
        	for(let i=colEnd;i>=colBegin;i--)
            	res.push(matrix[rowEnd][i])
        rowEnd--;
        
        // Traverse up
        if(colBegin <= colEnd)
        	for(let i=rowEnd;i>=rowBegin;i--)
            	res.push(matrix[i][colBegin])
        colBegin++;
    }
    return res;
};
```

## Solution 2

削苹果

```
spiral_order([[1, 2, 3],
                [4, 5, 6],
                [7, 8, 9]])

= [1, 2, 3] + spiral_order([[6, 9],
                            [5, 8],
                            [4, 7]])

= [1, 2, 3] + [6, 9] + spiral_order([[8, 7],
                                     [5, 4]])

= [1, 2, 3] + [6, 9] + [8, 7] + spiral_order([[4],
                                              [5]])

= [1, 2, 3] + [6, 9] + [8, 7] + [4] + spiral_order([[5]])

= [1, 2, 3] + [6, 9] + [8, 7] + [4] + [5] + spiral_order([])

= [1, 2, 3] + [6, 9] + [8, 7] + [4] + [5] + []

= [1, 2, 3, 6, 9, 8, 7, 4, 5]
```

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    let res = [];
    while(matrix.length !== 0 && matrix[0].length !== 0){
        res = res.concat(matrix.shift());
        matrix = leftRotate(matrix);
    }
    return res;
    
    function leftRotate(matrix){ // 将矩阵向左旋转90度
        let n = matrix.length
        let m = (matrix[0] instanceof Array) ? matrix[0].length : 1;
        
        let output = Create2DArray(m);
        for(let i=m-1;i>=0;i--)
            for(let j=0;j<n;j++){
                output[m-i-1][j] = matrix[j][i]
            }
        return output
    }
    function Create2DArray(rows){
        let arr = [];
        for(let i=0;i<rows;i++)
            arr[i] = [];
        return arr;
    }
};
```

