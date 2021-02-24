function myDebounce(fn, interval = 500) {
  let timeout = null;
  return function () {
    clearTimeout(timeout);
    setTimeout(() => {
      fn.apply(this, arguments);
    }, interval);
  }
}

function dosomething() {}

container.onClick() = myDebounce(dosomething, 300);

function throttle(fn, interval = 500) {
  let canRun = true; // 第一次就要开始计时
  return function () {
    if (!canRun) return;
    run = false;
    setTimeout(() => {
      fn.apply(this, arguments);
      canRun = true;
    }, interval)
  }
}
container.onClick() = throttle(dosomething, 300);