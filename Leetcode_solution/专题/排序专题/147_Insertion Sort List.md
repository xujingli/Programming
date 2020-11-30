# [147. Insertion Sort List](https://leetcode.com/problems/insertion-sort-list/)

[toc]

> Sort a linked list using insertion sort.
>
> ![](/image/Insertion-sort-example.gif)
> A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
> With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
>
>  **Algorithm of Insertion Sort:**
>
> 1. Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
> 2. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
> 3. It repeats until no input elements remain.
>
>**Example 1:**
> 
>```
> Input: 4->2->1->3
> Output: 1->2->3->4
> ```
> 
>**Example 2:**
> 
>```
> Input: -1->5->3->4->0
> Output: -1->0->3->4->5
> ```
> 
>```
> /**
>  * Definition for singly-linked list.
>  * function ListNode(val) {
>  *     this.val = val;
>  *     this.next = null;
>  * }
>  */
> /**
>  * @param {ListNode} head
>  * @return {ListNode}
>  */
> var insertionSortList = function(head) {
>     
> };
> ```



## solution

### 思路：

以 5->4 -> 2 -> 1 -> 3 为例来理解，如果不理解，请画图

1、head指向未排序的链表头部

2、sorted指向已排序的链表头部

node用于在sorted元素中游走，找到待插位置

pre是sorted链表中待插入位置的前一个位置

insert是一个node待插入到sorted数组中

举个例子来说：

sorted->1 -> 2 -> 4->5     head-> 3 ->null

node指向4 , pre指向2. 

insert是一个节点: insert->3 ->4

然后只要pre.next = insert即完成了插入

### 代码：



```
var insertionSortList = function(head) {
	if(!head || !head.next) return head;
	let sorted = head;	//排好序的链表
	head = head.next;	//指向下一个节点
	while(head){
		let prev = null;
		let insert = head;	//待插入的节点
		let node = sorted
		while(node && node.val < insert.val){
			prev = node;
			node = node.next;
		}	//出循环后，node.val>insert.val 将元素插入到node之前
	}
	insert.next = node
	if(prev!=null){
		insert.next = node;
	}else{
		
	}
	
};

```















```
const insertionSortList = head => {
  if (!head || !head.next) return head;
  const dummy = { next: head };
  let tail = head;
  let cur = head.next;
  while (cur) {
    if (cur.val >= tail.val) {
      tail = cur;
      cur = cur.next;
      continue;
    }
    const next = cur.next;
    let pos = dummy;
    while (pos.next) {
      if (pos.next.val >= cur.val) break;
      pos = pos.next;
    }
    cur.next = pos.next;
    pos.next = cur;
    tail.next = next;
    cur = next;
  }
  tail.next = null;
  return dummy.next;
};
```

