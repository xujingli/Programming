# [21. Merge Two Sorted Lists]( https://leetcode.com/problems/merge-two-sorted-lists/ )

> Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
>
> **Example:**
>
> ```
> Input: 1->2->4, 1->3->4
> Output: 1->1->2->3->4->4
> ```
>
> ```
> /**
>  * Definition for singly-linked list.
>  * function ListNode(val) {
>  *     this.val = val;
>  *     this.next = null;
>  * }
>  */
> /**
>  * @param {ListNode} l1
>  * @param {ListNode} l2
>  * @return {ListNode}
>  */
> var mergeTwoLists = function(l1, l2) {
>  
> };
> ```

# solution 合并链表

**合并两个升序的链表** 严书P31

```javascript
var mergeTwoLists = function(l1, l2) {
	//将最后结果存放在l1上
	let pa = l1,pb=l2
	let pc=l1;
    let L=pc;
	
	while(pa!=null && pb!=null){
		if(pa.val <= pb.val){
			pc = pa;
			pc = pc.next;
			pa = pa.next;
		} else {
			pc = pb;
			pc = pc.next;
			pb = pb.next
		}
	}
	pc = (pa == null ? pb : pa)
	return L
};
```







```
var mergeTwoLists = function(l1, l2) {
	//将最后结果存放在l1上
	let dummyHead = new ListNode()
	let cur = dummyHead;
	
	while(l1 && l2){
		if(l1.val <= l2.val){
			cur.next = l1;
			l1 = l1.next
		} else {
			cur.next = l2;
			l2 = l2.next;
		}
		cur = cur.next;
	}
	cur.next = (l1 == null ? l2 : l1)
	return dummyHead.next
};
```

```
var mergeTwoLists = function(l1, l2) {
  if(!l1 || !l2) return (l1? l1:l2);
  if(l1.val < l2.val) {
    l1.next = mergeTwoLists(l1.next, l2);
    return l1;
  } else {
    l2.next = mergeTwoLists(l1, l2.next);
    return l2;
  }
};
```



