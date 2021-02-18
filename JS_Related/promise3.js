// 三个状态：PENDING、FULFILLED、REJECTED
const PENDING = 'PENDING';
const FULFILLED = 'FULFILLED';
const REJECTED = 'REJECTED';

// 6. 
const resolvePromise = (promise2, x, resolve, reject) => {
  if (promise2 === x) {
    return reject(new TypeError("循环引用"));
  }
  let called;
  // x是对象或者函数
  if ((typeof x === "object" && x != null) || typeof x === 'function') {
    try {
      // // 为了判断 resolve 过的就不用再 reject 了（比如 reject 和 resolve 同时调用的时候）
      let then = x.then;
      if (typeof then === 'function') {
        then.call(x, y => {

        })
      }

    } catch (error) {

    }
  } else { // 如果x是个普通值 就直接返回resolve作为结果
    resolve(x);
  }
}

class Promise {
  constructor(executor) {
    this.status = PENDING;
    this.value = undefined;
    this.reason = undefined;

    this.onResolvedCallbacks = [];
    this.onRejectedCallbacks = [];

    let resolve = (value) => {
      if (this.status == PENDING) {
        this.status = FULFILLED;
        this.value = value;

        this.onResolvedCallbacks.forEach(fn => fn());
      }
    }

    let reject = (reason) => {
      if (this.status == PENDING) {
        this.status = REJECTED;
        this.reason = reason;
        this.onRejectedCallbacks.forEach(fn => fn());
      }
    }

    try {
      executor(resolve, reject);
    } catch (error) {
      reject(error);
    }
  }

  then(onFulfilled, onRejected) {

    // 1. 解决 onFulfilled 或者 onRejected函数没有传值的问题
    onFulfilled = typeof onFulfilled === 'function' ? onFulfilled : v => v;
    onRejected = typeof onRejected === 'function' ? onRejected : err => {
      throw err
    };

    // 2. 每次调用then都返回一个新的promise  
    let promise2 = new Promise((resolve, reject) => {
      if (this.status === FULFILLED) {
        // 3. Promise/A+ 2.2.4 --- setTimeout
        setTimeout(() => {
          // 4. try catch  错误信息传给下一个then
          try {
            let x = onFulfilled(this.value);
            // 5. x可能是一个promise
            // 如果 then 的返回值 x 是一个 promise，且 x 同时调用 resolve 函数和 reject 函数，
            // 则第一次调用优先，其他所有调用被忽略；
            resolvePromise(promise2, x, resolve, reject);
          } catch (error) {
            reject(error);
          }
        }, 0);
      } else if (this.status === REJECTED) {
        setTimeout(() => {
          try {
            let x = onRejected(this.reason);
            resolvePromise(promise2, x, resolve, reject);
          } catch (error) {
            reject(error);
          }
        }, 0);
      } else if (this.status === PENDING) {
        this.onResolvedCallbacks.push(() => {
          // 与上面的一样一样
          setTimeout(() => {
            try {
              let x = onFulfilled(this.value);
              resolvePromise(promise2, x, resolve, reject);
            } catch (error) {
              reject(error);
            }
          }, 0);
        });

        this.onRejectedCallbacks.push(() => {
          setTimeout(() => {
            try {
              let x = onRejected(this.reason);
              resolvePromise(promise2, x, resolve, reject);
            } catch (error) {
              reject(error);
            }
          }, 0);
        })
      }
    });

    return promise2;
  }
}