#include <iostream>
using namespace std;

int main()
{
    double num1, num2, result;
    int choice;

    cout << "=====================================\n";
    cout << "        SIMPLE CALCULATOR\n";
    cout << "=====================================\n";

    cout << "Enter First Number: ";
    cin >> num1;

    cout << "Enter Second Number: ";
    cin >> num2;

    cout << "\nChoose an Operation:\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";

    cout << "\nEnter Your Choice (1-4): ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            result = num1 + num2;
            cout << "\nResult = " << result;
            break;
        case 2:
            result = num1 - num2;
            cout << "\nResult = " << result;
            break;
        case 3:
            result = num1 * num2;
            cout << "\nResult = " << result;
            break;
        case 4:
            if (num2 != 0)
            {
                result = num1 / num2;
                cout << "\nResult = " << result;
            }
            else
            {
                cout << "\nError! Division by zero is not allowed.";
            }
            break;
        default:
            cout << "\nInvalid Choice!";
    }

    cout << "\n\nThank You for Using the Calculator!" << endl;

    return 0;
}
