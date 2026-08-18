#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Helper: remove surrounding quotes from a CSV field
string stripQuotes(string s) {
    if (s.size() >= 2 && s.front() == '"' && s.back() == '"')
        return s.substr(1, s.size() - 2);
    return s;
}

// Helper: parse one CSV line respecting quoted fields
// e.g.  1,"Ali Khan",Male,1999-01-15,"Cricket, Music",Lahore,Pakistan
vector<string> parseCSVLine(const string& line) {
    vector<string> fields;
    string field;
    bool inQuotes = false;

    for (int i = 0; i < (int)line.size(); i++) {
        char c = line[i];
        if (c == '"') {
            inQuotes = !inQuotes;
        } else if (c == ',' && !inQuotes) {
            fields.push_back(field);
            field.clear();
        } else {
            field += c;
        }
    }
    fields.push_back(field); // last field
    return fields;
}

// ─────────────────────────────────────────────────────────────
// Load users from CSV
// Format: UserID,Name,Gender,DOB,Interests,City,Country
// ─────────────────────────────────────────────────────────────
void FileHandler::loadUsersCSV(Graph& g, string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "ERROR: Cannot open " << filename << "!\n";
        cout << "Make sure users.csv is in the same folder"
             << " as your .vcxproj file.\n";
        return;
    }

    string line;
    getline(file, line); // skip header row

    int count = 0;
    while (getline(file, line)) {
        if (line.empty()) continue;

        vector<string> f = parseCSVLine(line);
        if (f.size() < 7) continue;

        User u;
        u.userID    = stoi(f[0]);
        u.name      = f[1];
        u.gender    = f[2];
        u.dob       = f[3];
        u.interests = f[4];
        u.city      = f[5];
        u.country   = f[6];

        // silent add (no cout per user during bulk load)
        if (!g.users.count(u.userID)) {
            g.users[u.userID] = u;
            g.adj[u.userID]   = {};
            count++;
        }
    }

    file.close();
    cout << count << " users loaded from " << filename << "!\n";
}

// ─────────────────────────────────────────────────────────────
// Load friendships from CSV
// Format: UserID1,UserID2
// ─────────────────────────────────────────────────────────────
void FileHandler::loadFriendshipsCSV(Graph& g, string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "ERROR: Cannot open " << filename << "!\n";
        cout << "Make sure friendships.csv is in the same"
             << " folder as your .vcxproj file.\n";
        return;
    }

    string line;
    getline(file, line); // skip header

    int count = 0;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string a, b;
        getline(ss, a, ',');
        getline(ss, b, ',');

        if (a.empty() || b.empty()) continue;

        int uid1 = stoi(a);
        int uid2 = stoi(b);

        if (g.userExists(uid1) && g.userExists(uid2)) {
            g.adj[uid1].push_back(uid2);
            g.adj[uid2].push_back(uid1);
            count++;
        }
    }

    file.close();
    cout << count << " friendships loaded from "
         << filename << "!\n";
}

// ─────────────────────────────────────────────────────────────
// Save current network back to file
// ─────────────────────────────────────────────────────────────
void FileHandler::saveNetwork(Graph& g, string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "ERROR: Cannot save to " << filename << "!\n";
        return;
    }

    file << "UserID,Name,Gender,DOB,Interests,City,Country\n";
    for (auto& e : g.users) {
        User& u = e.second;
        file << u.userID    << ","
             << "\"" << u.name      << "\","
             << u.gender    << ","
             << u.dob       << ","
             << "\"" << u.interests << "\","
             << u.city      << ","
             << u.country   << "\n";
    }
    file.close();
    cout << "Network saved to " << filename << "!\n";
}
