#include<iostream>
#include<cmath>

using namespace std;

class BasicCalculator{
public:
    //Function : Start Message
    void startMessage(){
        cout << "------------------------------------------" << endl;
        cout << "\t Digital Calculatot" << endl;
        cout << "------------------------------------------" << endl;
    }

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

private:
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
        else {
            cout << "Invalid operation." << endl;
            return NAN;
        }
    } 

    //stop loop
    bool basicloopExit(bool& code, string choise){
        code = (choise != "1" );
        return code;
    }

};

class ScientificCalculator {
public:
     void ScientificOperationloop(){
         bool code = true;
        while (code) {
            int choice = sciUserChoice();

            sciLoopExit(code, choice);

            if (!code) break;

            double answer = sciOperation(choice);
            if (!isnan(answer)) {
                cout << "Result: " << answer << endl;
            } else {
                cout << "Operation failed. Retrying." << endl;
            }
        }
    }
private:
    int sciUserChoice(){
        int sciChoise;
        cout << "X^2 - 1 \nx^3 - 2 \nx^n - 3 \n2^n - 4 \nExit = 0 " << endl;
        cout << "Enter operation : ";
        cin >> sciChoise;

        return sciChoise;
    }

    double sciOperation(int sciChoise){
        if(sciChoise == 1){
            cout << "Enter \"x\" value :";
            int x;
            cin >> x;
            return pow(x, 2);
        }
        else if(sciChoise == 2){
            cout << "Enter \"x\" value :";
            int x;
            cin >> x;
            return pow(x, 3);
        }
        else if (sciChoise == 3){
            int x, n;
            cout << "Enter \"x\" value :";
            cin >> x;
            cout << "Enter \"n\" value :";
            cin >> n;
            
            return pow(x, n); 
        }
        else if (sciChoise == 4){
            int n;
            cout << "Enter \"n\" value :";
            cin >> n;
            return pow(2, n);
        }
        else {
            cout << "Invalid operation." << endl;
            return NAN;
        }
    }
    bool sciLoopExit(bool& code, int choise){
        code = (choise != 0);
        return code;
    }
};

int main(){
    BasicCalculator basicClac;
    ScientificCalculator scientificClac;
    basicClac.startMessage();
    char calcType;
    cout << "Choose calculator type: Basic (b) or Scientific (s): ";
    cin >> calcType;
    
    if(calcType == 'b' || calcType == 'B'){
    basicClac.basicOperationloop();
    }
    else if(calcType == 's' || calcType == 'S')
    scientificClac.ScientificOperationloop();
    else{
        cout << "Invalid Choise!";
    }

    return 0;
}