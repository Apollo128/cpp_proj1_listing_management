#pragma once
#include <vector>
#include <string>

#include "HashTable.h"
using namespace std;

// Partition function to split array and swap elements in quick-sort process
int partition(vector<HashTable<string, string>>& data, int low, int high, string field);


// Quick-sort algorithm which takes in the data structure containing all rows.
void quickSort(vector<HashTable<string, string>>& data, int low, int high, string field);
