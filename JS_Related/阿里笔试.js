/*
 * 给定一个二叉树，找出其最小深度。
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 说明: 叶子节点是指没有子节点的节点
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 *     3
 *    / \ 
 *   9  20
 *     /  \
 *    15   7
 * 返回它的最小深度 2
 */
function getTreeDepth(arr) {
  // write code here

  // 将arr转换为一棵树
  // arr应该就是一棵树吧？

  if (arr.length == 0) return 0;
  let queue = [];
  queue.push(0);
  let i = 0;
  while (queue.length !== 0) {
    i++;
    let k = queue.length;
    for (let j = 0; j < k; j++) {
      let cur = queue.shift();
      let curLeft = cur * 2;
      let curRight = cur * 2 + 1;
      if (curLeft < arr.length && arr[curLeft] !== null) queue.push(curLeft);
      if (curRight < arr.length && arr[curRight] !== null) queue.push(curRight);
      if ((curLeft >= arr.length || curRight >= arr.length) || (arr[curLeft] === null && arr[curRight] === null)) return i;
    }
  }

  //   return helper(arr);

  //   function helper(root) {
  //   	if(root === null) return 0;
  //     let queue = [];
  //     queue.push(root);
  //     let i = 0;
  //     while(queue.length !== 0) {
  //       i++;
  //       let k = queue.length;
  //       for(let j=0;j<k;j++) {
  //       	let cur = queue.shift();
  //         if(cur.left) queue.push(cur.left);
  //         if(cur.right) queue.push(cur.right);
  //         if(cur.left === null && cur.right === null) return i;
  //       }
  //     }
  //   }
}

/**
 * 判断括号匹配
 * 说明：给定一个只包含 '() {} []' 6种字符的字符串，
 *   实现一个方法来检测该字符串是否合法，其规则为'()'、'{}'、'[]'必须互相匹配，可嵌套。
 * 示例：
 *   isValid('(');          // false
 *   isValid('()');         // true
 *   isValid('()[]{}');     // true
 *   isValid('{()[]}');     // true
 *   isValid('(]');         // false
 *   isValid('([)]');       // false
 *   isValid('({}[]([]))'); // true
 */
function isValid(s) {
  // write code here
  let len = s.length

  let stack = "";
  for (let i = 0; i < len; i++) {
    let len = stack.length
    if (s[i] === "(" || s[i] === "[" || s[i] === "{")
      stack += s[i] //直接相加
    else if ((s[i] === "]" && stack[len - 1] === "[") || (s[i] === ")" && stack[len - 1] === "(") || (s[i] === "}" && stack[len - 1] === "{"))
      stack = stack.slice(0, len - 1) //去除最后一个元素（出栈）
    else
      return false
  }
  if (stack.length != 0)
    return false
  return true
}

/*
 * 扁平化对象
 * 传入 input 对象（Object 或者 Array）进行扁平化处理并返回结果。
 * 具体效果如下：
 * const input = {
 *    a: 1,
 *    b: [ 1, 2, { c: true }, [ 3 ] ],
 *    d: { e: 2, f: 3 },
 *    g: null, 
 * }
 * 
 * flatten(input);
 * 
 * 返回：
 * {
 *    "a": 1,
 *    "b[0]": 1,
 *    "b[1]": 2,
 *    "b[2].c": true,
 *    "b[3][0]": 3,
 *    "d.e": 2,
 *    "d.f": 3,
 *    // "g": null,  值为null或者undefined，丢弃
 * }
 */

function flatten(input) {
  // write code here

  let res = {};
  helper(input);
  return res;

  function helper(obj, key) {
    if (Array.isArray(obj)) {
      obj.forEach((ele, idx) => {
        if (ele instanceof Object || ele instanceof Array) {
          helper(ele, key + '[' + idx + ']');
        } else {
          res[key + '[' + idx + ']'] = helper(ele, key + '[' + idx + ']');
        }
      });
    } else if (obj instanceof Object) {
      for (let tempKey in obj) {
        let tempValue = obj[tempKey];
        if (tempValue instanceof Array) {
          helper(tempValue, tempKey);
        } else if (tempValue instanceof Object) {
          helper(tempValue, tempKey);
        } else if (tempValue === null || tempValue === undefined)
          continue;
        else {
          if (key) {
            res[key + '.' + tempKey] = flatten(tempValue, tempKey);
          } else {
            res[tempKey] = flatten(tempValue, tempKey);
          }
        }
      }
    } else {
      return obj;
    }
  }


  //   function fn(obj, key, ) {
  // 	for(let k in obj) {
  //     	if(typeof obj[k] == "object") {
  //         	fn(obj[k], key + k + '.');
  //         } else if() { // 处理是

  //         } else
  //           res[key + k] = obj[k];
  //     }
  //   }

  // 以下是数组扁平化！
  // let res = [];
  // for(let ele of input) {
  // 	if(Array.isArray(ele)) {
  //   	res = res.concat(flatten(ele));
  //   } else 
  //     res.push(ele);
  // }
  // return res;
}