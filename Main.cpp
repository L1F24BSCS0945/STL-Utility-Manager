#include "stlmanager.h"
#include <iostream>
using namespace std;

// ============================================================
//  STL UTILITY MANAGER - MAIN
// ============================================================

void showWelcomeBanner() {
    printLine('*');
    printCenter("STL UTILITY MANAGER", 70);
    printCenter("STL concepts | Algorithms | Iterators", 70);
    printLine('*');
    cout << "\n";
}

void showMainMenu() {
    printLine('=');
    printCenter("MAIN MENU");
    printLine('=');
    cout << "  1. Vector Operations\n";
    cout << "  2. List Operations\n";
    cout << "  3. Stack Operations\n";
    cout << "  4. Queue Operations\n";
    cout << "  5. Map Operations\n";
    cout << "  6. Set Operations\n";
    cout << "  7. Sort Vector\n";
    cout << "  8. Search Vector\n";
    cout << "  9. Frequency Counter\n";
    cout << "  0. Exit\n";
    printLine('=');
    cout << "  Choice: ";
}

int main() {
    showWelcomeBanner();
    STLManager manager;

    while (true) {
        showMainMenu();
        long long choice = readIntValidated("", 0, 9);

        if (choice == 1) manager.vectorOperations();
        else if (choice == 2) manager.listOperations();
        else if (choice == 3) manager.stackOperations();
        else if (choice == 4) manager.queueOperations();
        else if (choice == 5) manager.mapOperations();
        else if (choice == 6) manager.setOperations();
        else if (choice == 7) { manager.sortVector(); pauseForUser(); }
        else if (choice == 8) { manager.searchVector(); pauseForUser(); }
        else if (choice == 9) { manager.frequencyCounter(); pauseForUser(); }
        else if (choice == 0) break;
    }

    printLine('=');
    cout << "  Thank you for using the STL Utility Manager!\n";
    printLine('=');
    return 0;
}