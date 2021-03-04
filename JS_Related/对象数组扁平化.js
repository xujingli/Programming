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