map<int,int>m;
//using recursion
void solve(Node *root, int i){
    if(root==NULL)return;
    if(m.find(i)==m.end())m[i]=root->data;
    else m[i]+=root->data;
    solve(root->left,i-1);
    solve(root->right,i+1);
}
void printVertical(Node *root)
{
    solve(root,0);
    for(auto i : m)cout<<i.second<<" ";
    m.clear();
    
}
