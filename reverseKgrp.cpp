//ITERATIVE APPROACH TO REVERSE A GROUP OF K NUMBERS IN A LINKED LIST

//psuedocode
// Suppose that we are given a list:
// 1->2->3->4->5->NULL, k = 2
// Initialization:     dummy -> 1, prev = dummy
// Current List:       dummy->1->2->3->4->5->NULL
// First Iteration:    let it point to 1
//                     increase count for 1, becomes 1
//                     let it point to 2
//                     increase count for 1, becomes 2
//                     there are at least 2 nodes left
//                     set nextPrev to 1
//                     reverse from 1 to 2
//                     let 1 point to NULL
//                     let 2 point to 1
//                     prev2 is 2
//                     cur is 3
//                     let prev (dummy) point to prev2 (2)
//                     let nextPrev (1) point to cur (3)
//                     move prev (dummy) to nextPrev (1)
// Current List:       dummy->2->1->3->4->5->NULL
// Second Iteration:   let it point to 3
//                     increase count for 1, becomes 1
//                     let it point to 4
//                     increase count for 1, becomes 2
//                     there are at least 2 nodes left
//                     set nextPrev to 3
//                     reverse from 3 to 4
//                     let 3 point to NULL
//                     let 4 point to 3
//                     prev2 is 4
//                     cur is 5
//                     let prev (1) point to prev2 (4)
//                     let nextPrev (3) point to cur (5)
//                     move prev (1) to nextPrev (3)
// Current List:       dummy->2->1->4->3->5->NULL
// Second Iteration:   let it point to 5
//                     increment count for 1, becomes 1
//                     let it point to NULL
//                     there is only 1 node left
//                     halt
                    
// return dummy.next = 2

//FUNC TO REVERSE AND PRINT K GROUPS IN A LINKEDLIST
ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || !head->next || k <= 1) {
        return head;
    }
    
    ListNode dummy(0), *prev = &dummy;
    prev->next = head;
    
    while (true) {
        ListNode* it = prev->next;
        int count = 0;
        while (it) {
            ++count;
            if (count == k) {
                break;
            }
            it = it->next;
        }
        if (count < k) {
            break;
        }
        
        ListNode* nextPrev = prev->next;
        
        ListNode* prev2 = NULL, *cur = prev->next, *next = NULL;
        for (int i = 0; i < k; ++i) {
            next = cur->next;
            cur->next = prev2;
            prev2 = cur;
            cur = next;
        }
        
        prev->next = prev2;
        nextPrev->next = cur;
        
        prev = nextPrev;
    }
    
    return dummy.next;
}

/*Time Complexity: O(n) — Basically, we need to iterate the list twice overall. First, in each iteration, we have to first look ahead to check if there are k nodes left. If there are, we need reverse them, which is another linear scan. So the total time complexity is still linear.

Space Complexity: O(1) — The only main data structure we have been using in this implementation are still pointers, so the space cost is constant.
*/
//SOURCE : https://medium.com