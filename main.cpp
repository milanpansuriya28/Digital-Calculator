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
    cout << "+ , - , / , *, % " << endl;
    cout << "Enter operation : ";
    cin >> choise;

    return choise;
}

// Do operation
double operation(string choise,double num1,double num2 ){
    if(choise == "+"){
        return num1 + num2;
    }
    else if(choise == "-"){
        return num1 - num2;
    } 
    else if(choise == "/"){
        return num1 / num2;
    }
    else if(choise == "*"){
        return num1 * num2;
    }
} 

int main(){
    startMessage();

    double num1, num2;
    cout << "Enter First number : ";
    cin >> num1;
    cout << "Enter Second number : ";
    cin >> num2;

    string choise = userChoise();

    double answer = operation(choise, num1, num2);

    cout << answer;



    return 0;
}