# JS数据结构与算法

[toc]

## 数组

###  创建和初始化数组

1. 使用new关键字创建

```
let arr = new Array()
let arr = new Array(7)
let arr = new Array(1,2,3,4,5,6)
```

2. 中括号创建

```
let arr = []
let arr = [1,3,34,44]
```

### 添加元素

1. 在末尾插入元素

```
arr[arr.length] = 11;
arr.push(11)  //push方法
arr.push(11,12,22) //可以添加任意个元素
```

2. 在数组开头插入元素

```
// 所有元素后移一位，腾出一个位置
InsertFirstPosition = (arr,value) => {
	for(let i = arr.length;i>0;i--){
		arr[i] = arr[i-1]
	}
	arr[0] = value
}
InsertFirstPosition(arr,-1)
```

```
//使用unshift方法,可以直接把数值插入数组的开头，代码的逻辑和上面是一样的
arr.unshift(-2)
arr.unshift(-5,-4,-3) //依次添加-3 -4 -5
```

### 删除元素

1. 末尾删除元素

```
arr.pop()
```

2. 开头删除元素

```
//使用shift方法
arr.shift();
```

### 在任意位置添加或删除

1. splice方法

**delete运算符删除数组中的元素，delete arr[0]过后，arr[0] = undefined delete不会改变数组长度**  

**因此，我们应该使用splice、pop、shift来删除数组元素**

``` 
arr.splice(5,3) //删除从数组索引5开始的 3个元素
arr.splice(5,0,2,3,4) //把数2,3,4插入到数组里，放到之前删除元素的位置上。

arr.splice(5,3,2,3,4) //以上两行等同于
```

### 二维和多维数组

**JS只支持一维数组，并不支持矩阵。但是可以使用 数组套数组 的方法** 



### JS数组方法 ES6数组的新功能 类型数组 TypeScript中的数组

**见书本**

---



## 栈

### 数组版本

| 5      | 8    | 11   | 15     |
| ------ | ---- | ---- | ------ |
| 0 栈底 | 1    | 2    | 3 栈顶 |

```
class Stack{
	constructor(){
		this.items = [];
	}
	push(element){
		this.items.push(element)
	}
	pop(){
		return this.items.pop()
	}
	peek(){	//查看栈顶元素
		return this.items[this.items.length-1]
	}
	isEmpty(){
		return this.items.length === 0;
	}
	size(){
		return this.items.length;
	}
	clear(){
		this.items = []
	}
}
```

### 创建一个基于JS对象的Stack类

使用count 属性来记录栈的大小

```
class Stack{
	constructor(){
		this.items = {};
		this.count = 0;	
	}
	push(element){
		this.items[this.count++] = element
	}
	pop(){
		if(this.isEmpty()){
			return undefined;
		}
		this.count--;
		const result = this.items[this.count];
		delete this.items[this.count]
		return result
	}
	peek(){	//查看栈顶元素
		if(this.isEmpty()){
			return undefined
		}
		return this.items[this.count - 1]
	}
	isEmpty(){
		return this.count === 0;
	}
	size(){
		return this.count;
	}
	clear(){
		this.items = {}
		this.count = 0
	}
	
	toString(){
		if(this.isEmpty()){
			return ""
		}
		let objString = `${this.items[0]}`
		for(let i=1;i<this.count;i++)
			objString =  `${objString}, ${this.items[i]}`
		return objString;
	}
}
```

### 保护数据结构内部元素

以上方法中内部的私有成员[count, items]是可以被访问和修改的！

1. 下划线命名约定： 私有成员名前加下划线
2. ES6 的WeakMap 实现类: WeakMap可以存储键值对

```
const items = new WeakMap();

class Stack{
	constructor(){
		items.set(this, [])
	}
	push(element){
		const s = items.get(this)
		s.push(element)
	}
	pop(){
		const s = items.get(this)
		const r = s.pop();
		return r;
	}
}
```

**小试牛刀：进制转换**

```
function baseConverter(decNumber,base){
	const remStack = new Stack()
	const digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	let number = decNumber;
	let rem;
	let baseString = ''
	
	if(!(base>=2 && base<=36))
		return ''
	
	while(number > 0){
		rem = Math.floor(number % base);
		remStack.push(rem);
		number = Math.floor(number/base);
	}
	
	while(!remStack.isEmpty()){
		baseString += digits[remStack.pop()];
	}
	
	return baseString;
}
```

---

## 队列和双端队列

### 队列 

尾进头出

| 2      | 5    | 6    | 8    | 3      |
| ------ | ---- | ---- | ---- | ------ |
| 头部 0 | 1    | 2    | 3    | 尾部 4 |



```
class Queue{
	constructor(){
		this.count = 0;
		this.lowestCount = 0; //第一个元素
		this.items = {}
	}
	enqueue(element){
		this.items[this.count] = element;
		this.count++
	}
	isEmpty(){
		return this.count - this.lowestCount === 0
	}
	dequeue(){
		if(this.isEmpty()){
			return undefined
		}
		const result = this.items[this.lowestCount]
		delete this.items[this.lowestCount]
		this.lowestCount++
		return result
	}
	peek(){	//查看队头元素
		if(this.isEmpty())
			return undefined;
		return this.items[this.lowestCount];
	}
	size(){
		return this.count - this.lowestCount
	}
	clear(){
		this.item = {}
		this.count = 0;
		this.lowestCount = 0
	}
	toString(){
		if(this.isEmpty()){
			return ""
		}
		let objString = `${this.items[this.lowestCount]}`
		for(let i=this.lowestCount+1;i<this.count;i++){
			objString = `${objString}, ${this.items[i]}`
		}
		return objString;
	}
}
```

### 双端队列

```
class Deque{
	constructor(){
		this.count = 0;
		this.lowestCount = 0; //第一个元素
		this.items = {}
	}
	addBack(element){
		this.items[this.count] = element;
		this.count++
	}
	addFront(element){
		if(this.isEmpty()){
			this.addBack(element);
		} else if(this.lowestCount > 0){
			this.lowestCount--
			this.items[this.lowestCount] = element;
		} else { // lowestCopunt === 0
			for(let i=this.count;i>0;i--){
				this.items[i] = this.items[i-1]
			}
			this.count++
			this.lowestCount = 0;
			this.items[0] = element;
		}
	}
	isEmpty(){
		return this.count - this.lowestCount === 0
	}
	size(){
		return this.count - this.lowestCount
	}
	clear(){
		this.item = {}
		this.count = 0;
		this.lowestCount = 0
	}
	toString(){
		if(this.isEmpty()){
			return ""
		}
		let objString = `${this.items[this.lowestCount]}`
		for(let i=this.lowestCount+1;i<this.count;i++){
			objString = `${objString}, ${this.items[i]}`
		}
		return objString;
	}
}
```

---



## 链表

```
class Node{
	constructor(element){
		this.element = element
		this.next = undefined
	}
}
```

```\
class LinkedList{	//不含头结点的链表
	constructor(){
		this.count = 0;
		this.head = undefined
	}
	push(element){
		const node = new Node(element);
		let current;
		if(this.head == undefined){ //空
			this.head = node;
		} else {	//不为空
			current = this.head;
			while(current.next != null)
				current = current.next
			current.next = node
		}
		this.count++
	}
	toString(){
		if(this.head == null)
			return '';
		let objString = `${this.head.element}$`
		let current = this.head.next;
		while(current != null){
			objString = `${objString}, ${current.element}`
			current = current.next
		}
		return objString
	}
	removeAt(index){
		if(index<0 || index>=this.count)
			return undefined
		let current = this.head;
		if(index === 0)
			this.head = current.next;
		else{
			let previous;
			for(let i=0;i<index;i++){
				previous = current;
				current = current.next
			}
			previous.next = current.next
		}
		this.count--
		return current.element
	}
}
```


