#pragma once
#include "Graph.h"
#include <string>
using namespace std;

class FileHandler {
public:
    void loadUsersCSV(Graph& g, string filename);
    void loadFriendshipsCSV(Graph& g, string filename);
    void saveNetwork(Graph& g, string filename);
};
