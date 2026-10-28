#include "header.h"

void Person::prompt_common_fields()
{
    cout << "Name: " << endl;
    getline(cin, name);
    while (!ValidName(name))
    {
        cout << "Invalid input, try again: ";
        getline(cin, name);
    }

    cout << "ID: " << endl;
    getline(cin, id);
    while (!ValidNumeric(id))
    {
        cout << "Invalid input, try again: ";
        getline(cin, id);
    }

    cout << "Age: " << endl;
    getline(cin, age);
    while (!ValidNumeric(age) || stoi(age) <= 0 || stoi(age) > 150)
    {
        cout << "Invalid input, try again: ";
        getline(cin, age);
    }

    cout << "Phone number: " << endl;
    getline(cin, Phone_number);
    while (!ValidNumeric(Phone_number) || Phone_number.length() != 11)
    {
        cout << "Invalid input, try again: ";
        getline(cin, Phone_number);
    }
}

void Person::search(const string& Filename)
{
    cout << "Enter the name or ID: ";
    string credential;
    getline(cin, credential);

    ifstream file(Filename);
    if (!file.is_open())
    {
        cout << "file doesnt exist" << endl;
        return;
    }

    string line;
    bool found = false;
    string needle = toLower(credential);

    while (getline(file, line))
    {
        if (line.empty()) continue;

        stringstream ss(line);
        string record_name, record_id;
        getline(ss, record_name, ',');
        getline(ss, record_id, ',');

        if (toLower(record_name) == needle || record_id == credential ||
            containsSubstring(record_name, credential) || containsSubstring(record_id, credential))
        {
            cout << " Found! " << record_name << " (ID: " << record_id << ")" << endl;
            found = true;
        }
    }

    if (!found)
        cout << " No match " << endl;
}
