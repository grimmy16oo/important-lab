#include<iostream>
using namespace std;
class books
{
    string author;
    string title;
    int price;
    int stock;
public:
    books() {}
    books(string a,string t,int p,int s)
    {
        author = a;
        title = t;
        price = p;
        stock = s;
    }
    void diplay_details()
    {
        cout << "Book Title : " << title << endl;
        cout << "Author Name : " << author << endl;
        cout << "Book Price : " << price << endl;
        cout << "Stock : " << stock << endl;
    }
    void display_cost()
    {
        int n, cost;
        cout << "How many copies do you want? ";
        cin >> n;

        if(n <= stock)
        {
            cost = n*price;
            cout<<"Total cost : "<<cost<<endl;
        }
        else
            cout << "Required copies not in stock" << endl;
    }
    bool match(string a,string t)
    {
        return (author==a && title==t);
    }
};
void search_book(books b[],int size)
{
    string a,t;
    cout << "Enter Author Name : " << a << endl;
    cin>>a;
    cout << "Enter Book Title : " << t << endl;
    cin>>t;

    for(int i=0; i<size; i++)
    {
        if( b[i].match(a,t) )
        {
            b[i].diplay_details();
            b[i].display_cost();
            return;
        }
    }
    cout<<"Not available"<<endl;
}
int main()
{
    int size = 1;
    books *b = new books[size];

    string a,t;
    int p,s;

    for(int i=0; i<size; i++)
    {
        cout << "Enter Author Name: ";
        cin >> a;
        cout << "Enter Book Title: ";
        cin >> t;
        cout << "Enter Price: ";
        cin >> p;
        cout << "Enter Stock: ";
        cin >> s;

        b[i] = books(a,t,p,s);
    }
    search_book(b,size);

    return 0;
}
