#include "Graph.h"
#include <algorithm>

// Add a new user (graph node)
string Graph::addUser(User u) {
    if (users.count(u.userID)) {
        return "User already exists!";
    }
    users[u.userID] = u;
    adj[u.userID]   = {};
    return "User " + u.name + " added successfully!";
}

// Add friendship (graph edge) between two users
string Graph::addFriend(int uid1, int uid2) {
    if (!userExists(uid1)) {
        return "User ID " + to_string(uid1) + " not found!";
        
    }
    if (!userExists(uid2)) {
        return "User ID " +to_string(uid2) +" not found!";
        
    }
    if (uid1 == uid2) {
        return "A user cannot be friends with themselves!";
    }

    // Check if already friends
    for (int f : adj[uid1]) {
        if (f == uid2) {
            return users[uid1].name + " and " +  users[uid2].name + " are already friends!";
        }
    }

    adj[uid1].push_back(uid2);
    adj[uid2].push_back(uid1);
    return  users[uid1].name + " and " + users[uid2].name + " are now friends!";
}

// Build and return network as one big string
string Graph::displayGraph() {
    string result = "";
    if (adj.empty()) {
        return "Network is empty!";
    }

    result += "SOCIAL NETWORK\n\n";
    result += "Total Users: " + to_string(getUserCount());
    result += " | Total Friendships: " + to_string(getEdgeCount());
    result += "\n";
    result += "----------------------------------------\n\n";

    for (auto& entry : adj) {
        int uid = entry.first;

        // Line 1: user info
        result += "[" + to_string(uid) + "] ";
        result += users[uid].name;
        result += " (" + users[uid].city + ")";
        result += "    --> \n";

        // Line 2: friends list indented
        if (entry.second.empty()) {
            result += "(no friends yet)";
        } else {
            for (int i = 0; i < (int)entry.second.size(); i++) {
                int fid = entry.second[i];
                result += users[fid].name;
                if (i < (int)entry.second.size() - 1)
                    result += ", ";
            }
        }
        result += "\n\n";
    }
    return result;
}

// Check if user exists
bool Graph::userExists(int uid) {
    return users.count(uid) > 0;
}

// Total number of users
int Graph::getUserCount() {
    return users.size();
}

// Total number of friendships
int Graph::getEdgeCount() {
    int total = 0;
    for (auto& e : adj) total += e.second.size();
    return total / 2;
}

// Get friend list of a user
vector<int> Graph::getFriends(int uid) {
    if (!userExists(uid)) return {};
    return adj[uid];
}
