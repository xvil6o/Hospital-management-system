#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

inline bool ValidName(const string& str)
{
    if (str.empty()) return false;
    return all_of(str.begin(), str.end(), [](char c) {
        return isalpha(static_cast<unsigned char>(c)) || c == ' ';
    });
}

inline bool ValidNumeric(const string& str)
{
    if (str.empty()) return false;
    return all_of(str.begin(), str.end(), [](char c) {
        return isdigit(static_cast<unsigned char>(c));
    });
}

inline bool ValidDate(const string& date)
{
    if (date.length() != 10) return false;
    if (date[2] != '/' || date[5] != '/') return false;

    string day = date.substr(0, 2);
    string month = date.substr(3, 2);
    string year = date.substr(6, 4);

    if (!ValidNumeric(day) || !ValidNumeric(month) || !ValidNumeric(year))
        return false;

    int d = stoi(day);
    int m = stoi(month);
    int y = stoi(year);

    if (d < 1 || d > 31 || m < 1 || m > 12 || y < 2025)
        return false;

    return true;
}

inline bool ValidTime(const string& time)
{
    if (time.length() != 5) return false;
    if (time[2] != ':') return false;

    string hour = time.substr(0, 2);
    string minute = time.substr(3, 2);

    if (!ValidNumeric(hour) || !ValidNumeric(minute))
        return false;

    int h = stoi(hour);
    int min = stoi(minute);

    if (h < 0 || h > 23 || min < 0 || min > 59)
        return false;

    return true;
}

inline string toLower(const string& str)
{
    string result = str;
    transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {
        return static_cast<char>(tolower(c));
    });
    return result;
}

inline bool containsSubstring(const string& str, const string& substr)
{
    return toLower(str).find(toLower(substr)) != string::npos;
}

class Person
{
protected:
    string name;
    string id;
    string age;
    string Phone_number;
    string filename;
    void prompt_common_fields();

public:
    Person() = default;
    static void search(const string& Filename);
    virtual ~Person() = default;
};

class Doctor : public Person
{
private:
    string specialization;
    string Available_times;

public:
    Doctor();
    static void search();
    static void search_by_specialisation();
};

class Patient : public Person
{
private:
    string medical_history;

public:
    Patient();
    static void search();
    static void medical_report();
};

class Appointment
{
private:
    string patient_id;
    string doctor_id;
    string date;
    string time;

public:
    void book();
    void cancel();
    void display();
};
