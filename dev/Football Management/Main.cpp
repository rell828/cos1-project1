// Football Management.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits>
using namespace std;
#include <string>

int main()
{
    int choice = -1;

    do
    {
        cout << "\n===== FOOTBALL MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Player\n";
        cout << "2. View Team Roster\n";
        cout << "3. Search Player\n";
        cout << "4. Update Player\n";
        cout << "5. Remove Player\n";
        cout << "6. View Player Statistics\n";
        cout << "7. Manage Games\n";
        cout << "8. View Team Record\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            cout << "Add Player selected.\n";
            break;
        case 2:
            cout << "View Team Roster selected.\n";
            break;
        case 3:
            cout << "Search Player selected.\n";
            break;
        case 4:
            cout << "Update Player selected.\n";
            break;
        case 5:
            cout << "Remove Player selected.\n";
            break;
        case 6:
            cout << "View Player Statistics selected.\n";
            break;
        case 7:
            cout << "Manage Games selected.\n";
            break;
        case 8:
            cout << "View Team Record selected.\n";
            break;
        case 0:
            cout << "Exiting Football Management System.\n";
            break;
        default:
            cout << "Invalid menu option.\n";
        }

    } while (choice != 0);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
