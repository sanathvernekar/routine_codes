#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define NO_OF_CHARS 256
bool ispalindrome(string str){
    size_t len = str.length();

    for(int i = 0; i < len/2; i++){
        if(str[i] != str[len-1-i]){
            return false;
        }
    }
    return true;
}

bool canFormPalindrome(string str)
{
    if(ispalindrome(str)){
        return true;
    }
    int len=str.length();
    int pos;
    int count[NO_OF_CHARS] = {0};
    int fake_count=0;
    for (int i = 0; str[i];  i++)
        count[str[i]]++;
    int odd = 0;
    for (int i = 0; i < NO_OF_CHARS; i++)
    {
        if (count[i] & 1)
            odd++;
 
        if (odd > 1)
            return false;
    }

    //cout<<len<<" string length"<<endl;
    int lmt=(int )len/2;
    //cout<<str<<endl;
    for (int j=0;j<lmt;j++){
        //cout<<str[j]<<" "<<str[len-j-1]<<endl;
        if(str[j]!=str[len-j-1] )
        {
        
        if(fake_count==1){
            //cout<<str[j]<<" "<<exep1<<endl;
            string my_string =str;
            my_string[pos]=str[j];
            my_string[j]=str[pos];
            //cout<<my_string<<endl;
            if(ispalindrome(my_string))
            {
                return true;
            }
            
        }
        pos=j;
        ++fake_count;
        if(fake_count>2)
        return false;
        
        }
        
        
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    
    
    char s[100000];
    for (int i=0;i<n;i++)
    {
            cin>>s;
            canFormPalindrome(s)? cout << "Yes\n": 
                                     cout << "No\n";
        
    }
   
  return 0;
}
