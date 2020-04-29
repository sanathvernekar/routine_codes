struct node *reverse (struct node *head, int k)
{ 
  node *tail=head;//for first time
  node *cur=head;//cur val
  node *curhead;
  node *temp=cur->next;//ahead of 1
  node *returnval;//returnable value
  cur->next=NULL;
  node *prev=cur;//below 1
  cur=temp;
  for(int i=0;i<k-1;i++){
      if(temp==NULL)continue;
      else {
          temp=cur->next;
          cur->next=prev;
          prev=cur;
          cur=temp;
      }
  }
  returnval=prev;
  curhead=prev;
  //printList(temp);
   
  //tail->next=temp;
  
  
  while(temp!=NULL){
      node *prevtail=tail;
      temp=cur->next;
      cur->next=NULL;
      prev=cur;
      tail=cur;
      cur=temp;
      //if(temp!=NULL)cout<<"prevtail "<<prevtail->data<<" tail "<<tail->data<<" temp "<<temp->data<<" cur "<<cur->data<<" prev "<<prev->data<<endl;
      //printList(temp);
      
      for(int i=0;i<k-1;i++){
          if(temp==NULL)continue;
          else{
              temp=cur->next;
              cur->next=prev;
              prev=cur;
              cur=temp;
              //printList(prev);
          }
          
      }
      prevtail->next=prev;
      //tail=prev;
  }
  
  
  
  return returnval;
}

