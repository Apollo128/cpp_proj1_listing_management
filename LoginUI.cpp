#include <string>
#include <vector>
using namespace std;
#include "UtilityFns.h"

namespace LoginUI {
    void entryPage () {
        const vector<string> uiStrings = {
            "\n\tWelcome to RSystem",
            "######### LOGIN MENU ##########",
            "[1] Login \t(for Tenant, Manager, Admin)",
            "[2] Register \t(for Tenant)",
            "[3] <- Exit Application"
        };
        uiPrint(uiStrings);
    }
    void successful() {
        const vector<string> uiStrings = {
            "Login Succesful..."
        };
        uiPrint(uiStrings);
    }
    void failed() {
        const vector<string> uiStrings = {
            "Login Succesful..."
        };
        uiPrint(uiStrings);
    }
}