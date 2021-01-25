// Promise


const PENDING = 'pending';
const RESOLVED = 'resolved';
const REJECTED = 'rejected';

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