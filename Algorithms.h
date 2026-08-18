#pragma once
#include "Graph.h"
#include <queue>
#include <set>
#include <map>
#include <sstream>
using namespace std;

class Algorithms {
public:
    // Recommend friends using BFS (depth-2 traversal)
    string recommendFriends(Graph& g, int uid);

    // BFS traversal from a starting user
    string BFSTraversal(Graph& g, int startUID);
};
