#include<bits/stdc++.h>
using namespace std;
vector<int> twoNumbers(vector<int>& nums) {
        int xorAll=0;
        
        for(int i=0;i<nums.size();i++){
            xorAll=(xorAll^nums[i]);
        }
        
        int bit=xorAll&(~(xorAll-1));
        int number1=0,number2=0;
                 
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]&bit){
                number1=number1^nums[i];
            }
            else{
                number2=number2^nums[i];
            }
        }
        
        return {number1,number2};
        
    }
int main(){

    int t;
    cin>>t;
    while(t--){
    
        int n;
        cin>>n;
        n=(2*n)+2;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<int> numbers=twoNumbers(v);
        sort(numbers.begin(),numbers.end());
        cout<<numbers[0]<<" "<<numbers[1]<<endl;
    }
}
