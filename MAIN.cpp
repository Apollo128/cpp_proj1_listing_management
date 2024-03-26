//Data functions
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "QuickSort.h"
#include "FileHandler.h"
#include "HashTable.h"
#include "UtilityFns.h"

//UI functions
#include "TenantUI.h"
//#include "LoginUI.h"
//#include "ManagerUI.h"
//#include "AdminUI.h"
using namespace std;


//void TEST_1();

int main() {
	bool programExit = false;
	int choice;
	string strInput;

	unique_ptr<FileHandler> csvFile ( new FileHandler("dataset.csv") );
	int currentPageNo = 0;

	HashTable<string, vector<string>> favorites = HashTable<string, vector<string>>(10); // userID -> { prop1, prop2 ... }
	HashTable<string, vector<string>> rentReqs = HashTable<string, vector<string>>(10); // ads_id -> { user1, user2... }
	HashTable<string, vector<string>> history = HashTable<string, vector<string>>(10); // userID -> { prop1, prop2... }

	string currentUser = "User123";
	vector<string> currentUserFavs;
	vector<string> currentUserReqs;

	while (!programExit) {
		// LOOP WHEN PROGRAM EXIT SET TO FALSE
		TenantUI::mainMenu();
		choice = getInput("Enter Option", 1);
		switch (choice)
		{
		case 1:
			//SEARCH
			strInput = getInput("Enter Search Term ");
			csvFile->search(strInput);
			break;
		case 2:
			// SORT BY RENT
			TenantUI::sortByRent();
			choice = getInput("Enter Option", 1);
			switch (choice)
			{
			case 1:
				// Sort by Rent - Asc
				quickSort(csvFile->getTable(), 0, csvFile->getSize(), "monthly_rent");
				csvFile->constructPages();
				csvFile->displayOutput("asc", currentPageNo);
				TenantUI::pageNav();
				choice = getInput("Choose Next", 1);
				switch (choice)
				{
				case 1: csvFile->displayOutput("asc", ++currentPageNo); break;
				case 2: if (currentPageNo > 0) csvFile->displayOutput("asc", --currentPageNo); break;
				case 3:
					strInput = getInput("Enter ads_id to add to Favorites ");
					if (!favorites.contains(currentUser)) {
						currentUserFavs.push_back(strInput);
						favorites.insert(currentUser, currentUserFavs);
					}
					favorites.appendVector(currentUser, strInput);
					break;

				default:break;
				}
				break;

			case 2:
				// Sort by Rent - Desc
				quickSort(csvFile->getTable(), 0, csvFile->getSize(), "monthly_rent");
				csvFile->constructPages();
				csvFile->displayOutput("desc", currentPageNo);
				TenantUI::pageNav();
				choice = getInput("Choose Next", 1);
				switch (choice)
				{
				case 1: csvFile->displayOutput("desc", ++currentPageNo); break;
				case 2: if (currentPageNo > 0) csvFile->displayOutput("asc", --currentPageNo); break;
				case 3:
					strInput = getInput("Enter ads_id to add to Favorites ");
					if (!favorites.contains(currentUser)) {
						currentUserFavs.push_back(strInput);
						favorites.insert(currentUser, currentUserFavs);
					}
					favorites.appendVector(currentUser, strInput);
					break;

				default: break;

				}
				break;

			default: break;

			}
			break;
		case 3:
			// SORT BY SIZE
			TenantUI::sortBySize();
			choice = getInput("Enter Option", 1);
			switch (choice)
			{
			case 1:
				// Sort by Size - Asc
				quickSort(csvFile->getTable(), 0, csvFile->getSize(), "size");
				csvFile->constructPages();
				csvFile->displayOutput("asc", currentPageNo);
				TenantUI::pageNav();
				choice = getInput("Choose Next", 1);
				switch (choice)
				{
				case 1: csvFile->displayOutput("asc", ++currentPageNo); break;
				case 2: if (currentPageNo > 0) csvFile->displayOutput("asc", --currentPageNo); break;
				case 3:
					strInput = getInput("Enter ads_id to add to Favorites ");
					if (!favorites.contains(currentUser)) {
						currentUserFavs.push_back(strInput);
						favorites.insert(currentUser, currentUserFavs);
					}
					favorites.appendVector(currentUser, strInput);
					break;
				default: break;
				}
				break;

			case 2:
				// Sort by Size - Desc
				quickSort(csvFile->getTable(), 0, csvFile->getSize(), "size");
				csvFile->constructPages();
				csvFile->displayOutput("desc", currentPageNo);
				TenantUI::pageNav();
				choice = getInput("Choose Next", 1);
				switch (choice)
				{
				case 1: csvFile->displayOutput("asc", ++currentPageNo); break;
				case 2: if (currentPageNo > 0) csvFile->displayOutput("desc", --currentPageNo); break;
				case 3:
					strInput = getInput("Enter ads_id to add to Favorites ");
					if (!favorites.contains(currentUser)) {
						currentUserFavs.push_back(strInput);
						favorites.insert(currentUser, currentUserFavs);
					}
					favorites.appendVector(currentUser, strInput);
					break;

				default: break;

				}
				break;
			default: break;

			}
			break;
		case 4:
			// SORT BY LOCATION 
			TenantUI::sortByLocation();
			choice = getInput("Enter Option", 1);
			switch (choice)
			{
			case 1:
				// Sort by Location - Asc
				quickSort(csvFile->getTable(), 0, csvFile->getSize(), "location");
				csvFile->constructPages();
				csvFile->displayOutput("asc", currentPageNo);
				TenantUI::pageNav();
				choice = getInput("Choose Next", 1);
				switch (choice)
				{
				case 1: csvFile->displayOutput("asc", ++currentPageNo); break;
				case 2: if (currentPageNo > 0) csvFile->displayOutput("asc", --currentPageNo); break;
				case 3:
					strInput = getInput("Enter ads_id to add to Favorites ");
					if (!favorites.contains(currentUser)) {
						currentUserFavs.push_back(strInput);
						favorites.insert(currentUser, currentUserFavs);
					}
					favorites.appendVector(currentUser, strInput);
					break;

				default: break;

				}
				break;

			case 2:
				// Sort by Size - Desc
				quickSort(csvFile->getTable(), 0, csvFile->getSize(), "location");
				csvFile->constructPages();
				csvFile->displayOutput("desc", currentPageNo);
				TenantUI::pageNav();
				choice = getInput("Choose Next", 1);
				switch (choice)
				{
				case 1: csvFile->displayOutput("asc", ++currentPageNo); break;
				case 2: if (currentPageNo > 0) csvFile->displayOutput("desc", --currentPageNo); break;
				case 3:
					strInput = getInput("Enter ads_id to add to Favorites ");
					if (!favorites.contains(currentUser)) {
						currentUserFavs.push_back(strInput);
						favorites.insert(currentUser, currentUserFavs);
					}
					favorites.appendVector(currentUser, strInput);
					break;

				default: break;

				}
				break;

			default:
				break;
			}
			break;
		case 5:
			for (auto& prop : favorites.getValue(currentUser)) {
				csvFile->search(prop);
			}
			std::cout << "[1] Place Rent Request";
			std::cout << "[2] <- Back to menu" << endl;
			strInput = getInput("Enter ads_id");
			if (!rentReqs.contains(currentUser)) {
				currentUserReqs.push_back(strInput);
				rentReqs.insert(currentUser, currentUserReqs);
			}
			rentReqs.appendVector(currentUser, strInput);
			break;
		case 6:
			for (auto& prop : rentReqs.getValue(currentUser)) {
				csvFile->search(prop);
			}
			break;
		default:
			break;

		} // SWITCH
	}// LOOP 


}

//void TEST_1() {
//	// TEST : Storing string - > vec in hashtable. 
//	//unique_ptr<FileHandler> csvFile(new FileHandler("dataset.csv"));
//	HashTable<string, vector<string>> str_vec = HashTable<string, vector<string>> (3);
//	string s1 = "s1"; string s2 = "s2";
//	vector<string> vec = { "1vs1","1vs2" };
//	vector<string> vec2 = { "2vs1","2vs2" };
//	str_vec.insert(s1, vec);
//	str_vec.insert(s2, vec2);
//
//	for (const KeyValuePair<string,vector<string>>& kvp : str_vec.elements()) {
//		cout << kvp.key;
//		for (const string& str_in_kv_vec : kvp.value) {
//			cout << "\n" << str_in_kv_vec; 
//		}
//		cout << "\n";
//	}
//	cout << endl;
//}