# [203. Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)

[toc]

> Remove all elements from a linked list of integers that have value ***val\***.
>
> **Example:**
>
> ```
> Input:  1->2->6->3->4->5->6, val = 6
> Output: 1->2->3->4->5
> ```
>
> ```javascript
> /**
>  * Definition for singly-linked list.
>  * function ListNode(val) {
>  *     this.val = val;
>  *     this.next = null;
>  * }
>  */
> /**
>  * @param {ListNode} head
>  * @param {number} val
>  * @return {ListNode}
>  */
> var removeElements = function(head, val) {
>     
> };
> ```

## solution 1: 

不带头结点的链表，如何删除元素？

先从头节点开始考虑。比如：1->1->1->2->1->1;  val=1

则首先删除头部的等于val的元素。然后链表指向2->1->1。则头部元素肯定不是val。然后。。。

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
//6->6->6->7->6
var removeElements = function(head, val) {
    if(!head) return head; //链表为空
    
    // 如果头节点的值就是要删除的值。
    while(head){
        if(head.val === val)
            head = head.next;
        else
            break;
    }
    
    //头节点的值已经确定不等于val。
    // 接下来就相当于处理一个带头结点的链表的思路。
    let curr = head;
    while(curr && curr.next){
        if(curr.next.val === val) curr.next = curr.next.next;
        else curr = curr.next;
    }
    
    return head;  
};
```

## Solution 2:

受到Solution 1 的启发，可以先把第一个节点当作空节点，最后处理第一个节点。这样的逻辑就非常清晰了。

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
//6->6->6->7->6
var removeElements = function(head,val){
    if(!head) return head;
    
    let cur = head; //head放在最后处理
    while(cur.next){
        if(cur.next.val === val)
            cur.next = cur.next.next;
        else
            cur = cur.next;
    }
    if(head.val === val) return head.next;
    return head;
    
}
```



## 书上参考

**问题1： 在O(1)时间内删除链表节点： 给定一个单向链表的头指针和一个节点指针，定义一个函数在O(1)时间内删除该节点。**

在单向链表中删除一个节点，常规做法是从链表的头结点开始，顺序遍历查找要删除的节点，并在链表中删除该节点。

之所以需要从头开始查找，是因为我们需要得到将被删除的节点的前一个节点。在单向链表中，节点中没有指向前一个节点的指针，所以只好从链表的头结点开始顺序查找。

但是也不一定非要得到被删除节点的前一个节点！ 我们可以很容易地删除节点的下一个节点。如果我们**把下一个节点的内容复制到需要删除的节点上覆盖原有的内容，再把下一个节点删除，就相当于把当前需要的节点删除了。** 

>  问题1：如果要删除的节点位于链表的尾部，它没有下一个节点.
>
>  ​	 -> 仍然需要从链表的头节点开始，顺序遍历得到该节点的前序节点，并完成删除操作。
>
>  问题2:如果链表中只有一个节点，而我们要删除链表的头结点（也是尾结点）
>
>  ​	->删除节点后，还需要把链表的头结点设置为null

复杂度：最坏情况：每一个节点都要删除。对于n-1个非尾结点，可以在O(1)时间内把下一个节点的内存复制覆盖要删除的节点，并删除下一个节点；对于尾结点，由于需要顺序查找， 时间复杂度是O(n)。因此总的平均复杂度是： [(n-1) * O(1) + O(n)] / n，结果还是O(1).

代码逻辑：

```
DeleteNode(ListHead,ToBeDeletedNode){
	if(!ListHead || !ToBeDeletedNode)
		return;
	//要删除的节点不是尾结点
	if(ToBeDeletedNode->next != null){
		
	}
	//链表只有一个节点，要删除头节点(也是尾结点)
	else if(ListHead == ToBeDeletedNode){
		
	}
	//链表中有多个节点，要删除尾结点
	else{
		
	}
}
```

缺陷：

给定的第二个参数是一个节点，可是如果第二个参数是数值，此方法不能用！

**问题2：** 删除链表中重复的节点。在一个排序的链表中，如何删除重复的节点？



