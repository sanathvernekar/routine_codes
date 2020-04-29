void topView(Node *root)
{
   if(root==NULL)return;
   queue<pair<Node*,int>>q;
   Node *cur=root;
   int pos=0;
   q.push(make_pair(cur,pos));
   //mp[0]=cur->data;
   int newpos;
   map<int,int>mp;
   while(!q.empty() ){
       cur=q.front().first;
       newpos=q.front().second;
       q.pop();
       if(mp.find(newpos)==mp.end())mp[newpos]=cur->data;
       if(cur->left){
           int tst=newpos-1;
           q.push(make_pair(cur->left,tst));
       }
       if(cur->right){
           int tst=newpos+1;
           q.push(make_pair(cur->right,tst));
       }
       
   }
   for(auto ele : mp){
       cout<<ele.second<<" ";
   }
   //64 32 16 8 4 2 1 3 7 15 31 63 
}


