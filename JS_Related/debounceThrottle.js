function myDebounce(fn, interval = 500) {
  let timeout = null;
  return function () {
    clearTimeout(timeout);
    setTimeout(() => {
      fn.apply(this, arguments); // 很重要
    }, interval);
  }
}

function dosomething() {}

container.onClick() = myDebounce(dosomething, 300);

function throttle(fn, interval = 500) {
  let canRun = true; // 第一次就要开始计时
  return function () {
    if (!canRun) return;
    canRun = false;
    setTimeout(() => {
      fn.apply(this, arguments); // 很重要
      canRun = true;
    }, interval)
  }
}
container.onClick() = throttle(dosomething, 300);