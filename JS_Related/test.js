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

  function helper(obj, initialKey = "") {
    if (obj instanceof Object) {
      for (let key in obj) {
        let tempValue = obj[key];
        if (tempValue instanceof Array) {
          helper(tempValue, key); // 如果是array下一层自己加上括号
        } else if (tempValue instanceof Object) {
          // 核心的疑惑就在这里，当前是对象，那么 '.' 在哪里加呢？？？？
          helper(tempValue, key);
        } else if (tempValue === null || tempValue === undefined) {
          continue;
        } else {
          if (initialKey) {
            res[initialKey + "." + key] = tempValue;
          } else {
            res[key] = tempValue;
          }
        }
      }
    } else if (obj instanceof Array) {
      obj.forEach((ele, idx) => {
        if (ele instanceof Object) { // 数组中的元素是对象，则 点号下一层自己加
          helper(ele, initialKey + '[' + idx + ']'); // 本层加上括号，其余下一次加
        } else if (ele instanceof Array) { // 如果数组中的元素还是数组，则括号下一层自己加上
          helper(ele, initialKey + '[' + idx + ']'); // 本层加上括号，其余的下一层加
        } else if (ele === null || ele === undefined) {
          // continue;
        } else { // 如果数组元素就是普通的值，则加上括号
          let tempKey = initialKey + "[" + idx + "]";
          res[tempKey] = ele; // TODO
        }
      })
    } else {
      return obj;
    }
  }
}

const input = {
  a: 1,
  b: [1, 2, {
      c: true
    },
    [3]
  ],
  d: {
    e: 2,
    f: 3
  },
  g: null,
}

console.log(flatten(input));