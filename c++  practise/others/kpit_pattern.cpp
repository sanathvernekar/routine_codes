#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    int level;
    char ch,my_char;
    int num;
    int j=0;
    //cout<<"Enter the number of levels ,1st character and 1st number "<<endl;
    cin>>level>>ch>>num;
    my_char=ch;
    int i=1;
    while(i<=level)
    {
        for(j=i;j<=level;j++){
            cout<<" ";
        }
        for(int k=0;k<i;k++){
            cout<<my_char<<" ";
            my_char++;
            if(my_char=='{')my_char='a';
            else if(my_char=='[')my_char='A';
            
        }
        i++;
        cout<<endl;
		if(i>level)break;
        for(j=i;j<=level;j++){
            cout<<" ";
        }
        for(int l=0;l<i;l++){
            cout<<num%10<<" ";
            num=num+1;
        }
        cout<<endl;
        i++;
        
    }
    return 0;
}

