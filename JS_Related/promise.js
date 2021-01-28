// Promise


const PENDING = 'pending';
const RESOLVED = 'resolved';
const REJECTED = 'rejected';

// Promise构造函数接受一个函数作为参数，该函数的两个参数分别是resolve和reject
// resolve函数的作用是，将Promise对象的状态从“未完成”变为“成功”（即从 pending 变为 resolved），
// 在异步操作成功时调用，并将异步操作的结果，作为参数传递出去；
// reject函数的作用是，将Promise对象的状态从“未完成”变为“失败”（即从 pending 变为 rejected），
// 在异步操作失败时调用，并将异步操作报出的错误，作为参数传递出去。
function MyPromise(fn) {
  const that = this;
  that.value = null;
  that.state = PENDING;
  that.resolvedCallback = [];
  that.rejectedCallback = [];

  function resolve(value) {
    if (that.state == PENDING) {
      that.value = value;
      that.state = RESOLVED;
      that.resolvedCallback.map(cb => cb(value));
    }
  }

  function reject() {
    if (that.state == PENDING) {
      that.value = value;
      that.state = REJECTED;
      that.rejectedCallback.map(cb => cb(value));
    }
  }

  try {
    fn(resolve, reject);
  } catch (e) {
    reject(e);
  }
}

// then方法可以接受两个回调函数作为参数。
// 第一个回调函数是Promise对象的状态变为resolved时调用，
// 第二个回调函数是Promise对象的状态变为rejected时调用。
// 这两个函数都是可选的，不一定要提供。它们都接受Promise对象传出的值作为参数。
MyPromise.prototype.then = function (onFulfilled, onRejected) {
  const that = this;
  onFulfilled = typeof onFulfilled === "Function" ? onFulfilled : v => v;
  onRejected = typeof onRejected === "Function" ? onRejected :
    v => {
      throw v
    };

  if (that.state == PENDING) {
    that.resolvedCallback.push(onFulfilled);
    that.rejectedCallback.push(onRejected);
  } else if (that.state == RESOLVED) {
    onFulfilled(that.value);
  } else if (that.state == REJECTED) {
    onRejected(that.value);
  }
}

new MyPromise((resolve, reject) => {
  setTimeout(() => {
    resolve(1)
  }, 0)
}).then(value => {
  console.log(value)
})