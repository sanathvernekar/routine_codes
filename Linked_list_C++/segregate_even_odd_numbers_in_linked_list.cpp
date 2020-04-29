#include<bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;
struct Node {
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
void print(Node *head){
    Node *cur=head;
    while(cur!=NULL){
        cout<<cur->data<<" ";
        cur=cur->next;
    }
    cout<<endl;
}
Node *evenodd(Node *head){
    Node *cur=head;
    Node *even=NULL;
    Node *odd=NULL;
    Node *etail=NULL;
    Node *otail=NULL;
    while(cur!=NULL){
        if(cur->data%2==0){
            //even
            if(even==NULL){even=cur;cur=cur->next;even->next=NULL;etail=even;}
            else {
                etail->next=cur;
                etail=cur;
                cur=cur->next;
                etail->next=NULL;
            }
        }
        else {
            //odd
            if(odd==NULL){odd=cur;cur=cur->next;odd->next=NULL;otail=odd;}
            else {
                otail->next=cur;
                otail=cur;
                cur=cur->next;
                otail->next=NULL;
            }
        }
        
    }
    if(odd==NULL)return even;
        if(even==NULL)return odd;
        else {
            etail->next=odd;
            return even;
        }
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	    {
	        Node *head=NULL;
	        Node *cur=head;
	        int n;
	        cin>>n;
	        int x;
	        while(n--){
	            cin>>x;
	            if(cur==NULL){
	                head=new Node(x);
	                cur=head;
	            }
	            else {
	                Node *new_node=new Node(x);
	                cur->next=new_node;
	                cur=new_node;
	            }
	        }
	        //print(head);
	        Node *res=evenodd(head);
	        print(res);
	        
	    }
    return 0;
}
