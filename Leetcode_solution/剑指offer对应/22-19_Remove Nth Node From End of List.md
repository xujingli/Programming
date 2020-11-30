# [19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

> Given a linked list, remove the *n*-th node from the end of list and return its head.
>
> **Example:**
>
> ```
> Given linked list: 1->2->3->4->5, and n = 2.
> 
> After removing the second node from the end, the linked list becomes 1->2->3->5.
> ```
>
> **Note:**
>
> Given *n* will always be valid.
>
> **Follow up:**
>
> Could you do this in one pass?
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
>  * @param {number} n
>  * @return {ListNode}
>  */
> var removeNthFromEnd = function(head, n) {
>     
> };
> ```

## One pass solution

> 可以定义两个指针，第一个指针向前走n-1步，第二个指针保持为0；第一个指针走到第n步时，第二个指针指向1.当第一个指针指向尾结点时，第二个指针指向的就是倒数第n个元素。

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
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {    
    let nullhead = new ListNode(null); // 为了保证第一个节点，为“第一步”，增加头节点
    nullhead.next = head;
    let p1 = nullhead,p2 = nullhead;
    for(let i=1;i<n;i++) // p1向前走n-1步
        p1=p1.next;
    while(p1.next){	// 从第n步起，一起走
        p1 = p1.next;
        p2 = p2.next;
    }
    // p2 所指的就是待删除节点
    if(p2.next === null) p2 = null;
    else{
        p2.val = p2.next.val;
        p2.next = p2.next.next
    }
    return nullhead.next;
};
```

以上代码存在一个很大的问题是：

比如链表1->2->3->4 想删除4所指向的节点，指针p1 p2都指向4，该怎么删除呢？

上面代码的做法是：设置p2 = null。这样是没有删除整个链表里面的4的，只是设置了指针指向空。

### 修正：

所以应该想办法，**使得p2指向待删除节点的前一个节点**。这样直接可以p2.next = p2.next.next

即：p1走第n步时，p2再跟着走

```javascript
var removeNthFromEnd = function(head, n) {
    let nullhead = new ListNode(null); // 为了保证第一个节点，为“第一步”，增加头节点
    nullhead.next = head;
    let p1 = nullhead,p2 = nullhead;
    for(let i=1;i<=n;i++) // p1向前走n步
        p1=p1.next;
    while(p1.next){	// 从第n步起，一起走
        p1 = p1.next;
        p2 = p2.next;
    }
    // p2 所指的就是待删除节点的前一个节点。
    p2.next = p2.next.next;
    
    return nullhead.next;
};
Runtime: 64 ms, faster than 34.45% of JavaScript online submissions for Remove Nth Node From End of List.
Memory Usage: 34 MB, less than 81.82% of JavaScript online submissions for Remove Nth Node From End of List.
```

## 不含头指针的链表，增加头指针

```javascript
var removeNthFromEnd = function(head, n) {
    var nullHead = new ListNode(null);
    nullHead.next = head;
    var p1 = nullHead;
    var p2 = nullHead;
    
    return nullHead.next;
};
```

## 总结:

一定要注意：

比如链表1->2->3->4 想删除4所指向的节点，指针p1 p2都指向4，该怎么删除呢？

上面代码的做法是：设置p2 = null。这样是没有删除整个链表里面的4的，只是设置了指针指向空。