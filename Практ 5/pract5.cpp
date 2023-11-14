/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

int generateRandomNumberInt();
string inputString();
bool inputEqualsNotNumberString(string input, string number);
void inputHowCloseToNumberString(string input, string number);

int main()
{
    string numberString = to_string( generateRandomNumberInt( ));
    int turns = 0;
    
    string input;
    do {
        input = inputString();
        inputHowCloseToNumberString(input, numberString);
        turns+=1;
    }
    while (inputEqualsNotNumberString(input, numberString));
    cout<<"\nYou Won! Congrats!\n";
    cout<<"You needed: "<<turns<<" turns! ";
    if (turns>3){
        cout<<"You can do better!\n";
        return 0;
    }
    cout<<"Amazing!\n";
    
    return 0;
}

int generateRandomNumberInt(){
  srand(time(NULL));
  int num = 1000 + rand() % (9999 - 1000 + 1);

  return num;
};

string inputString(){
    string inputt;
    do {
    cout<<"Guess the Number from 1000 to 9999\n"<<endl;
    getline(cin, inputt);
	if (inputt == "exit" or inputt == "q" or inputt == "wq"){exit(0);}
    if (inputt.length()!=4 or stoi(inputt)<=999){
        cout << "Dumbass ";
        continue;
    }
    }
    while (inputt.length()!=4 or stoi(inputt)<=999);
    return inputt;
};


bool inputEqualsNotNumberString(string input, string numberString){
    return input!=numberString;
};

void inputHowCloseToNumberString(string input, string numberString){
    for (int i = 0; i < 4; i++){
            if (input [i] == numberString[i]) { cout << "Горячо "; continue;}
            
            if ( (input[i] == numberString[i-3]) + (input[i] == numberString[i-2]) + (input[i] == numberString[i-1]) + (input[i] == numberString[i+1]) + (input[i] == numberString[i+2]) + (input[i] == numberString[i+3])){
                cout << "Тепло "; continue;
            }
            
            if (input[i] != numberString[i]) { cout << "Холодно "; continue;}
        }
    cout<<'\n';
};
