#include "Algorithms.h"
#include <iostream>
#include <algorithm>

// ─────────────────────────────────────────────────────────────
// RECOMMEND FRIENDS
// Uses BFS to traverse depth-2 nodes (friends of friends)
// Scores each candidate by:
//   +3 per mutual friend
//   +2 if same city
//   +1 if same country
//   +2 per shared interest
// Uses STL: queue, set, map, priority_queue
// Time Complexity : O(V + E)
// Space Complexity: O(V)
// ─────────────────────────────────────────────────────────────
string Algorithms::recommendFriends(Graph& g, int uid) {
   if (!g.userExists(uid)) {
       return "User not found!\n";

   }
   string result = "";   //for storing all output in a single variable;

   User& me = g.users[uid];

   // STL set: store direct friends for quick lookup
   set<int> myFriends(g.adj[uid].begin(), g.adj[uid].end());

   // STL map: candidate -> score
   map<int, int> score;

   // Parse my interests into a set
   set<string> myInterests;
   stringstream ss(me.interests);
   string token;
   while (getline(ss, token, ',')) {
       // trim spaces
       int start = token.find_first_not_of(" ");
       int end = token.find_last_not_of(" ");
       if (start != string::npos)
           myInterests.insert(token.substr(start, end - start + 1));
   }

   // BFS queue: {nodeID, depth}
   queue<pair<int, int>> q;
   set<int> visited;

   visited.insert(uid);
   q.push({ uid, 0 });

   while (!q.empty()) {
       auto front = q.front(); q.pop();
       int curr = front.first;
       int depth = front.second;

       if (depth >= 2) continue;

       for (int nb : g.adj[curr]) {
           if (!visited.count(nb)) {
               visited.insert(nb);
               q.push({ nb, depth + 1 });

               // Only score depth-2 non-friends
               if (depth == 1 && !myFriends.count(nb) && nb != uid) {

                   // +3 for mutual friend
                   score[nb] += 3;

                   // +2 same city
                   if (g.users[nb].city == me.city)
                       score[nb] += 2;

                   // +1 same country
                   if (g.users[nb].country == me.country)
                       score[nb] += 1;

                   // +2 per shared interest
                   stringstream ss2(g.users[nb].interests);
                   string tok2;
                   while (getline(ss2, tok2, ',')) {
                       int s = tok2.find_first_not_of(" ");
                       int e = tok2.find_last_not_of(" ");
                       if (s != string::npos) {
                           string interest = tok2.substr(s, e - s + 1);
                           if (myInterests.count(interest))
                               score[nb] += 2;
                       }
                   }
               }
           }
       }
   }

   if (score.empty()) {
       return "No recommendations found for " + me.name + ".\n";

   }

   // STL priority_queue: rank by score (highest first)
   priority_queue<pair<int, int>> pq;
   for (auto& e : score)
       pq.push({ e.second, e.first });

   result += "\n===== Friend Recommendations for "
       + me.name + " =====\n\n";
   result += "  City: " + me.city + " | Interests: " + me.interests + "\n\n";
   result += "------------------------------------------------------------------------\n";
   result += "Rank    Name              City                Score\n";
   result += "-------------------------------------------------------------------------\n";

   int rank = 1;
   while (!pq.empty() && rank <= 5) {
       int pts = pq.top().first;
       int id = pq.top().second;
       pq.pop();

       // formatted output
       string nameStr = g.users[id].name;
       string cityStr = g.users[id].city;
       // pad name to 22 chars
       nameStr.resize(22, ' ');
       cityStr.resize(12, ' ');

       result += " " + to_string(rank) + ".    " + nameStr + cityStr + "   " + to_string(pts) + " pts\n";
       rank++;
   }
//    return result;
//    return  "----------------------------------------------\n";
//    return "Score = mutual friends(+3) + same city(+2) + country(+1) + interests(+2 each)\n";
// }
// ... inside recommendFriends, near the bottom ...
   result += "----------------------------------------------\n";
   result += "Score = mutual friends(+3) + same city(+2) + country(+1) + interests(+2 each)\n";
   
   return result; // Everything else below this line in your original code will never run
}

// ─────────────────────────────────────────────────────────────
// BFS TRAVERSAL
// Visits all reachable users level by level from startUID
// Shows degrees of separation from starting user
// Uses STL: queue, map
// Time Complexity : O(V + E)
// Space Complexity: O(V)
// ─────────────────────────────────────────────────────────────
// string Algorithms::BFSTraversal(Graph& g, int startUID) {
//     if (!g.userExists(startUID)) {
//         return "User not found!";
//     }

//     // 1. Create a string to store all the output
//     string result = "";
//     result += "\n===== BFS Traversal from " + g.users[startUID].name + " =====\n";

//     queue<int> q;
//     map<int, int> dist;

//     dist[startUID] = 0;
//     q.push(startUID);

//     int currentLevel = -1;

//     while (!q.empty()) {
//         int curr = q.front(); q.pop();
//         int level = dist[curr];

//         if (level != currentLevel) {
//             currentLevel = level;
//             if (level == 0)
//                 result += "\nDegree 0 (You):\n";
//             else
//                 result += "\nDegree " + to_string(level) + " (" + to_string(level) + " hop(s) away):\n";
//             result += "  ";
//         }

//         result += g.users[curr].name;
//         if (level > 0) result += " [" + to_string(curr) + "]";
//         result += "  ";

//         for (int nb : g.adj[curr]) {
//             if (!dist.count(nb)) {
//                 dist[nb] = level + 1;
//                 q.push(nb);
//             }
//         }
//     }

//     result += "\n\n-----------------------------------------\n";
//     result += "Total users reached : " + to_string(dist.size()) + "\n";
//     result += "Starting user       : " + g.users[startUID].name + "\n";
//     result += "-----------------------------------------\n";

//     // 2. CRITICAL FIX: Return the final string
//     return result; 
// }
string Algorithms::BFSTraversal(Graph& g, int startUID) {
    if (!g.userExists(startUID))
        return "User not found!\n";

    string result = "";
    result += "===== BFS Traversal from "
           + g.users[startUID].name + " =====\n";

    queue<int> q;
    map<int, int> dist;

    dist[startUID] = 0;
    q.push(startUID);

    int currentLevel = -1;

    while (!q.empty()) {
        int curr  = q.front(); q.pop();
        int level = dist[curr];

        if (level != currentLevel) {
            currentLevel = level;
            if (level == 0)
                result += "\nDegree 0 (You):\n  ";
            else
                result += "\nDegree " + to_string(level)
                       + " (" + to_string(level)
                       + " hop(s) away):\n  ";
        }

            result += "   ";
            result += g.users[curr].name;

            if(level > 0)
            {
                result += " [";
                result += to_string(curr);
                result += "]";
            }

            result += "\n";

        for (int nb : g.adj[curr]) {
            if (!dist.count(nb)) {
                dist[nb] = level + 1;
                q.push(nb);
            }
        }
    }

    result += "\n\n-----------------------------------------\n";
    result += "Total users reached : " + to_string(dist.size()) + "\n";
    result += "Starting user       : " + g.users[startUID].name + "\n";
    result += "-----------------------------------------\n";
    return result;
}