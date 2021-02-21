Function.prototype.myCall = function (context) {
  if (typeof this !== 'function') {
    throw new TypeError('Error');
  }
  context = context || window;

  const args = [...arguments].slice(1);
  const func = this;
  const result = func(...args); // 用这些参数来执行这个函数
  delete func;
  return result;
}

Function.prototype.myApply = function (context) {
  if (typeof this !== 'function') {
    throw new TypeError('Error');
  }
  context = context || window; // 如果参数为空则默认this为window

  const func = this;
  // 处理参数和 call 有区别，arguments[1]准确来说是个数组
  let result;
  if (arguments[1]) {
    result = func(...arguments[1]);
  } else {
    result = func();
  }
  delete func;
  return result;
}

// MDN的解释是：bind()方法会创建一个新函数，称为绑定函数，
// 当调用这个绑定函数时，绑定函数会以创建它时传入 bind()方法
// 的第一个参数作为 this，传入 bind() 方法的第二个以及以后的
// 参数加上绑定函数运行时本身的参数按照顺序作为原函数的参数来调用原函数
Function.prototype.myBind = function (context) {
  if (typeof this !== 'function') {
    throw new TypeError('Error');
  }

  const _this = this;
  const args = [...arguments].slice(1);
  return function F() {
    // 因为返回了一个函数，我们可以 new F()，所以需要判断
    if (this instanceof F) {
      // 通过new方式调用函数，忽略传入的this, arguments是“调用”的时候传入的参数
      return new _this(...args, ...arguments);
    }
    // 直接调用，有两组参数，用concat连接起来
    return _this.apply(context, args.concat(arguments));
  }
}