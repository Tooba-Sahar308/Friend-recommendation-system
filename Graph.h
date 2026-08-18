#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "User.h"
using namespace std;

class Graph {
public:
    map<int, vector<int>> adj;   // adjacency list: ID -> list of friend IDs
    map<int, User>        users; // ID -> full user data

    string  addUser(User u);
    string    addFriend(int uid1, int uid2);
    string    displayGraph();
    bool    userExists(int uid);
    int     getUserCount();
    int     getEdgeCount();
    vector<int> getFriends(int uid);
};
