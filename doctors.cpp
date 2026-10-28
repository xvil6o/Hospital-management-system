#include "header.h"

Doctor::Doctor()
{
    filename = "doctors.txt";
    prompt_common_fields();

    cout << "Specialization: " << endl;
    getline(cin, specialization);
    while (specialization.empty())
    {
        cout << "Invalid input, try again: ";
        getline(cin, specialization);
    }

    cout << "Available times: " << endl;
    getline(cin, Available_times);
    while (Available_times.empty())
    {
        cout << "Invalid input, try again: ";
        getline(cin, Available_times);
    }

    ofstream file(filename, ios::app);
    file << name << ',' << id << ',' << age << ',' << Phone_number << ','
         << specialization << ',' << Available_times << '\n';
    file.close();

    cout << "Doctor added successfully!\n";
}

void Doctor::search()
{
    Person::search("doctors.txt");
}

void Doctor::search_by_specialisation()
{
    cout << "Enter doctor specialization : ";
    string specialisation;
    getline(cin, specialisation);

    ifstream read("doctors.txt");
    if (!read.is_open())
    {
        cerr << "Could not open  doctors.txt" << endl;
        return;
    }

    bool found = false;
    int count = 0;
    string line;

    while (getline(read, line))
    {
        if (line.empty()) continue;

        stringstream ss(line);
        string rec_name, rec_id, rec_age, rec_phone, rec_specialization, rec_times;
        getline(ss, rec_name, ',');
        getline(ss, rec_id, ',');
        getline(ss, rec_age, ',');
        getline(ss, rec_phone, ',');
        getline(ss, rec_specialization, ',');
        getline(ss, rec_times);

        if (toLower(rec_specialization) == toLower(specialisation))
        {
            count++;
            cout << count << '-' << rec_name << "\n";
            found = true;
        }
    }

    if (!found)
        cout << "No doctors found for that specialization.\n";
}
