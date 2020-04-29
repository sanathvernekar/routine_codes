Node* sortedMerge(Node* head1,   Node* head2)
{
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;
    Node *cur1=head1;
    Node *cur2=head2;
    Node *returnval;
    Node *temp;
    if(cur1->data<cur2->data){returnval=cur1;}
    else {returnval=cur2;}
    while(cur1!=NULL && cur2!=NULL){
        if(cur1->data<cur2->data){
            while(cur1->data<cur2->data){
                temp=cur1;
                cur1=cur1->next;
                if(cur1==NULL)break;
            }
            temp->next=cur2;
        }
        else {
            while(cur2->data<cur1->data){
                temp=cur2;
                cur2=cur2->next;
                if(cur2==NULL)break;
            }
            temp->next=cur1;
        }
    }
    return returnval;
}
