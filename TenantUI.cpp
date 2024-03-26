#include <string>
#include <vector>
using namespace std;

#include "TenantUI.h"
#include "UtilityFns.h"
namespace TenantUI {
    void mainMenu() {

        const vector<string> uiStrings = {
            "\n\tWelcome to RSystem",
            "######### MAIN MENU ##########",
            "[1] Search listing by Property Name",
            "[2] View Properties by Rent",
            "[3] View Properties by Size",
            "[4] View Properties by Location in Alphabetic Order",
            "[5] View Favorites and Place Rent Request",
            "[6] View History",
            "[7] <- Log Out"
        };
        uiPrint(uiStrings);
    }
    void sortByRent() {

        vector <string> uiStrings = {
                    "[1] Sort by Monthly Rent - Low to High",
                    "[2] Sort by Monthly Rent - High to Low",
                    "[3] <- Back to Main Menu"
        };

        uiPrint(uiStrings);
    }
    void sortBySize() {

        vector <string> uiStrings = {
                    "[1] Sort by Floor Area - Low to High",
                    "[2] Sort by Floor Area - High to Low",
                    "[3] <- Back to Main Menu"
        };
        uiPrint(uiStrings);
    }
    void sortByLocation() {

        vector <string> uiStrings = {
                    "[1] Sort by Location - A to Z",
                    "[2] Sort by Location - Z to A ",
                    "[3] <- Back to Main Menu"
        };
        uiPrint(uiStrings);
    }
    void pageNav() {

        vector <string> uiStrings = {
            "[1] Next Page",
            "[2] Previous Page",
            "[3] Add a listing to favorites...",
            "[4] Main Menu"
        };
        uiPrint(uiStrings);
    }
    void placeReq() {

        vector <string> uiStrings = {
            "[1] Place rent request...",
            "[2] <- Back to Main Menu"
        };
        uiPrint(uiStrings);
    }
}