void reversePrint(Node* root)
{
    vector<int >res[3000];
  int level=0;
  Node *cur=root;
  queue<Node*>q;
  q.push(cur);
  q.push(NULL);
  while(q.size()!=1){
      cur=q.front();
      q.pop();
      if(cur!=NULL){
          res[level].push_back(cur->data);
          //cout<<cur->data<<" ";
      }
      else if(cur==NULL){
          level+=1;
          //cout<<'$'<<" ";
          q.push(NULL);
          continue;
      }
      if(cur->left)q.push(cur->left);
      if(cur->right)q.push(cur->right);
  }
    
  //cout<<'$';
  for(int j=level;j>=0;j--){
      for(int ele : res[j]){
          cout<<ele<<" ";
      }
  }
}

