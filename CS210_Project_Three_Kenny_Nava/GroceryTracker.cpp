#include "GroceryTracker.h"
#include <iostream>
#include <fstream>

using namespace std;

// Constructor loads the grocery data when the object is created
GroceryTracker::GroceryTracker() {
    loadData();
    createBackupFile();
}

// Read the input file and count how many times each item appears
void GroceryTracker::loadData() {
    ifstream inputFile;
    string itemName;

    inputFile.open("CS210_Project_Three_Input_File.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening input file." << endl;
        return;
    }

    while (inputFile >> itemName) {
        itemFrequency[itemName]++;
    }

    inputFile.close();
}

// Return how many times a specific grocery item was purchased
int GroceryTracker::getItemFrequency(string itemName) {
    if (itemFrequency.count(itemName) > 0) {
        return itemFrequency[itemName];
    }

    return 0;
}

// Print each grocery item and the number of times it was purchased
void GroceryTracker::printAllFrequencies() {
    for (const auto& item : itemFrequency) {
        cout << item.first << " " << item.second << endl;
    }
}

// Print each grocery item as a histogram using asterisks
void GroceryTracker::printHistogram() {
    for (const auto& item : itemFrequency) {
        cout << item.first << " ";

        for (int i = 0; i < item.second; ++i) {
            cout << "*";
        }

        cout << endl;
    }
}

// Create a backup file with each item and its frequency
void GroceryTracker::createBackupFile() {
    ofstream outputFile;

    outputFile.open("frequency.dat");

    if (!outputFile.is_open()) {
        cout << "Error creating backup file." << endl;
        return;
    }

    for (const auto& item : itemFrequency) {
        outputFile << item.first << " " << item.second << endl;
    }

    outputFile.close();
}