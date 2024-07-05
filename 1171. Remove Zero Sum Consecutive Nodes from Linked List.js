class ListNode {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

function removeZeroSumSublists(head) {
    const dummy = new ListNode(0);
    dummy.next = head;
    let prefix_sum = 0;
    const prefix_sums = { 0: dummy };
    let current = head;

    while (current) {
        prefix_sum += current.val;
        if (prefix_sum in prefix_sums) {
            let to_delete = prefix_sums[prefix_sum].next;
            let temp_sum = prefix_sum + to_delete.val;
            while (to_delete !== current) {
                delete prefix_sums[temp_sum];
                to_delete = to_delete.next;
                temp_sum += to_delete.val;
            }
            prefix_sums[prefix_sum].next = current.next;
        } else {
            prefix_sums[prefix_sum] = current;
        }
        current = current.next;
    }

    return dummy.next;
}

// Input code
function createLinkedList(arr) {
    if (arr.length === 0) return null;
    let head = new ListNode(arr[0]);
    let current = head;
    for (let i = 1; i < arr.length; i++) {
        current.next = new ListNode(arr[i]);
        current = current.next;
    }
    return head;
}

function printLinkedList(head) {
    let current = head;
    let result = [];
    while (current) {
        result.push(current.val);
        current = current.next;
    }
    console.log(result.join(' -> '));
}

let arr = prompt("Enter elements of linked list separated by space:").split(" ").map(Number);
let head = createLinkedList(arr);
let result = removeZeroSumSublists(head);
printLinkedList(result);
