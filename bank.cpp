#include <iostream>
#include <cmath>
using namespace std;
class account
{
protected:
    string name;
    int Id;
    string type;

public:
    account() {}
    account(string n, int i, string t)
    {
        name = n;
        Id = i;
        type = t;
    }
};
class current_acc : public account
{
    int min = 1000;
    int charge = 100;
    int balance;

public:
    current_acc() {}
    current_acc(string n, int i, string t, int b) : account(n, i, t)
    {
        balance = b;
    }
    void service_penalty()
    {
        if (balance < min)
        {
            cout << "Penalty applied!" << endl;
            balance -= charge;
        }
    }
    void deposit(int d)
    {
        balance += d;
        service_penalty();
    }
    void withdraw(int w)
    {
        if (w > balance)
            cout << "insufficient money" << endl;
        else
            balance -= w;

        service_penalty();
    }
    void display()
    {
        cout << "current balance : " << balance << endl;
    }
};
class saving_acc : public account
{
    int balance;
    float intrest = 10.0;

public:
    saving_acc(string n, int i, string t,int b) : account(n, i, t) 
    {
        balance = b;
    }

    void deposit(int d)
    {
        balance += d;
    }
    void calc_intrest()
    {
        int year;
        cout << "how many years?" << endl;
        cin >> year;

        balance = balance * pow((1 + intrest / 100), year);
        cout << "the compound interest " << balance << endl;
    }
    void withdraw(int w)
    {
        if (w < balance)
        {
            balance -= w;
            cout << "withdrawed " << w<< "and" << balance << endl;
        }
        else
        {
            cout << "insufficient amount cant withdraw" << endl;
        }
    }
    void display()
    {
        cout << "current balance : " << balance << endl;
    }
};
int main()
{
    string s;
    int i, b, d, w;

    cout << "Enter name: ";
    cin >> s;
    cout << "Enter ID: ";
    cin >> i;
    cout << "Enter initial balance: ";
    cin >> b;


    current_acc c(s, i, "current", b);
    cout << "Enter deposit amount : ";
    cin >> d;
    c.deposit(d);
    cout << "Enter withdraw amount : ";
    cin >> w;
    c.withdraw(w);
    c.display();

    saving_acc sv(s,i,"savings",b);
    cout << "Enter deposit amount : ";
    cin >> d;
    sv.deposit(d);
    sv.calc_intrest();
    cout << "Enter withdraw amount : ";
    cin >> w;
    sv.withdraw(w);
    sv.display();

    return 0;
}
