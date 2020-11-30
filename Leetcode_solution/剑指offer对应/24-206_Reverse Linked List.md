# [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)

> Reverse a singly linked list.
>
> **Example:**
>
> ```
> Input: 1->2->3->4->5->NULL
> Output: 5->4->3->2->1->NULL
> ```
>
> **Follow up:**
>
> A linked list can be reversed either iteratively or recursively. Could you implement both?
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
>  * @return {ListNode}
>  */
> var reverseList = function(head) {
>     
> };
> ```



## Solution 递归

[参考](https://www.zhihu.com/question/31412436/answer/683820765)

```javascript
var reverseList = function(head) {
    if(head === null || head.next === null) //
        return head;
    let newList = reverseList(head.next);

    // 改变第1、2个节点的指向
    let t1 = head.next;
    t1.next = head;
    head.next = null;
    return newList;
};
```





## Solution迭代

```javascript
var reverseList = function(head) {
    if(head === null || head.next === null)
        return head;
    let nextp = head.next,newp = head;
    newp.next = null;
    while(nextp && nextp.next){
        let tmp = nextp;
        nextp = nextp.next;
        tmp.next = newp;
        newp = tmp;
    }
    nextp.next = newp
    return nextp
};
Runtime: 52 ms, faster than 94.36% of JavaScript online submissions for Reverse Linked List.
Memory Usage: 35 MB, less than 56.52% of JavaScript online submissions for Reverse Linked List.
```





## 参考：

