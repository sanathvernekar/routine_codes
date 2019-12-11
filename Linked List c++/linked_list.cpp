struct Node
  {
     int data;
     struct Node *next;
  }


//linked list traversal
void Print(Node *head)
{ 
       Node *temp = head;  
       while(temp != NULL){
            std::cout << temp->data << endl;
            temp = temp->next;
    }
    
}
//insert new node
Node* Insert(Node *head,int data)
{
Node *temp=new Node();
temp->data = data;
temp->next = NULL;

if(head == NULL)
  {
  head = temp;
}
else
  {
  Node *p;
  p = head;
  while(p->next != NULL)
      p = p->next;
  p->next = temp;
}
return(head);
}
//Insert node at the head of linked list

Node* Insert(Node *head,int data)
{
  // Complete this method
    Node *temp = new Node();
    Node *cpyhead = head;
    temp->data = data;
    temp->next = cpyhead;
    head=temp;
    return head;
}

//insert at nth position
Node* InsertNth(Node *head, int data, int position)
{
    Node *root;
    root= head;
    
    Node *temp = new Node();
    temp->data=data;
    
    if (position<0){return NULL; }
    else if (position==0){
        temp->next= head;
        return temp;
    }else{
        while(position-1>0){
            position--;
            head= head->next;
        }
            temp->next= head->next;
            head->next= temp;

        return root;
    }

    
}



//to delete a node at nth position


Node* Delete(Node *head, int position)
{
     Node *root;
    Node *before;
    before=head;
    root=head;
    if(position<0){return NULL;}
    else if(position==0){
        root=head->next;
        return root;
    }
    else{
        while(position>0){
            position--;
            before=head;
            head=head->next;
            
            
            
        }
        before->next=head->next;
        delete head;
        return root;
        
        
    }
    
  
}

//print reverse order of linked list recursion method
void ReversePrint(Node *head){
    if(head==NULL) return;
    else{
        ReversePrint(head->next);
        cout<<head->data<<endl;
    }
}

//print reverse order of singly linked list without recursion

void ReversePrint(Node *head)
{
    struct Node* last = NULL;
    while(head != NULL) {
        struct Node* temp = new Node;
        temp->data = head->data;
        temp->next = last;
        last = temp;
        head = head->next;
    }
    
    while(last != NULL) {
        cout<<last->data<<endl;
        last = last->next;
    }
}


//another method of reversing an linked list without recursion
//faster method compared to recursion
//best one
//less memory constraint
void ReversePrint(Node *head) {
        if (!head) return;

        auto reverse = [](Node* head, bool print) {
            auto curr = head->next;
            head->next = nullptr;

            auto prev = head;
            while (curr) {
                if (print) cout << prev->data << "\n";

                auto temp = curr->next;
                curr->next = prev;
                prev = curr;

                curr = temp;
            }

            if (print) cout << prev->data << "\n";
            return prev;
        };

        head = reverse(head, false);
        head = reverse(head, true);
    }

//return a reverse of a linked list 
//better solution
Node* Reverse(Node *head)
{
    Node *tail, *t;
    tail = NULL;
    while (head != NULL) {
        t = head->next;
        head->next = tail;
        tail = head;
        head = t;
    }
    return tail;
  // Complete this method
}




//based on non-recursive method 
// Non-recursive version
Node* Reverse(Node *head)
{
    Node *tail, *t;
    tail = NULL;
    while (head != NULL) {
        t = head->next;
        head->next = tail;
        tail = head;
        head = t;
    }
    return tail;
  // Complete this method
} 
 

// Recursive version
Node* Reverse(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *newhead = Reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newhead;
}


// Non-recursive version, using stack
#include <stack>
Node *Reverse(Node *head)
{
    if (head != nullptr)
    {
    Node *curr = head;
    std::stack<Node *> ps;
    while(curr)
    {
        ps.push(curr);
        curr = curr->next;
    }
        Node *newhead = ps.top();
    while(!ps.empty())
        {
        Node *prev = ps.top();
        ps.pop();
        prev->next = ps.empty()? nullptr : ps.top();
    }

        return newhead;
    }
    return head;
}


//compare 2 linked list
int CompareLists(Node *headA, Node* headB)
{
   if (headA == NULL && headB == NULL) {
	return 1;
} else if (headA == NULL || headB == NULL) {
	return 0;
}

if (headA->data == headB->data) {
	return CompareLists(headA->next, headB->next);
} else {
	return 0;
}
}


//merge 2 sorted list
Node* MergeLists(Node *headA, Node* headB)
{
    if (headA == NULL && headB == NULL) return NULL;
else if (headA == NULL) return headB;
else if (headB == NULL) return headA;

if(headA->data <= headB->data)
    headA->next = MergeLists(headA->next, headB);

else {
    Node* temp = headB;
    headB = headB->next;
    temp->next = headA;
    headA = temp;
    headA->next = MergeLists(headA->next, headB);
}

return headA;
}

//print data of nth node from tail

int GetNode(Node *head,int positionFromTail)
{
    int index = 0;
    Node* current = head;
    Node* result = head;
    while(current!=NULL)
    {
        current=current->next;
        if (index++>positionFromTail)
        {
            result=result->next;
        }
    }
    return result->data;
}
//delete similar linked list numbers
Node* RemoveDuplicates(Node *head)
{
    if(head=='\0' || head->next=='\0')
        return head;
        else
        {
        Node *current=head;
        while(current->next!='\0')
            {
            if(current->data!= current->next->data)
            current=current->next;
            else
               {
               delete current->next;
               current->next=current->next->next;
               }
        }
            return head;
    }
    
}

