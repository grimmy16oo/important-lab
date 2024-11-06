#include <iostream>
#include <cmath>
using namespace std;
class polar;
class cartesian
{
public:
    double x, y;
    cartesian() {}
    cartesian(double a, double b)
    {
        x = a;
        y = b;
    }
    cartesian convert(const polar &p);
    void display()
    {
        cout << "cartesian co-ordinates : " << endl;
        cout << x << " " << y << endl;
    }
};
class polar
{
public:
    double r, theta; // theta in degree
    polar() {}
    polar(double a, double b)
    {
        r = a;
        theta = b;
    }
    polar convert(const cartesian &c);
    void display()
    {
        cout << "polar co-ordinates : " << endl;
        cout << r << " " << theta << endl;
    }
};
cartesian cartesian ::convert(const polar &p)
{
    cartesian temp;
    double radian = p.theta * (M_PI / 180);

    temp.x = p.r * cos(radian); // in redian
    temp.y = p.r * sin(radian);

    return temp;
}
polar polar ::convert(const cartesian &c)
{
    polar temp;
    temp.r = sqrt(c.x * c.x + c.y * c.y);
    temp.theta = atan2(c.y, c.x) * (180 / M_PI); // in degree

    return temp;
}

int main()
{
    cartesian c(3, 4),c1;
    polar p(15, 60),p1;

    cout << "Before Conversion :" << endl;
    c.display();
    p.display();

    c1 = c.convert(p);
    p1 = p.convert(c);

    cout << "after conversion : " << endl;
    c1.display();
    p1.display();

    return 0;
}
