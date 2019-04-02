#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tc int t; cin >> t; while(t--)

ll digits(ll n){
    ll res=0;
    while(n>0){
        n=n/10;
        res+=1;
    }
    return res;
}
ll query(ll num,ll l, ll r){
    ll res=0;
    if(num==2){
        ll a[10]={1,0,1,0,1,0,1,0,1,0};
        for(ll i=l;i<=r;i++)res+=a[i];
        return res;
    }
    else if(num==3){
        ll b[10]={1,0,0,1,0,0,1,0,0,1};
        for(ll i=l;i<=r;i++)res+=b[i];
        return res;
    }
    else if(num==6){
        ll c[10]={1,0,0,0,0,0,1,0,0,0};
        for(ll i=l;i<=r;i++)res+=c[i];
        return res;
    }
    else return 0;
}

int main()
{
	FIO;
	{
       ll l,r;
       cin>>l>>r;
       ll d;
       ll count =0;
       ll i;
       ll temp;
       bool lflag=true;
       bool rflag=true;
       ll fnum=0,snum=0;
       //from 0 to i digit
       
       ll two[10]={5,4,4,3,3,2,2,1,1,0};
       ll three[10]={4,3,3,3,2,2,2,1,1,1};
       ll five[10]={1,1,1,1,1,1,0,0,0,0};
       ll six[10]={2,1,1,1,1,1,1,0,0,0};
       ll seven[10]={1,1,1,1,1,1,1,1,0,0};
        //from i to 9 digit
       ll two_[10]={1,1,2,2,3,3,4,4,5,5};
       ll three_[10]={1,1,1,2,2,2,3,3,3,4};
       ll five_[10]={0,0,0,0,0,1,1,1,1,1};
       ll six_[10]={1,1,1,1,1,1,2,2,2,2};
        ll seven_[10]={0,0,0,0,0,0,0,1,1,1};
       
       if(l<10)count=10-l,l=10;
       else {
           ll ld=digits(l);
           ll rd=digits(r);
           ll larray[ld];
           ll rarray[rd];
           //create an array of numbers
           ll val=l;
           for(i=0;i<ld;i++){
               d=val%10;
               larray[ld-i-1]=d;
               val=val/10;
           }
           val=r;
           for(i=0;i<rd;i++){
               d=val%10;
               rarray[rd-i-1]=d;
               val=val/10;
           }
           
           
           
           if(rd==18)r=r-1,rd=rd-1;
           
           if(ld!=rd){
               ll llimit,rlimit;
               //calclate llmiit and rlimit
               
               
               
               //till l+1 digit to r-1 digit count PR numbers
               for(i=ld+1;i<=rd-1;i++){
                   //check if i should be equal or less than rd 
                   count+=(two[1]*pow(5,i-1));
                   count+=(three[1]*pow(4,i-1));
                   count-=(six[1]*pow(2,(i-1)));
                   count+=(five[1]);
                   count+=seven[1];
               }
               
               
               
               
            cout<<count<<endl;
               
           }
           else {
               ll pos;
               for(i=0;i<ld;i++){
                   if(larray[i]==rarray[i])continue;
                   else {pos=i;break;}
               }
                temp=query(2,larray[pos],rarray[pos]);
                if(temp!=0){
                   
                   if(temp>2){count+=((temp-2)*pow(5,(ld-pos-1)));temp=2;}
                   else if(temp==1 && larray[pos]%2==1 && rarray[pos]%2==1 ){count+=(pow(5,(ld-pos-1)));rflag=false;lflag=false;}
                   else if(temp==1 && larray[pos]%2==1 && rarray[pos]%2==0)lflag=false;
                   else if(temp==1 && larray[pos]%2==0 && rarray[pos]%2==1)rflag=false;
                   else if(temp==2 && larray[pos]%2==1 && rarray[pos]%2==1){count+=(2*pow(5,(ld-pos-1)));lflag=false;rflag=false;}
                   else if(temp==2 && larray[pos]%2==1 && rarray[pos]%2==0){count+=(pow(5,(ld-pos-1)));lflag=false;}
                   else if(temp==2 && larray[pos]%2==0 && rarray[pos]%2==1){count+=(pow(5,(ld-pos-1)));rflag=false;}
                   //else if(temp>2 && larray[pos]%2==1 && rarray[pos]%2==1){count+=(2*pow(5,(ld-pos-1)));lflag=false;rflag=false;}
                   //else if(temp>2 && larray[pos]%2==1 && rarray[pos]%2==0){count+=(pow(5,(ld-pos-1)));lflag=false;}
                   //else if(temp>2 && larray[pos]%2==0 && rarray[pos]%2==1){count+=(pow(5,(ld-pos-1)));rflag=false;}
                   for(i=pos+1;i<ld;i++){
                       if(lflag==true){
                           //do left operation
                           temp=query(2,larray[i],9);
                           if(larray[i]%2!=0){
                               count+=(temp*pow(5,(ld-i-1)));
                               lflag=false;
                           }
                           else count+=((temp-1)*pow(5,(ld-i-1)));
                       }
                       if(rflag==true){
                           //do right operation
                           temp=query(3,0,rarray[i]);
                           if(rarray[i]%2!=0){
                               count+=(temp*pow(5,(ld-i-1)));
                               rflag=false;
                           }
                           else count+=((temp-1)*pow(5,(ld-i-1)));
                       }
                   }
                   if(lflag==true)count+=1;
                   if(rflag==true)count+=1;
               }
                lflag=true;rflag=true;
                temp=query(3,larray[pos],rarray[pos]);
                if(temp!=0){
                   if(temp>2){count+=((temp-2)*pow(4,(ld-pos-1)));temp=2;}
                   else if(temp==1 && larray[pos]%3!=0 && rarray[pos]%3!=0){count+=(pow(4,(ld-pos-1)));lflag=false;rflag=false;}
                   else if(temp==1 && larray[pos]%3!=0 && rarray[pos]%3==0)lflag=false;
                   else if(temp==1 && larray[pos]%3==0 && rarray[pos]%3!=0)rflag=false;
                   else if(temp==2 && larray[pos]%3!=0 && rarray[pos]%3!=0){count+=(2*pow(4,(ld-pos-1)));lflag=false;rflag=false;}
                   else if(temp==2 && larray[pos]%3!=0 && rarray[pos]%3==0){count+=(pow(4,(ld-pos-1)));lflag=false;}
                   else if(temp==2 && larray[pos]%3==0 && rarray[pos]%3!=0){count+=(pow(4,(ld-pos-1)));rflag=false;}
                    for(i=pos+1;i<ld;i++){
                        if(lflag==true){
                            temp=query(3,larray[i],9);
                            if(larray[i]%3!=0){
                                count+=(temp*pow(4,(ld-i-1)));
                                lflag=false;
                            }
                            else count+=((temp-1)*pow(4,(ld-i-1)));
                        }
                        if(rflag==true){
                            temp=query(3,0,rarray[i]);
                            if(rarray[i]%3!=0){
                                count+=(temp*pow(4,(ld-i-1)));
                                rflag=false;
                            }
                            else count+=((temp-1)*pow(4,(ld-i-1)));
                        }
                    }
                    if(lflag==true)count+=1;
                    if(rflag==true)count+=1;
               }
                lflag=true;rflag=true;
                temp=query(6,larray[pos],rarray[pos]);
                if(temp!=0){
                    if(temp==2 && larray[pos]%6==0 && rarray[pos]%6!=0){count-=(pow(2,(ld-i-1)));rflag=false;}
                    else if(temp==1 && larray[pos]%6!=0 && rarray[pos]%6!=0){count-=(pow(2,(ld-i-1)));rflag=false;lflag=false;}
                    else if(temp==1 && larray[pos]%6!=0 && rarray[pos]%6==0)lflag=false;
                    else if(temp==1 && larray[pos]%6==0 && rarray[pos]%6!=0)rflag=false;
                    for(i=pos+1;i<ld;i++){
                        if(lflag==true){
                            temp=query(6,larray[i],9);
                            if(larray[i]%6!=0){
                                count-=(temp*pow(2,(ld-i-1)));
                                lflag=false;
                            }
                            else count-=((temp-1)*pow(2,ld-i-1));
                        }
                        if(rflag==true){
                            temp=query(6,0,rarray[i]);
                            if(rarray[i]%6==0){
                                count-=(temp*pow(2,(ld-i-1)));
                                rflag=false;
                            }
                            else count-=((temp-1)*pow(2,(ld-i-1)));
                        }
                    }
                    if(lflag==true)count-=1;
                    if(rflag==true)count-=1;
                }
                
               for(i=0;i<ld;i++){
                   fnum+=(5*pow(10,i));
               }
               if(fnum>=l && fnum<=r)count+=1;
               for(i=0;i<ld;i++){
                   snum+=(7*pow(10,i));
               }
               if(snum>=l && snum<=r)count+=1;
               cout<<count<<endl;
           }
          
       }
       
    }


return 0;
}