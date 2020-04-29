void printSpiral(Node* root)
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
      }
      else if(cur==NULL){
          level+=1;
          q.push(NULL);
          continue;
      }
      if(cur->left)q.push(cur->left);
      if(cur->right)q.push(cur->right);
  }
  int val=1;
  for(int j=0;j<=level;j++){
      if(val==-1){
          val=val*-1;
          for(int i=0;i<res[j].size();i++)cout<<res[j][i]<<" ";
      }
      else {
          val=val*-1;
          for(int i=res[j].size()-1;i>=0;i--)cout<<res[j][i]<<" ";
      }
  }
}

