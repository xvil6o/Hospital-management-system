#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "header.h"
using namespace std;

bool again(const string& prompt) // helper function
{
    string ans;
    cout << prompt;
    
    while (true)
    {
        getline(cin, ans);
        
        if (ans.empty())
        {
            cout << "Invalid input, try again: ";
            continue;
        }
        
        char firstChar = ans[0];

        if (firstChar == 'y' || firstChar == 'Y')
            return true;
        else if (firstChar == 'n' || firstChar == 'N')
            return false;
        else
            cout << "Invalid input, try again: ";
    }
}
void calculateTotalBill()
{
    string consultation_fees, medicine_cost;
                
    cout << "Enter consultation fees: ";
    getline(cin, consultation_fees);
    while (!ValidNumeric(consultation_fees)) // only accepts numbers
    {   
        cout << "Invalid input, try again: ";
        getline(cin, consultation_fees);
    }
                
     cout << "Enter medicines cost: ";
    getline(cin, medicine_cost);
    while (!ValidNumeric(medicine_cost)) // only accepts numbers
    {   
        cout << "Invalid input, try again: ";
        getline(cin, medicine_cost);
    }

    cout << "Total bill = " << stoi(medicine_cost) + stoi(consultation_fees) << " EGP\n";
}

int main() 
{
    cout << "--- Hospital Management System ---\n";
    cout << "0-Exit\n1-Add New Doctor\n2-Add New Patient\n3-Book Appointment\n 4-Cancel Appointment\n5-Display all appointments\n6-Search for a doctor by credentials\n7-Search for a patient by credentials\n8-Total bill\n9-Search for a doctor by specialization\n10-Patient medical report\n";

    while (true)
    {
        string input;
        cout << "\nEnter your choice: ";
        getline(cin, input);
        
        // Validate: non-empty and all digits
        if (input.empty() || !all_of(input.begin(), input.end(), ::isdigit))
        {
            cout << "Invalid input.\n";
            continue;
        }
    
        int choice = stoi(input);
    
        if (choice < 0 || choice > 10)
        {
            cout << "Invalid input.\n";
            continue;
        }
    
        switch (choice)
        {
            case 0: cout << "Exiting...\n"; return 0;
            case 1:
            {
                Doctor d1;
                break;
            }
            case 2:
            {
                Patient p1;
                break;
            }
            case 3: 
            {
                Appointment a1;
                a1.book();
                break;
            }    
            case 4: 
            {
                Appointment a1;
                a1.cancel(); 
                break;
            }
            case 5: 
            {
                Appointment a1;
                a1.display();
                break;
            }
            case 6: 
            {
                Doctor::search();
                break;
            }
            case 7: 
            {
                Patient::search();
                break;
            }
            case 8:
            {
                calculateTotalBill(); break;
            } 
            case 9: 
            {
                Doctor::search_by_specialisation();
                break;
            }
            case 10: 
            {
                Patient::medical_report();
                break;
            }    
        }

        if (!again("\nAgain? "))
        {
            break;
        }
            
    }
    
    return 0;
}    