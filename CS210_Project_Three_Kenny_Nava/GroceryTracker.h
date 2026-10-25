#ifndef GROCERY_TRACKER_H_
#define GROCERY_TRACKER_H_

#include <map>
#include <string>

using namespace std;

class GroceryTracker {
public:
    GroceryTracker();

    int getItemFrequency(string itemName);
    void printAllFrequencies();
    void printHistogram();

private:
    map<string, int> itemFrequency;

    void loadData();
    void createBackupFile();
};

#endif
