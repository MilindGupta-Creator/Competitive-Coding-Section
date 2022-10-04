//RECURSIVE APPROACH TO REVERSE A GROUP OF K NUMBERS IN A LINKED LIST
//Recursive Rules: 1) Recursively reverse the list beginning from k+1-th node. 2) Reverse the k nodes starting from current head, and connect the new reversed sub-list to the post result.

//PSEUDOCODE

// Suppose that we have an input list:
// 1->2->3->4->5->NULL, k = 2
// Current List:           1->2->3->4->5->NULL
// In Main Function:       call reverseKGroup(1)
// Current List:           1->2->3->4->5->NULL
// In reverseKGroup(1):    let it point to 1
//                         increase count for 1, becomes 1
//                         let it point to 2
//                         increase count for 1, becomes 2
//                         there are at least 2 nodes
//                         call reverseKGroup(3)
// Current List:           1->2->3->4->5->NULL
// In reverseKGroup(3):    let it point to 3
//                         increase count for 1, becomes 1
//                         let it point to 4
//                         increase count for 1, becomes 2
//                         there are at least 2 nodes
//                         call reverseKGroup(5)
// Current List:           1->2->3->4->5->NULL
// In reverseKGroup(5):    let it point to 5
//                         increase count for 1, becomes 1
//                         there is only 1 node left
//                         hit base case
//                         return 5
// Current List:           1->2->3->4->5->NULL
// In reverseKGroup(3):    get 5 from reverseKGroup(5)
                        
//                         reverse from 3 to 4
//                         let 3 point to 5
//                         return 4
// Current List:           1->2->4->3->5->NULL
// In reverseKGroup(1):    get 4 from reverseKGroup(3)
//                         reverse from 1 to 2
                        
//                         let 1 point to 3
//                         return 2
// Current List:           2->1->4->3->5->NULL
// In Main Function:       get 2


//FUNCTION TO REVERSE AND OUTPUT THE LIST WITH K GROUP REVERSED
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* it = head;
    int count = 0;
    while (it) {
        ++count;
        if (count == k) {
            break;
        }
        it = it->next;
    }
    if (count < k)
        return head;
    
    ListNode* post = reverseKGroup(it->next, k);
    
    ListNode* prev = NULL, *cur = head, *next = NULL;
    for (int i = 0; i < k; ++i) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    
    head->next = post;
    
    return prev;
}

/*Time Complexity: O(n) —  in each function call, we need to first check if there are k nodes left starting from input head, and if there is, we have to reverse them. So two linear scans are still necessary.

Space Complexity: O(n / k) — With recursion, we need to take the cost of call stacks into consideration. For every k nodes, we are supposed to recursively call the function for once. So the total number of recursive calls is n / k. Within each function, we are still using a couple of pointers only in this algorithm, so they are constant cost. Thus, the total space complexity is O(n / k).
*/