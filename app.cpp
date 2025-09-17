#include <iostream>
#include <filesystem>
#include <string>
#include "create.cpp"
#include "read.cpp"
#include "update.cpp"
#include "delete.cpp"
namespace fs = filesystem;
using namespace std;

int main()
{
    //Check if the note folder exists and create it if necessary
    string folderName = "Notes";
    fs::path currentPath = fs::current_path();
    fs::path folderPath = currentPath / folderName;
    if (fs::exists(folderPath) == false || fs::is_directory(folderPath) == false)
    {
        if (fs::create_directory(folderPath))
        {}
        else
        {
        cerr << "Failed to create notes directory." << endl; return 1; 
        }
    }

    cout << "Welcome to the Note App\n";
    int input = 0;
    
    while(1)
    {
        cout << "What would you like to do? Enter a number between 1 to 5\n";
        cout << "1. Create new note\n";
        cout << "2. Read note\n";
        cout << "3. Edit note\n";
        cout << "4. Delete note\n";
        cout << "5. Exit the application\n";

        cin >> input;
        switch (input)
        {
        case 1:
        {
            create_note();
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        case 5:
        {
            cout << "Exiting the application\n"; return 0;
        }
        default:
            cout << "Enter a number between 1 to 4\n";
        }
    }

    return 0;
}