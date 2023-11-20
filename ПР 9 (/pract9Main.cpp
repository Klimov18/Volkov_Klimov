#include<iostream>
#include<math.h>
#include<string>

using namespace std;

void func1(double (&x)[101]);
void func2(double (&x)[101]);
void func3(double (&x)[101]);

int main()
{
    double step=0;
    double startPoint=0;
    cout<<"\nНачальная точка x0 = ";
    cin>>startPoint;
    cout<<"Шаг h = ";
    cin>>step;
    cout<<"\n";

    double x[101];
    x[0] = startPoint;
    for (int i = 1; i<=100; i++)
    {
        x[i] = x[i-1]+step;
        //cout<<"x["<<i<<"] = "<<x[i]<<'\n';
    }
    cout<<"FUNCTION SQRT(X^2 + 5)-1 == 5\n";
    func1(x);
    cout<<"FUNCTION MAX(-(X-2)^2 + cos(X))\n";
    func2(x);
    cout<<"FUNCTION SQRT(X^2+0.5)-sin(3*x) == 0\n";
    func3(x);
    return 0;
}

void func1(double (&x)[101])
{
    bool isNotEqual = true;
    cout<<"Function is equal to 5 when X is equal to: ";
    for (int i=0;i<101;i++)
    {
        if(sqrt(pow(x[i],2)+5)-1 == 5)
        {
            isNotEqual = false;
            cout<<x[i]<<"; ";
        }
    }
    if (isNotEqual){cout<<"ERROR";}
    cout<<"\n\n";
};
void func2(double (&x)[101])
{
    cout<<"MAX of function is equal to: ";
    double max = cos(x[0]*0.0174533)-pow((x[0]-2),2);
    string maxIndex = to_string(x[0]);
    for (int i = 1;i<101;i++)if (max<cos(x[i]*0.0174533)-pow((x[i]-2),2))
    {
        max=cos(x[i]*0.0174533)-pow((x[i]-2),2);
        maxIndex += to_string(x[i])+"; ";
    }
    cout<<max<<" when X is equal to: "<<maxIndex;
    cout<<"\n\n";
};
void func3(double (&x)[101])
{
    bool isNotEqual = true;
    cout<<"Function is equal to 0 when X is equal to: ";
    for (int i=0;i<101;i++)
    {
        if(pow((x[i,2]+0.5),2)-sin(3*x[i]*0.0174533) == 0)
        {
            isNotEqual = false;
            cout<<x[i]<<"; ";
        }
    }
    if (isNotEqual){cout<<"ERROR";}
    cout<<"\n\n";
};
