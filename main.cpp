#include <iostream>
#include <string>
#include <limits>
#include "Graph.h"
#include "Algorithms.h"
#include "FileHandler.h"
#include "gui.h"
using namespace std;

int main() {
    Graph       g;
    Algorithms  algo;
    FileHandler fh;

    fh.loadUsersCSV(g,       "users.csv");
    fh.loadFriendshipsCSV(g, "friendships.csv");
    // fh.saveNetwork(g, "users.csv");

    runGUI(g);

    // // Auto-load real dataset on startup
    // cout << "SOCIAL NETWORK FRIEND RECOMMENDER ";

    // cout << "Loading network data...\n";
    // fh.loadUsersCSV(g,       "users.csv");
    // fh.loadFriendshipsCSV(g, "friendships.csv");
    // cout << "\nNetwork ready!\n";
    // cout << "  Total Users      : " << g.getUserCount() << "\n";
    // cout << "  Total Friendships: " << g.getEdgeCount()  << "\n";

    // int choice;

    // do {
        
    //     cout << "        SOCIAL NETWORK MENU              \n";
       
    //     cout << "  1. Add User                             \n";
    //     cout << "  2. Add Friendship                       \n";
    //     cout << "  3. Show Network                         \n";
    //     cout << "  4. Recommend Friends                    \n";
    //     cout << "  5. BFS Traversal                        \n";
    //     cout << "  6. Exit                                 \n";
        
    //     cout << "Enter choice: ";
    //     cin  >> choice;

    //     // ── 1. ADD USER ────────────────────────────────────
    //     if (choice == 1) {
    //         User u;
    //         cin.ignore();

    //         cout << "\n--- Add New User ---\n";
    //         cout << "Enter User ID   : "; cin >> u.userID;
    //         cin.ignore();
    //         cout << "Enter Name      : "; getline(cin, u.name);
    //         cout << "Enter Gender    : "; getline(cin, u.gender);
    //         cout << "Enter DOB       : "; getline(cin, u.dob);
    //         cout << "Enter Interests : "; getline(cin, u.interests);
    //         cout << "Enter City      : "; getline(cin, u.city);
    //         cout << "Enter Country   : "; getline(cin, u.country);

    //         g.addUser(u);
    //     }

    //     // ── 2. ADD FRIENDSHIP ──────────────────────────────
    //     else if (choice == 2) {
    //         int id1, id2;
    //         cout << "\n--- Add Friendship ---\n";
    //         cout << "Enter User ID 1: "; cin >> id1;
    //         cout << "Enter User ID 2: "; cin >> id2;

    //         // Show names if found
    //         if (g.userExists(id1) && g.userExists(id2)) {
    //             cout << "Adding friendship between: "
    //                  << g.users[id1].name << " and "
    //                  << g.users[id2].name << "\n";
    //         }
    //         g.addFriend(id1, id2);
    //     }

    //     // ── 3. SHOW NETWORK ────────────────────────────────
    //     else if (choice == 3) {
    //         cout << "\n--- Show Network ---\n";
    //         cout << "Show full network? (500 users = long output)\n";
    //         cout << "  1. Show full network\n";
    //         cout << "  2. Show one user's connections\n";
    //         cout << "Choice: ";
    //         int sub; cin >> sub;

    //         if (sub == 1) {
    //             g.displayGraph();
    //         } else {
    //             int id;
    //             cout << "Enter User ID: "; cin >> id;
    //             if (!g.userExists(id)) {
    //                 cout << "User not found!\n";
    //             } else {
    //                 g.users[id].display();
    //                 vector<int> friends = g.getFriends(id);
    //                 cout << "\nFriends of " << g.users[id].name
    //                      << " (" << friends.size() << " total):\n";
    //                 if (friends.empty()) {
    //                     cout << "  (no friends yet)\n";
    //                 } else {
    //                     for (int i = 0; i < (int)friends.size(); i++) {
    //                         int fid = friends[i];
    //                         cout << "  " << i+1 << ". ["
    //                              << fid << "] "
    //                              << g.users[fid].name
    //                              << " - " << g.users[fid].city
    //                              << "\n";
    //                     }
    //                 }
    //             }
    //         }
    //     }

    //     // ── 4. RECOMMEND FRIENDS ───────────────────────────
    //     else if (choice == 4) {
    //         int id;
    //         cout << "\n--- Friend Recommendations ---\n";
    //         cout << "Enter User ID: "; cin >> id;
    //         algo.recommendFriends(g, id);
    //     }

    //     // ── 5. BFS TRAVERSAL ───────────────────────────────
    //     else if (choice == 5) {
    //         int id;
    //         cout << "\n--- BFS Traversal ---\n";
    //         cout << "Enter starting User ID: "; cin >> id;
    //         algo.BFSTraversal(g, id);
    //     }

    //     // ── 6. EXIT ────────────────────────────────────────
    //     else if (choice == 6) {
            
    //         cout << "\nGoodbye! Network saved.\n";
           
    //         cout << "        Thank you for using            \n";
    //         cout << "   Social Network Friend Recommender    \n";
           
    //     }

    //     else {
    //         cout << "Invalid choice! Please enter 1-6.\n";
    //     }

    // } while (choice != 6);

    return 0;
}
