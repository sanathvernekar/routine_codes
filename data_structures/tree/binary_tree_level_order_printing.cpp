void levelOrder(Node* root)
{
  int level=0;
  Node *cur=root;
  queue<Node*>q;
  q.push(cur);
  q.push(NULL);
  while(q.size()!=1){
      cur=q.front();
      q.pop();
      if(cur!=NULL){
          cout<<cur->data<<" ";
      }
      else if(cur==NULL){
          cout<<'$'<<" ";
          q.push(NULL);
          continue;
      }
      if(cur->left)q.push(cur->left);
      if(cur->right)q.push(cur->right);
  }
  cout<<'$';
}

//to print level order sum in binary tree
void levelOrder(Node* root)
{
    vector<int >res;
    int sum=0;
  int level=0;
  Node *cur=root;
  queue<Node*>q;
  q.push(cur);
  q.push(NULL);
  while(q.size()!=1){
      cur=q.front();
      q.pop();
      if(cur!=NULL){
          sum+=cur->data;
          cout<<cur->data<<" ";
      }
      else if(cur==NULL){
          res.push_back(sum);
          sum=0;
          cout<<'$'<<" ";
          q.push(NULL);
          continue;
      }
      if(cur->left)q.push(cur->left);
      if(cur->right)q.push(cur->right);
  }
  res.push_back(sum);
  cout<<'$';
  cout<<endl;
  for(int ele : res)cout<<ele<<" ";
  cout<<endl;
}

