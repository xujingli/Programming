// promise.all 的特点：
// 入参是个由Promise实例组成的数组
// 返回值是个promise，因为可以使用.then
// 如果全部成功，状态变为resolved, 并且返回值组成一个数组传给回调
// 但凡有一个失败，状态变为rejected, 并将error返回给回调
function diPromiseAll(promises) {
  return new Promise((resolve, reject) => {
    // 参数判断
    if (!Array.isArray(promises)) {
      throw new TypeError("promises must be an array")
    }
    let result = [] // 存放结果
    let count = 0 // 记录有几个resolved
    promises.forEach((promise, index) => {
      // 如果promise不是Promise对象，则要调用Promise.resolve转成Promise对象
      if (typeof promise !== 'function') promise = Promise.resolve(promise);

      promise.then((res) => {
        result[index] = res
        count++
        count === promises.length && resolve(result) // 判断是否已经完成
      }, (err) => {
        reject(err)
      })
    })
  })
}