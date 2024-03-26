#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

#include "FileHandler.h"
#include "HashTable.h"
#include "UtilityFns.h"



//CONSTRUCTOR 

FileHandler::FileHandler(std::string filepath) {
    ifstream inputFile(filepath);
    if (!inputFile) {
        cerr << "Error opening file: " << filepath << endl;
    }
    string line;
    while (getline(inputFile, line)) {
        vector<string>    rowData;
        stringstream      ss(line);
        string            item;
        while (getline(ss, item, ',')) {
            if (!item.empty() && item.front() == '"' && item.back() != '"') {
                string temp;
                while (getline(ss, temp, ',')) {
                    item += "," + temp;
                    if (temp.back() == '"') break;
                }
            }
            // Remove quotes 
            if (!item.empty() && item.front() == '"' && item.back() == '"')
                item = item.substr(1, item.size() - 2);

            rowData.push_back(item);
        }
        // Add the current row data to the FileHandler::csvStrings vector
        FileHandler::csvStrings.push_back(rowData);
    }
    inputFile.close();
    header = FileHandler::FileHandler::csvStrings[0];
    fieldCount = header.size();

    //Construct hashtable { columnname -> value } and append to FileHandler::csvTable.
    HashTable<string, string> temp = HashTable<string, string>(fieldCount);
    for (int row = 0; row < FileHandler::csvStrings.size(); row++) {
        for (int col = 0; col < header.size(); col++) {
            if (FileHandler::csvStrings[row][col] != "") {
                temp.insert(header[col], FileHandler::csvStrings[row][col]);
            }
        }
        FileHandler::csvTable.push_back(temp);
    }
    constructPages();
    headerPresent = true;
}

// Organise data into pages
void FileHandler::constructPages() {
    pages.clear();
    int itemsPerPage = 10;
    int i = 1;
    vector <HashTable<string, string>> page;
    for (auto& row : FileHandler::csvTable) {
        if (i == itemsPerPage) {
            i = 1;
            pages.push_back(page);
            page.clear();
            continue;
        }
        page.push_back(row);
        i++;
    }
}

void FileHandler::search(string searchTerm) {
    for (auto& row : FileHandler::csvTable) {
        for (auto& elems : row.elements()) {
            if (elems.value == searchTerm) {
                cout << formatOutput(row);
            }
        }
    }
    cout << "not found. " << endl;
}

void FileHandler::deleteRow(string ads_id) {
    for (int row = 0; row < FileHandler::csvTable.size(); row++) {
        if (FileHandler::csvTable[row].getValue("ads_id") == ads_id) {
            FileHandler::csvTable.erase(FileHandler::csvTable.begin() + row);
        }
    }
}

// Output contents of the hashtable (row) in a formatted way.
string FileHandler::formatOutput(HashTable<string, string>& row) {
    string formatOutput;
    for (const auto& kvPair : row.elements()) {
        formatOutput += kvPair.key + "\t--->\t" + kvPair.value + "\n";
    }
    return formatOutput;
}

// Displays output in either ascending/ descedning order, for a given page num.
void FileHandler::displayOutput(string mode, int pageNo) {
    if (mode == "desc") std::reverse(pages.begin(), pages.end());
    vector< HashTable<string, string> > currentPage = FileHandler::pages[pageNo];
    for (auto& row : currentPage) {
        std::cout << formatOutput(row) << "\n";
    }
}

vector<HashTable<string, string>>& FileHandler::getTable() { 
    if (headerPresent) {
        FileHandler::csvTable.erase(FileHandler::csvTable.begin());
        headerPresent = false;
        return FileHandler::csvTable;
    }
    return FileHandler::csvTable;
}

int FileHandler::getSize() { return FileHandler::csvTable.size() - 2; }


