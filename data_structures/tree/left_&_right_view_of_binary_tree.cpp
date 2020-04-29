void leftView(Node *root)
{
    int res[1002]={0};
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
              if(res[level]==0)
              res[level]=cur->data;
          }
          else if(cur==NULL){
              level+=1;
              q.push(NULL);
              continue;
          }
          if(cur->left)q.push(cur->left);
          if(cur->right)q.push(cur->right);
      }
      for(int i=0;i<=level;i++){
          cout<<res[i]<<" ";
      }
}



void rightView(Node *root)
{
    int res[1002]={0};
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
              res[level]=cur->data;
          }
          else if(cur==NULL){
              level+=1;
              q.push(NULL);
              continue;
          }
          if(cur->left)q.push(cur->left);
          if(cur->right)q.push(cur->right);
      }
      for(int i=0;i<=level;i++){
          cout<<res[i]<<" ";
      }
}

