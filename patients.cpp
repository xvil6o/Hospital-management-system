#include "header.h"

Patient::Patient()
{
    filename = "patient.txt";
    prompt_common_fields();

    cout << "medical_history: " << endl;
    getline(cin, medical_history);
    while (medical_history.empty())
    {
        cout << "Invalid input, try again: ";
        getline(cin, medical_history);
    }

    ofstream file(filename, ios::app);
    file << name << ',' << id << ',' << age << ',' << Phone_number << ','
         << medical_history << '\n';
    file.close();

    cout << "patient added successfully!\n";
}

void Patient::search()
{
    Person::search("patient.txt");
}

void Patient::medical_report()
{
    cout << "Please enter the patient's name: ";
    string query;
    getline(cin, query);

    ifstream read("patient.txt");
    if (!read.is_open())
    {
        cerr << "Could not open  patient.txt" << endl;
        return;
    }

    bool found = false;
    string line;

    while (getline(read, line))
    {
        if (line.empty()) continue;

        stringstream ss(line);
        string rec_name, rec_id, rec_age, rec_phone, rec_history;
        getline(ss, rec_name, ',');
        getline(ss, rec_id, ',');
        getline(ss, rec_age, ',');
        getline(ss, rec_phone, ',');
        getline(ss, rec_history);

        if (toLower(rec_name) == toLower(query) || containsSubstring(rec_name, query))
        {
            cout << rec_name << " : " << rec_history << ".\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Could not find the patient \n";
}
