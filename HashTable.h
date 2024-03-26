2#pragma once

#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;
template <typename K, typename V>
class KeyValuePair {
public:
    K key;
    V value;
    KeyValuePair(const K& key, const V& value)
        : key(key), value(value)
    {
    }
};
/*enum keyTypes {type_int, type_str};
enum valueTypes {type_vector,type_str,type_int}; */

template <typename KeyType, typename ValueType>
class HashTable {
public:

    size_t tableSize = 0;
    vector < vector < KeyValuePair<KeyType, ValueType>>> tableVec;
    set<int> activeIndex;

    int hashFunction(const KeyType& key) {
        return hashGeneric(key);
    }

    // Specialization for int
    int hashGeneric(const int& key) {
        return static_cast<unsigned int>(key) % tableSize;
    }

    // Specialization for std::string
    int hashGeneric(const std::string& key) {
        int hash = 5381;
        for (char c : key) {
            hash = ((hash << 5) + hash) + c;
        }
        return hash % tableSize;
    }


    explicit HashTable(int size) : tableSize(size), tableVec(size) {}

    void insert(const KeyType& key, const ValueType& value) {
        int index = hashFunction(key);
        for (auto& pair : tableVec[index]) {
            if (pair.key == key) {
                // TEST std::cout << "Key already exists. Updating value." << std::endl;
                pair.value = value;
                return;
            }
        }
        tableVec[index].push_back({ key, value });
        activeIndex.insert(index);
    }
    ValueType getValue(const KeyType& key) {
        int index = hashFunction(key);
        ValueType value;
        for (const auto& pair : tableVec[index]) {
            if (pair.key == key) {
                value = pair.value;
                return value;
            }
        }
        return ValueType();
    }
    void remove(const KeyType& key) {
        int index = hashFunction(key);
        tableVec[index].remove_if([key](const KeyValuePair<KeyType, ValueType>& pair) {
            return pair.key == key;
            });
    }
    bool contains(const KeyType& key) {
        int index = hashFunction(key);
        for (const auto& pair : tableVec[index]) {
            if (pair.key == key) {
                return true;
            }
        }
        return false;
    }
    vector<KeyValuePair<KeyType, ValueType>> elements() {
        vector<KeyValuePair<KeyType, ValueType>> row;
        for (const auto& index : activeIndex) {
            for (const auto& elem : tableVec[index]) {
                row.push_back(elem);
            }
        }
        return row;
    }
    void appendVector(KeyType& key, string& newval) {
            int index = hashFunction(key);  
            ValueType temp = getValue(key);
            temp.push_back(newval);
            insert(key, temp);
    }


    HashTable() = default;

};

