#include<bits/stdc++.h>
using namespace std;
class DB;
class DM{
        float meter;
        float centimeter;
    public:
        void getvalue(float m,float cm)
        {
            meter = m;
            centimeter = cm;
        }
        friend DM add(DM obj1,DB obj2);
        void display()
        {
            cout<<meter<<" "<<centimeter;
        }
};
class DB{
        float feet;
        float inch;
    public:
        void getvalue(float f,float i)
        {
           feet = f;
           inch = i;
        }
        friend DM add(DM obj1,DB obj2);
        void display()
        {
            cout<<feet<<" "<<inch;
        }
};
DM add(DM obj1,DB obj2)
{
    DM temp;
    temp.meter = obj1.meter + (obj2.feet * 0.30);
    temp.centimeter = obj1.centimeter + (obj2.inch * 2.54);

    return temp;
}

int main()
{
    DM obj1, obj3;
    DB obj2;

    obj1.getvalue(52,870);
    obj2.getvalue(45,897);

    obj3 = add(obj1,obj2);
    obj3.display();

    return 0;
}