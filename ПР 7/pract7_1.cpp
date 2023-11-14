#include <iostream> 
#include <stdlib.h>
#include <stack> 
#include <string> 
#include <sstream> 
#include <stdexcept> 
 
using namespace std; 
 
// Функция для проверки, является ли символ оператором 
bool isOperator(char c) { 
    return c == '+' or c == '*' or c == '/' or c == '-' or c == '^'; 
} 
 
// Функция для проверки, является ли символ цифрой 
bool isDigit(char c) { 
    return c >= '0' and c <= '9'; 
} 
 
// Функция для выполнения операции над двумя числами 
double calculate(double a, double b, char op) { 
    switch (op) { 
        case '+': 
            return a + b; 
        case '-': 
            return a - b; 
        case '*': 
            return a * b; 
        case '/': 
            if (b == 0) { 
                throw runtime_error("Деление на ноль запрещено!"); 
            } 
            return a / b; 
        default: 
            throw runtime_error("Некорректный оператор!"); 
    } 
} 
 
// Функция для рассчета выражения 
double evaluateExpression(const string& expression) { 
    stack<double> numbers; 
    stack<char> operators; 
 
    for (int i = 0; i < expression.length(); i++) { 
        if (expression[i] == ' ') { 
            continue; 
        } 
        if (isDigit(expression[i])) { 
            stringstream ss; 
            while (i < expression.length() && (isDigit(expression[i]) || expression[i] == '.')) { 
                ss << expression[i]; 
                i++; 
            } 
            i--; 
            double number; 
            ss >> number; 
            if (ss.fail()) { 
                throw runtime_error("Недопустимый формат числа!"); 
            } 
            numbers.push(number); 
        } else if (expression[i] == '(') { 
            operators.push('('); 
        } else if (expression[i] == ')') { 
            while (!operators.empty() && operators.top() != '(') { 
                double b = numbers.top(); 
                numbers.pop(); 
 
                double a = numbers.top(); 
                numbers.pop(); 
 
                char op = operators.top(); 
                operators.pop(); 
 
                double result = calculate(a, b, op); 
                numbers.push(result); 
            } 
            if (operators.empty()) { 
                throw runtime_error("Непарная закрывающая скобка!"); 
            } 
            operators.pop(); 
        } else if (isOperator(expression[i])) { 
            while (!operators.empty() && isOperator(operators.top()) && 
                   ((expression[i] != '/' && expression[i] != '*') || (operators.top() != '+' && operators.top() != '-'))) { 
                double b = numbers.top(); 
                numbers.pop(); 
 
                double a = numbers.top(); 
                numbers.pop(); 
 
                char op = operators.top(); 
                operators.pop(); 
 
                double result = calculate(a, b, op); 
                numbers.push(result); 
            } 
            operators.push(expression[i]); 
        } else { 
            throw runtime_error("Некорректный символ: " + string(1, expression[i])); 
        } 
    } 
 
    while (!operators.empty()) { 
        double b = numbers.top(); 
        numbers.pop(); 
 
        double a = numbers.top(); 
        numbers.pop(); 
 
        char op = operators.top(); 
        operators.pop(); 
 
        double result = calculate(a, b, op); 
        numbers.push(result); 
    } 
 
    if (numbers.size() == 1) { 
        return numbers.top(); 
    } else { 
        throw runtime_error("Некорректное выражение!"); 
    } 
} 
 
int main() { 
    string expression; 
    cout << "Введите математическое выражение: "; 
    getline(cin, expression); 
 
    try { 
        double result = evaluateExpression(expression); 
if (result>-18446744073709551615 or result<18446744073709551615){cout<<"Некорректный ввод "; exit(0);}
        cout << "Результат: " << result << endl; 
    } catch (const exception& e) { 
        cout << "Ошибка: " << e.what() << endl; 
    } 
 
    return 0; 
}
