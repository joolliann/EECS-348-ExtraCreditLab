#include <iostream>
#include <iomanip> 
#include <string>
using namespace std;

double extractNumeric(const string& str);
int char_digit(char c);

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4)
                 << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}

double extractNumeric(const string& str) {
    double result = 0.0;
    double decimalDivisor = 1.0;
    bool negative = false;
    bool decimal = false;
    //initialize result and divisor
    //along with this create values to denote whether or not the number is negative and has a decimal point
    if (str.empty()) {
        return -999999.99;
    }
    //if string empty return invalid number
    int i = 0;
    if (str[i] == '-') {
        negative = true;
        i++;
        //set negative to true if there is a negative sign, same applies to positive sign below
    } else if (str[i] == '+') {
        i++;
    }
    if (i = str.length()){
        return -999999.99;
    }
    //check if there is just a plus or just a minus
    for (; i < str.length(); i++) {
        char c = str[i];
        if (c == '.') {
            if (decimal) {
                return -999999.99;
            }
            decimal = true;
            continue;
            //now iterate throughout the indexes, if encountering a decimal when a decimal already exists then make sure that it is invalid
        }
        int digit = char_digit(c);
        if (digit == -1) {
            return -999999.99;
            //if a digit is invalid, make sure to return the invalid number
        }
        if (decimal) {
            decimalDivisor *= 10.0;
            result += digit / decimalDivisor;
            //otherwise, if we are past the decimal threshold, then keep multipying the decimal devisor by 10 then add the result with the digit divided by the divisor to get that specific value in the decimal place
        } else {
            result = result * 10 + digit;
            //otherwise, simply multiply the result by 10 and add the last digit, 
        }
    }
    if (negative) {
        result = -result;
    }
    //give the result as negative if that part is true
    return result;
}

int char_digit(char c) {
    switch (c) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return -1;
    }
}
// create differenct cases for whenever the string is a specific value, utilizing the switch operator