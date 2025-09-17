#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
using namespace std;

void create_note()
{
    cout << "Enter title of note\n";
    string title; cin >> title;
    filesystem::path NotePath = filesystem::current_path() / "Notes" / title / ".txt";
    if(filesystem::exists(NotePath) && filesystem::is_regular_file(NotePath))
    {
        cout << "This note already exists\n";
    }
    else
    {
        ofstream outputFile(NotePath, ios::app);
        if(outputFile.is_open())
        {
            cout << "Write something in the note. Press Ctrl+Z (Windows) or Ctrl+D (Linux/macOS) followed by Enter to stop.\n";
            string line;
            while (getline(cin, line)) {
            outputFile << line << endl;
        }
            outputFile.close();
        }
        else
        {
            cerr << "Could not create note\n";
        }
    }
}