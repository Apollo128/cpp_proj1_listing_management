#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

#include "HashTable.h"
#include "UtilityFns.h"



    class FileHandler {
    public:
        std::vector<std::string> header;
        int fieldCount;
        std::vector< std::vector<std::string> > csvStrings;
        std::vector< HashTable<std::string, std::string> > csvTable;
        std::vector< std::vector<HashTable<std::string, std::string>>> pages;
        bool headerPresent;
        
        
        FileHandler(std::string filepath);

        void constructPages();

        void search(std::string searchTerm);

        void deleteRow(std::string ads_id);

        std::string formatOutput(HashTable<std::string, std::string>& row);

        void displayOutput(std::string mode, int pageNo);

        std::vector<HashTable<std::string, std::string>>& getTable();

        int getSize();
    };


