Node *compute(Node *head)
{
    if(head->next==NULL)return head;
    Node *cur=head;
    Node *temp=cur->next;
    Node *res;
    bool flag=false;
    while(temp!=NULL){
        if(temp->data>cur->data){res=temp;flag=true;break;}
        else {
            cur=temp;
            temp=temp->next;
        }
    }
    if(flag==false)return cur;
    else {
        cur=res;
        Node *prev=res;
        if(cur->next==NULL)return res;
        temp=cur->next;
        while(temp!=NULL){
            if(temp->data>cur->data){
                prev->next=temp;
                prev=temp;
                cur=temp;
                temp=temp->next;
            }
            else {
                cur=temp;
                temp=temp->next;
            }
        }
    }
    return res;
    
}
