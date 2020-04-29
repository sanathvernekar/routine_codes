map<int,int>m;
int i=0;
void fill(Node *root,int i)
{
    if(root==NULL)return;
    m[i]=root->data;
    fill(root->left,i-1);
    fill(root->right,i+1);
}
void bottomView(Node *root)
{
    
    if(root==NULL)return;
    m[i]=root->data;
    fill(root->left,i-1);
    fill(root->right,i+1);
    for(auto i : m)cout<<i.second<<" ";
    m.clear();
   
}

