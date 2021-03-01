function Person(name) {
  this.name = name;
  return {
    name: "abc"
  }
}

// function Person(name) {
//   this.name = name;
// }

function create() {
  let obj = new Object(); // 第一步， 新建一个对象

  let constructor = [].shift.call(arguments); // 第一个参数
  obj.__proto__ = constructor.prototype; // 第二步 链接到原型  

  // constructor.apply(obj, arguments); // 第三步， 绑定this
  let res = constructor.apply(obj, arguments);
  if (res) return res;
  else return obj;
}

person = create(Person, "xjl"); // (对象名称, ...arguments)