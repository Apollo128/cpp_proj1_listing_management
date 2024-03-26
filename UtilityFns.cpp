#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <random>
#include <limits>
#include <stdexcept>
#include "UtilityFns.h"

using namespace std;
// Utility function - Split a string according to delimiter.
vector<std::string> splitString(const string& input, char delimiter) {
    vector<string>  result = {} ;
    stringstream    ss(input);
    string          item;

    while (getline(ss, item, delimiter)) { result.push_back(item); }
    return result;
}

//Takes a string and returns the number value, ignoring any letters.
int extractDigits(const string& input) {
    string digits;
    for (char ch : input) {
        if (isdigit(ch)) {
            digits += ch;
        }
    }
    return stoi(digits);
}

// Utility function to print a vector of strings in a formatted way for UI and get next option.
void uiPrint(vector <string> uiStrings) {
    for (const auto& text :  uiStrings) { std::cout << text << "\n"; }
    cout << endl;
}


string getInput(string msg) {
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string input;
    cout << msg << " >>> ";

    getline(cin, input);
    return input;
}

int getInput(string msg, bool asInt) {
    string inputStr = getInput(msg);
        return stoi(inputStr);
}



int randomInt() {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dist(0, 60);
    return dist(gen);

}

//Pass in a string to display then an option from ( type_str OR type_int ). Returns user input.
//template<typename returnType>
//returnType getInput(string msg, inputType type) {
//    string input;
//
//    cout << msg << " >>> ";
//    cin.clear();
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//    getline(cin, input);
//
//    switch (type) {
//    case type_str:
//        return input;
//    case type_int: {
//        try {
//            return stoi(input);
//        }
//        catch (const std::exception& e) {
//            throw runtime_error("Invalid integer input");
//        }
//    }
//    default:
//        throw runtime_error("Invalid input type");
//    }
//}
////template<typename returnType>
////returnType getInput(string msg, inputType type) {
////
////    string retStr;
////    int retInt;
////
////    cout << "\n" << msg << " >>> ";  // Added a colon after the input message
////    cin.clear();
////    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
////
////    switch (type)
////    {
////    case type_str:
////        cin >> retStr;
////        return retStr;
////    case type_int:
////        cin >> retInt;
////        return retInt;
////    default:
////        throw runtime_error("Invalid input type");
////    }
////}