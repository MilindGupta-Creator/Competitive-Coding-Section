class Solution {
public:
    
   struct cmp {
        bool operator()(const ListNode* l, const ListNode* r) 
        {
            return l->val > r->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(auto it : lists)
        {
            if(it)
            q.push(it);
        }
        ListNode* dummy=new ListNode;
        ListNode* temp=dummy;
        while(!q.empty())
        {
            ListNode* t=q.top();
            q.pop();
            ListNode* curr= new ListNode(t->val);
            temp->next=curr;
            temp=temp->next;
            if(t->next)
            q.push(t->next);
        }
        return dummy->next;
    }
};
