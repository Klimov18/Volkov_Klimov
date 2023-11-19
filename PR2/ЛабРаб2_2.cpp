/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;
class Animal {
    private:
    string name;
    int age;
    public:
    void info(){}
};

class Zebra:Animal{
    private:
    string name = "Толян";
    int age = 5;
    public:
    void info(){
        cout<<"Имя: "<<name<<"\nВозраст: "<<age<<"\n\nЗебра "<<name<<" - Чёткая Зебра\n"<<endl;
    }
};
class Dolphin:Animal{
    private:
    string name = "Камушек";
    int age = 2;
    public:
    void info(){
        cout<<"Имя: "<<name<<"\nВозраст: "<<age<<"\n\nДельфин "<<name<<" - Чёткий Дельфин\n"<<endl;
    }
};

int main()
{
    Zebra zebra;
    zebra.info();
    Dolphin dolphin;
    dolphin.info();
    return 0;
}