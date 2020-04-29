
// get intersection point from 2 linked lists in the shape of Y with different lengths
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int l1=1;
    int l2=1;
    if(head1==NULL || head2==NULL)return -1;
    Node *cur1=head1;
    Node *cur2=head2;
    while(cur1!=NULL){
        cur1=cur1->next;
        l1+=1;
    }
    while(cur2!=NULL){
        cur2=cur2->next;
        l2+=1;
    }
    //cout<<l1<<" "<<l2<<endl;
    if(l1>l2){
        cur1=head1;
        cur2=head2;
        while(l1>l2){
            cur1=cur1->next;
            l1-=1;
        }
    }
    else if(l2>l1){
        cur2=head2;
        cur1=head1;
        while(l2>l1){
            cur2=cur2->next;
            l2-=1;
        }
    }
    //here l1=l2
    
    bool flag=false;
    while(cur1!=NULL || cur2!=NULL){
        if(cur1==cur2){flag=true;return cur1->data;break;}
        cur1=cur1->next;
        cur2=cur2->next;
    }
    return -1;
}

