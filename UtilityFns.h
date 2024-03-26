#pragma once

#include <string>
#include <vector>
#include <iostream>



std::vector<std::string> splitString(const std::string& input, char delimiter);

int extractDigits(const std::string& input);

// Utility function to print a vector of strings in a formatted way for UI and get next option.
void uiPrint(std::vector <std::string> uiStrings);

enum inputType { type_str, type_int };



std::string getInput(std::string msg);

int getInput(std::string msg, bool asInt);

int randomInt();

