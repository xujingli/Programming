let result = {};
const flatten = (obj, key) => {
  if (obj instanceof Array) {
    obj.forEach((param, index) => {
      if (param instanceof Object || param instanceof Array) {
        flatten(param, `${key}[${index}]`);
      } else {
        result[`${key}[${index}]`] = flatten(param, `${key}[${index}]`);
      }
    });
  } else if (obj instanceof Object) {
    for (var tempKey in obj) {
      const tempValue = obj[tempKey];
      if (tempValue instanceof Array) {
        flatten(tempValue, tempKey);
      } else if (tempValue instanceof Object) {
        flatten(tempValue, tempKey);
      } else if (tempValue === null || tempValue === undefined) {} else {
        if (key) {
          result[`${key}.${tempKey}`] = flatten(tempValue, tempKey);
        } else {
          result[tempKey] = flatten(tempValue, tempKey);
        }
      }
    }
  } else {
    return obj;
  }
};

var input = {
  a: 1,
  b: [
    1,
    2, {
      c: true
    },
    [3]
  ],
  d: {
    e: 2,
    f: 3
  },
  g: null
};
flatten(input);
console.log(result);