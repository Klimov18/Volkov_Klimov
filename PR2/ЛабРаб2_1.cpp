/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
class Mother{
    private:
    int _age = 33;
    public:
    void print(){
        cout<<"Nuhyou Bebru"<<endl;
    }
};
class Dother: Mother{
    private:
    int _age = 18;
    public:
    void print(){
        cout<<"Nuhyou Nohu"<<endl;
    }
};


int main()
{
    Mother mother;
    Dother dother;
    mother.print();
    dother.print();
    return 0;
}