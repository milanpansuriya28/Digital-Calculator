#include<iostream>
#include<cmath>

using namespace std;

//Function : Start Message
    void startMessage(){
        cout << "------------------------------------------" << endl;
        cout << "\t Digital Calculator" << endl;
        cout << "------------------------------------------" << endl;
    }

//----------------------------------------------------------------------Basic Calculator---------------------------------------------------------------------
class BasicCalculator{
public:
    //basic operations loop 
    void basicOperationloop(){
        bool code = true; // condtion for loop
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

    //stop basic operations loop
    bool basicloopExit(bool& code, string choise){
        code = (choise != "1" );
        return code;
    }

};

//---------------------------------------------------------------Scientific Calculator---------------------------------------------------------------------

class ScientificCalculator {
public:
    //Scientific operations loop 
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
    //get user's choise which Scientific operations they want to do
    int sciUserChoice(){
        int sciChoise;
        cout << "X^2 - 1 \nx^3 - 2 \nx^n - 3 \n2^n - 4 \nExit = 0 " << endl;
        cout << "Enter operation : ";
        cin >> sciChoise;

        return sciChoise;
    }

    //Scientific operations
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

    // stop Scientific operations loop
    bool sciLoopExit(bool& code, int choise){
        code = (choise != 0);
        return code;
    }
};

//------------------------------------------------------------------Trigonometry Calculator---------------------------------------------------------------------
class TrigonometryCalculator{
public:
    //Trigonometry Operation loop
    void TrigonometryOperationloop(){
         bool code = true;
        while (code) {
            int func = getTrigonometryFunc();

            trigonometryLoopExit(code, func);

            if (!code) break;

            double angle = getAngle();

            double answer = trigonometryValues(angle, func);
            if (!isnan(answer)) {
                cout << "Result: " << answer << endl;
            } else {
                cout << "Operation failed. Retrying." << endl;
            }
        }
    }
private:
    // Get Trigonometry Functions like sin, cos from user
    int getTrigonometryFunc(){
        int func;
        cout << "Select Trigonometry functiom : \nSin   - 1 \nCos   - 2 \nTan   - 3 \nCosec - 4 \nSec   - 5 \nCot   - 6 \nExit  - 0" << endl;
        cin >> func;
        if(func<7){
            return func;
        }
        else{
            cout << "Invalid";
            return NAN;
        }
    }

    //Get angle from user in radians or degrees
    double getAngle(){
        int unitChoise;
        double angle;
        double radians;
        double degrees;

        cout << "Which units for measuring angles you want to input?" << endl;
        cout << "Radians - 1 \nDegrees - 2" << endl;
        cin >> unitChoise;
        
        if(unitChoise == 1){
            cout << "Enter angle in Radians : ";
            cin >> angle;
        }
        else{
            cout << "Enter angle in Degrees : ";
            cin >> degrees;
            angle = degrees * (M_PI / 180.0);
        }
        return angle;
    }

    //Trigonometry Operation
    double trigonometryValues(double& angle, int& func){
        if(func == 1){
            return sin(angle);
        }
        else if(func == 2){
            return cos(angle);
        }
        else if(func == 3){
           return tan(angle);
        }
        else if(func == 4){
            return (1 / sin(angle));
        }
         else if(func == 5){
            return (1 / cos(angle));
        }
         else{
            return (1 / tan(angle));
        }
    }

    //Stop Trigonometry Operation loop
    bool trigonometryLoopExit(bool& code, int func){
        code = (func != 0);
        return code;
    }
};

int main(){
    //make  Basic Calculator object
    BasicCalculator basicClac; 

    //make Scientific Calculator object
    ScientificCalculator scientificClac;

    //make Trigonometry Calculator object
    TrigonometryCalculator trigonometryClac;

    //Start message
    startMessage();
    
    char calcType;
    cout << "Choose calculator type: \nBasic (b)  \nScientific (s) \nTrigonometry (t) \n: ";
    cin >> calcType;
    
    if(calcType == 'b' || calcType == 'B'){
        basicClac.basicOperationloop();
    }
    else if(calcType == 's' || calcType == 'S'){
        scientificClac.ScientificOperationloop();
    }
    else if(calcType == 't' || calcType == 'T'){
        trigonometryClac.TrigonometryOperationloop();
    }
    else{
        cout << "Invalid Choise!";
    }

    return 0;
}