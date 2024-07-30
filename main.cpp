#include<iostream>
#include<cmath>

using namespace std;

//Function : Start Message
void startMessage(){
    cout << "------------------------------------------" << endl;
    cout << "\t Digital Calculatot" << endl;
    cout << "------------------------------------------" << endl;
}

// Get user choise
string userChoise(){
    string choise;
    cout << "+ , - , / , *, Exit = 1 " << endl;
    cout << "Enter operation : ";
    cin >> choise;

    return choise;
}

// Do operation
double basicOperation(string choise,double num1,double num2 ){
    if(choise == "+"){
        return num1 + num2;
    }
    else if(choise == "-"){
        return num1 - num2;
    } 
    else if(choise == "/"){
        if (num2 == 0){
            cout << "Not divide by 0...";
            return NAN;
        }
        return num1 / num2;
    }
    else if(choise == "*"){
        return num1 * num2;
    }
} 

//exit function for stop basic operation loop
bool basicloopExit(bool& code, string choise);

//basic loop operations loop
void basicOperationloop(){
    bool code = true;
    double num1;
    cout << "Enter First number : ";
    cin >> num1;

    while (code)
    {
    
    double num2;
    cout << endl << "First number is " << num1 << endl;
    cout << "Enter Second number : ";
    cin >> num2;

    string choise = userChoise();

    basicloopExit(code, choise);

    if (!code) break;

    double answer = basicOperation(choise, num1, num2);

    if (!isnan(answer)) {
            cout << "Result: " << answer << endl;
            num1 = answer;
        } else {
            cout << "Operation failed. Retrying with the same first number." << endl;
        }
    }
}

//stop loop
bool basicloopExit(bool& code, string choise){
    code = (choise != "1" );
    return code;
}

int main(){
    startMessage();
    basicOperationloop();

    return 0;
}