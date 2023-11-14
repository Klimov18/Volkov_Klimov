#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

int main (){

char login []="VanyaNikita";
char password[]="1234";
char str[30];
int counter(0);

do{
	cout << "Введите Логин: ";
	cin >> str;
	if(!strcmp(login,str)) break;
	else cout << "Неправильный логин,ввидите его снова.\n";
	counter++;
}while(counter < 3);

if(counter == 3){
	cout<<"401.Not authorized.\n";
	exit(0);
}

cout << "Логин верный осталось совсем чуть чуть.\n";

do{
	cout << "Введите пароль: ";
	cin >> str;
	if(!strcmp(password,str)) break;
	else cout << "Неверный пароль, ввидите его снова.\n";
	counter++;
} while(counter < 3);

if(counter == 3){
	cout<<"401.Not authorized.\n";
	exit(0);
}
cout << "You successfull VanyaNikita, user VanyaNikita.\n";

return 0;
}

