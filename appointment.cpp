#include "header.h"
#include <cstdio>

void Appointment::book()
{
    cout << "Doctor ID: ";
    getline(cin, doctor_id);
    while (!ValidNumeric(doctor_id))
    {
        cout << "Invalid input, try again: ";
        getline(cin, doctor_id);
    }

    cout << "Patient ID: ";
    getline(cin, patient_id);
    while (!ValidNumeric(patient_id))
    {
        cout << "Invalid input, try again: ";
        getline(cin, patient_id);
    }

    cout << "Date (DD/MM/YYYY): ";
    getline(cin, date);
    while (!ValidDate(date))
    {
        cout << "Invalid date, try again: ";
        getline(cin, date);
    }

    cout << "Time (HH:MM): ";
    getline(cin, time);
    while (!ValidTime(time))
    {
        cout << "Invalid time, try again: ";
        getline(cin, time);
    }

    ofstream file("appointments.txt", ios::app);
    file << doctor_id << ',' << patient_id << ',' << date << ',' << time << '\n';
    file.close();

    cout << "Appointment booked successfully!\n";
}

void Appointment::cancel()
{
    cout << "Enter the keyword: ";
    string value;
    getline(cin, value);

    if (value.empty())
    {
        cout << "Appointment not found" << endl;
        return;
    }

    ifstream file("appointments.txt");
    if (!file.is_open())
    {
        cerr << "Error: Could not open file.\n";
        return;
    }

    ofstream temporary("temporary.txt");
    if (!temporary.is_open())
    {
        cerr << "Error: Could not open file.\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line))
    {
        if (line.empty()) continue;
        if (line.find(value) != string::npos)
        {
            found = true;
            continue;
        }
        temporary << line << '\n';
    }

    file.close();
    temporary.close();

    remove("appointments.txt");
    rename("temporary.txt", "appointments.txt");

    if (found)
        cout << "Appointment deleted successfully" << endl;
    else
        cout << "Appointment not found" << endl;
}

void Appointment::display()
{
    cout << "Enter date (DD/MM/YYYY): ";
    string Date;
    getline(cin, Date);

    ifstream file("appointments.txt");
    if (!file.is_open())
    {
        cout << " No match " << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line))
    {
        if (line.empty()) continue;

        stringstream ss(line);
        string rec_doctor_id, rec_patient_id, rec_date, rec_time;

        getline(ss, rec_doctor_id, ',');
        getline(ss, rec_patient_id, ',');
        getline(ss, rec_date, ',');
        getline(ss, rec_time);

        if (rec_date == Date)
        {
            cout << "Doctor ID:  " << rec_doctor_id << endl;
            cout << "Patient ID: " << rec_patient_id << endl;
            cout << "Date: " << rec_date << endl;
            cout << "Time: " << rec_time << endl;
            found = true;
        }
    }

    if (!found)
        cout << " No match " << endl;
}
