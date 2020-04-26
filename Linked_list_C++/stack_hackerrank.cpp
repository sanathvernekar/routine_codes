int main() {
    int N;
    cin >> N;
    
    vector <int> s;
    vector <int> max;
    max.push_back(0);
    while (N--) {
        int q;
        cin >> q;
        
        if (q==1) {
            int x;
            cin >> x;
            s.push_back(x);
            if ((x>=max.back())) max.push_back(x);
        }
        else if (q==2) {
            if (s.back()==max.back()) max.pop_back();
            s.pop_back();
        }    
        else cout << max.back() << endl;
    }

    return 0;
}


//code which i tried
/*
class stack{
    int *arr;
    int top;
    //int prev_max;
    //int prev_min;
    int max;
    int min;
    public:
    stack(int size=SIZE);
    int peak();
    void push(int );
    void pop();
    
}
stack::stack(int size){
    arr=new int[size];
    top=-1;
    max=0;
    min=0;
}
void stack::push(int x){
    top=top+1;
    arr[top]=x;
    if(x>max){
        max=x;
    }
    if(x<min){
        min=x;
    }
    //top=top+1;
}
void stack::pop(){
    delete arr;
    top=top-1;
    
    //return(arr[top--]);
}
int stack::peak(){
    return(arr[top]);
}

*/

