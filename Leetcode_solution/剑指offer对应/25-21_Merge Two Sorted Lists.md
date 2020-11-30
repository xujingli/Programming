# [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

> Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
>
> **Example:**
>
> ```
> Input: 1->2->4, 1->3->4
> Output: 1->1->2->3->4->4
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
>  * @param {ListNode} l1
>  * @param {ListNode} l2
>  * @return {ListNode}
>  */
> var mergeTwoLists = function(l1, l2) {
>     
> };
> ```

# Solution

```javascript

```



### 如下代码是已经写过的，可是没有及时复习，都忘光了，连思想都忘了。

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

