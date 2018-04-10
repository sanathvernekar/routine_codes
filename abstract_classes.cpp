#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Book{
    protected:
        string title;
        string author;
    public:
        Book(string t,string a){
            title=t;
            author=a;
        }
        virtual void display()=0;

};
using namespace std;
class MyBook : Book{

    private:
        int price;
    public :
        MyBook(string title_,string author_,int price_) : Book(title_,author_) ,price(price_){}

        virtual void display(){
            cout << "Title: " <<Book::title << "\nAuthor: " << Book::author << "\nPrice: " << price << endl;
        }
    
};
int main() {
    string title,author;
    int price;
    getline(cin,title);
    getline(cin,author);
    cin>>price;
    MyBook novel(title,author,price);
    novel.display();
    return 0;
}

