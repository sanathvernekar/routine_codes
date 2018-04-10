#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include<iostream>
using namespace std;
struct node
{
	int height;
	int location;
	bool drowned;
	node *next;	
};
class list
{
		private:
		node *head, *tail;
		public:
		list()
		{
			head=NULL;
			tail=NULL;
		}
		void createnode(int height,int location)
		{
			node *temp=new node;
			temp->height=height;
			temp->location=location;
			temp->drowned=false;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				tail=temp;
				temp=NULL;
			}
			else
			{	
				tail->next=temp;
				tail=temp;
			}
		}
		void display()
		{
			node *temp=new node;
			temp=head;
			while(temp!=NULL)
			{
				cout<<temp->height<<temp->location<<temp->drowned<<"\t";
				temp=temp->next;
			}
		}
		
		void delete_position(int pos)
		{
			node *current=new node;
			node *previous=new node;
			current=head;
			for(int i=1;i<pos;i++)
			{
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
		}
};

int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}




























#include<iostream>
using namespace std;
struct node
{
	int height;
	int location;
	bool drowned;
	node *next;	
};
class list
{
		private:
		node *head, *tail;
		public:
		list()
		{
			head=NULL;
			tail=NULL;
		}
		void createnode(int height,int location)
		{
			node *temp=new node;
			temp->height=height;
			temp->location=location;
			temp->drowned=false;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				tail=temp;
				temp=NULL;
			}
			else
			{	
				tail->next=temp;
				tail=temp;
			}
		}
		void display()
		{
			node *temp=new node;
			temp=head;
			while(temp!=NULL)
			{
				cout<<temp->height<<temp->location<<temp->drowned<<"\t";
				temp=temp->next;
			}
		}
		
		void delete_position(int pos)
		{
			node *current=new node;
			node *previous=new node;
			current=head;
			for(int i=1;i<pos;i++)
			{
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
		}
        void drown(int pos)
        {
            node *temp=new node;
            temp=head;
            while(temp!=NULL){
                if(temp->location==pos){
                    temp->drowned==true;
                    
                    break;
                }
                temp=temp->next;
            }
            /*for(int x2=1;x2<pos;x2++){
                temp=temp->next;
            }
            temp->drowned=true;*/
        }
        void evacuate(int pos)
		{
            node *temp=new node;
            temp=head;
            node *temp2=new node;
            
            
			//node *current=new node;
			//node *previous=new node;
			//current=head;
			for(int x1=1;x1<pos;x1++)
			{
                temp=temp->next;
                
                
				//previous=current;
				//current=current->next;
			}
			//previous->next=current->next;
            temp2=temp;
            int count=pos;
            while(temp2!=NULL){
                if(temp2->height>temp->height  ){
                    if(temp2->drowned==false){
                        cout<<temp2->location<<endl;
                    break;
                        
                    }
                    else{
                        cout<<"DROWNED"<<endl;
                    }
                    
                }
                
                else{
                    temp2=temp2->next;
                    count=count+1;
                }
            }
            if(temp2==NULL){
                cout<<"IMPOSSIBLE"<<endl;
            }
		}
};
int main()
{
	list obj;
	int num,query;
    cin>>num;
    int i,j;
    char status;
    
    int height,location;
    bool drowned;
    for(i=0;i<num;i++){
        cin>>location>>height;
        obj.createnode(height,location);   
    }
    cin>>query;
    for(j=0;j<query;j++){
        cin>>status>>location;
        if(status=='e'){
            obj.evacuate(location);
            
        }
        else{
            obj.drown(location);
        }
    }
    obj.display();
	return 0;
}
