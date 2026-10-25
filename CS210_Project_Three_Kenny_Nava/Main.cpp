#include <iostream>
#include <string>
#include "GroceryTracker.h"
#include <cctype>

using namespace std;

int main() {
    GroceryTracker groceryTracker;
    int menuChoice = 0;
    string itemName;

    // Continue displaying the menu until the user chooses to exit
    do {
        cout << endl;
        cout << "Corner Grocer" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Display all item frequencies" << endl;
        cout << "3. Display histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> menuChoice;


        // Clear invalid input if the user enters something other than a number
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number from 1 to 4." << endl;
            menuChoice = 0;
            continue;
        }

        cout << endl;

        if (menuChoice == 1) {
            cout << "Enter an item to search for: ";
            cin >> itemName;

            // Format the item name to match the capitalization in the input file
            for (int i = 0; i < itemName.length(); ++i) {
                itemName[i] = tolower(itemName[i]);
            }

            itemName[0] = toupper(itemName[0]);

            cout << itemName << " was purchased "
                << groceryTracker.getItemFrequency(itemName)
                << " time(s)." << endl;
        }
        else if (menuChoice == 2) {
            groceryTracker.printAllFrequencies();
        }
        else if (menuChoice == 3) {
            groceryTracker.printHistogram();
        }
        else if (menuChoice == 4) {
            cout << "Exiting program." << endl;
        }
        else {
            cout << "Invalid menu choice. Please enter 1 through 4." << endl;
        }

    } while (menuChoice != 4);

    return 0;
}