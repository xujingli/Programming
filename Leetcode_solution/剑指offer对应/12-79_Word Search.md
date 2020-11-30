# [79. Word Search](https://leetcode.com/problems/word-search/)

[toc]

> Given a 2D board and a word, find if the word exists in the grid.
>
> The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
>
> **Example:**
>
> ```
> board =
> [
>   ['A','B','C','E'],
>   ['S','F','C','S'],
>   ['A','D','E','E']
> ]
> 
> Given word = "ABCCED", return true.
> Given word = "SEE", return true.
> Given word = "ABCB", return false.
> ```
>
> ```javascript
> /**
>  * @param {character[][]} board
>  * @param {string} word
>  * @return {boolean}
>  */
> var exist = function(board, word) {
>     
> };
> ```

## solution：回溯法

```javascript
const dfs = (board, i,j,remain) => {
	if(remain.length === 0) return true;
	if(i<0 || i>=board.length || j<0 || j>=board[0].length) return false;
	if(board[i][j] !== remain[0]) return false;
	
	let ch = board[i][j];
	board[i][j] = '-';
	let result = ( dfs(board,i+1,j,remain.substring(1)) ||  dfs(board,i-1,j,remain.substring(1)) ||  dfs(board,i,j+1,remain.substring(1)) ||  dfs(board,i,j-1,remain.substring(1)))
	board[i][j] = ch;
	
	return result;
}

var exist = function(board, word) {
	if(board.length === 0 || word.length === 0) return false;
	
	for(let i=0;i<board.length;i++){
		for(let j=0;j<board[0].length;j++){
			if(dfs(board,i,j,word)) return true;
		}
	}
	return false;
};
```

> Runtime: 80 ms, faster than 75.18% of JavaScript online submissions for Word Search.
>
> Memory Usage: 42.3 MB, less than 46.15% of JavaScript online submissions for Word Search.

时间复杂度：O((mn*4)^l) 最差的情况是，每次都差一个字符没有形成最终的字符。那么并且每次都遍历了四个方向

 空间复杂度: O(l) 深度遍历时，使用了长度为l的堆栈。



## 更优写法 



```javascript
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function (board, word) {
    for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[0].length; j++) {
            if (exists(board, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
    function exists(board, i, j, index) {
        if (index === word.length) {
            return true;
        }
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] !== word[index]) {
            return false;
        }
        board[i][j] = '*';
        let retVal = exists(board, i - 1, j, index + 1) ||
            exists(board, i + 1, j, index + 1) ||
            exists(board, i, j - 1, index + 1) ||
            exists(board, i, j + 1, index + 1)
        board[i][j] = word[index];
        return retVal;
    }
};

```

> Runtime: 84 ms, faster than 59.50% of JavaScript online submissions for Word Search.
>
> Memory Usage: 37.7 MB, less than 100.00% of JavaScript online submissions for Word Search.

小结：应该把工具函数写在函数里，这样方便调用，也减少了参数传递。

