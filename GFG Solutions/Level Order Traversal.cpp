/*
Problem- Level Order Traversal(BFS)
Platform- GFG
Author - Adarsh
*/
vector<int> levelOrder(Node* node)
{
    queue<Node *> q;
    vector<int> v;
    q.push(node);
    while(!q.empty())
    {
        Node *cur=q.front();
        q.pop();
        v.push_back(cur->data);
        if(cur->left!=NULL)
        {
            q.push(cur->left);
        }
        if(cur->right!=NULL)
        {
            q.push(cur->right);
        }
        
    }
    return v;
    
 
}
