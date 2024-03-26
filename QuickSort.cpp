#include <vector>
#include <string>

#include "HashTable.h"
#include "UtilityFns.h"
using namespace std;


// Partition function to split array and swap elements in quick-sort process
int partition(vector<HashTable<string, string>>& data, int low, int high, string field) {
    //handle numeric data separately from alphabetic data.
    string highval = data[high].getValue(field);

    if (field == "monthly_rent" || field == "size") {
        int pivot = extractDigits(highval);
        int i = low - 1;
        for (int j = low; j <= high; j++) {
            string temp = data[j].getValue(field);
            //TEST
            /* if ( j > 10254  && j < 10264) {
                std::cout<< temp << endl;
                std::cout << extractDigits(temp) << endl;
            }
             */if (extractDigits(temp) < pivot) {
                 i++;
                 swap(data[i], data[j]);
             }
        }
        swap(data[i + 1], data[high]);
        return i + 1;
    }
    string pivot = highval;
    int i = low - 1;
    for (int j = low; j <= high; j++) {
        if (data[j].getValue(field) < pivot) {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[high]);
    return i + 1;
}

// Quick-sort algorithm which takes in the data structure containing all rows.
void quickSort(vector<HashTable<string, string>>& data, int low, int high, string field) {
    if (low < high) {
        int pivotIndex = partition(data, low, high, field);
        // Recursively sort the sub-array
        quickSort(data, low, pivotIndex - 1, field);
        quickSort(data, pivotIndex + 1, high, field);
    }
}
