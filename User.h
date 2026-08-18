#pragma once
#include <iostream>
#include <string>
using namespace std;

struct User {
    int    userID;
    string name;
    string gender;
    string dob;
    string interests;
    string city;
    string country;

    void display() const {
        cout << "\n+----------------------------------+\n";
        cout << "  ID       : " << userID << "\n";
        cout << "  Name     : " << name << "\n";
        cout << "  Gender   : " << gender << "\n";
        cout << "  DOB      : " << dob << "\n";
        cout << "  Interests: " << interests << "\n";
        cout << "  Location : " << city << ", " << country << "\n";
        cout << "+----------------------------------+\n";
    }
};
