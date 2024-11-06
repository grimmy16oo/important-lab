#include <iostream>
#include <vector>
using namespace std;
class booking
{
    string name;
    string phone;
    int seat_no;

public:
    booking() {};
    booking(string n, string p, int seat)
    {
        name = n;
        phone = p;
        seat_no = seat;
    }
    void display()
    {
        cout << "Customer Name: " << name << endl;
        cout << "Phone Number: " << phone << endl;
        cout << "Seat Number: " << seat_no << endl;
    }
};
int main()
{
    vector<booking> v;

    string n, p;
    int seat;
    char choice, add;

    do
    {
        cout << "Enter your name : " << endl;
        cin>>n;
        cout << "Enter your phone no : " << endl;
        cin>>p;
        cout << "do you want to specify your seat no?  (y/n)" << endl;
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            cout << "Enter your seat no : " << endl;
            cin >> seat;
        }
        else
            seat = 1;

        v.push_back(booking(n, p, seat));
        cout << "Do you want to book another ticket? (y/n): " << endl;
        cin >> add;
    } while (add == 'y' || add == 'Y');

    for (int i = 0; i < v.size(); i++)
    {
        v[i].display();
        cout << "-------------------\n";
    }
}
