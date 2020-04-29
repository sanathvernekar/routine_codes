Node *flatten(Node *root)
{
   if(root==NULL)return root;
   Node *cur=root;
   int a[1001]={0};
   queue<Node*>q;
   q.push(cur);
   int min=1001;
   while(!q.empty()){
       cur=q.front();
       if(cur->data<min)min=cur->data;
       a[cur->data]+=1;
       if(cur->next!=NULL)q.push(cur->next);
       if(cur->bottom!=NULL)q.push(cur->bottom);
       q.pop();
   }
   Node *cur_move=new Node;
   cur_move->data=min;
   cur_move->bottom=NULL;
   cur_move->next=NULL;
   Node *returnval=cur_move;
   a[min]-=1;
   for(int i=min;i<1001;i++){
       while(a[i]>0){
           Node *cur_new=new Node;
           cur_new->data=i;
           cur_new->next=NULL;
           cur_new->bottom=NULL;
           cur_move->bottom=cur_new;
           cur_move=cur_new;
           a[i]-=1;
       }
   }
   return returnval;
}
