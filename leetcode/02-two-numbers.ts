// Definition for singly-linked list.
function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function (l1, l2) {
  let root = new ListNode(0, undefined);
  let current = root;
  let carry = 0;

  while (l1 || l2 || carry) {
    const sum = (l1?.val ?? 0) + (l2?.val ?? 0) + carry;
    carry = Math.floor(sum / 10);

    current.next = new ListNode(sum % 10, undefined);
    current = current.next;

    l1 = l1?.next ? l1.next : null;
    l2 = l2?.next ? l2.next : null;
  }

  return root.next;
};
