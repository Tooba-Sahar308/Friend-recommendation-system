# 🌐 Social Network Friend Recommendation System

A **C++-based Social Network and Friend Recommendation System** that models users and their friendships as a graph and uses **Breadth-First Search (BFS)** and a **recommendation scoring algorithm** to discover and rank potential friends.

The system analyzes the user's existing network, identifies indirect connections, and recommends users based on **mutual friends, shared interests, and profile similarities**.

---

## Overview

Social networks can be represented naturally using **Graph Data Structures**, where:

* 👤 **Users** → Vertices / Nodes
* 🤝 **Friendships** → Edges
* 🔍 **BFS Traversal** → Explores the user's network
* ⭐ **Recommendation Score** → Ranks potential friends

Starting from a selected user, the system explores their network level by level and identifies users who are not already directly connected.

The recommendation engine then evaluates these candidates using multiple social factors to produce relevant friend suggestions.

---

##  Key Features

*  User profile management
*  Friendship/network representation using graphs
*  BFS-based social network traversal
*  Friend-of-friend discovery
*  Intelligent friend recommendation scoring
*  Mutual friend analysis
*  Shared-interest matching
*  Location/profile similarity analysis
*  Recommendation ranking
*  CSV-based user and friendship data
*  Interactive visualization using SFML
*  Efficient graph traversal using adjacency lists

---

##  Recommendation Algorithm

The recommendation system combines **graph traversal** with a **scoring mechanism**.

### 1. BFS Network Exploration

Breadth-First Search starts from the selected user and explores the network level by level.

```text
Degree 0 → Selected User
     ↓
Degree 1 → Direct Friends
     ↓
Degree 2 → Friends of Friends
     ↓
Degree 3 → Extended Network
```

A distance map keeps track of how many hops each user is from the selected user and ensures that each user is visited only once.

### 2. Recommendation Scoring

Potential friends are evaluated using social similarities:

| Factor          |           Score |
| --------------- | --------------: |
| Mutual Friend   |              +3 |
| Same City       |              +2 |
| Same Country    |              +1 |
| Shared Interest | +2 per interest |

Users with stronger connections and higher similarity scores are ranked higher in the recommendation list.

### Example

If two users:

* Have **2 mutual friends** → `2 × 3 = 6`
* Share **3 interests** → `3 × 2 = 6`
* Live in the same city → `+2`

Their total recommendation score becomes:

```text
6 + 6 + 2 = 14
```

A higher score indicates stronger recommendation relevance.

---

##  BFS Traversal

The system provides a BFS traversal of the social network from a selected user.



##  System Architecture

```text
              ┌──────────────────┐
              │   User Profiles  │
              └────────┬─────────┘
                       │
                       ▼
              ┌──────────────────┐
              │   Graph Network  │
              │  Users + Edges   │
              └────────┬─────────┘
                       │
                       ▼
              ┌──────────────────┐
              │   BFS Traversal  │
              └────────┬─────────┘
                       │
                       ▼
              ┌──────────────────┐
              │ Candidate Users  │
              └────────┬─────────┘
                       │
                       ▼
              ┌──────────────────┐
              │ Scoring Engine   │
              │ • Mutual Friends │
              │ • Interests      │
              │ • Location       │
              └────────┬─────────┘
                       │
                       ▼
              ┌──────────────────┐
              │ Ranked Friends   │
              │ Recommendations  │
              └──────────────────┘
```

---

##  Technologies & Concepts

### Programming

* **C++**

### Data Structures

* Graph
* Adjacency List
* Queue
* Map
* Arrays / Vectors

### Algorithms

* Breadth-First Search (BFS)
* Graph Traversal
* Similarity-Based Scoring
* Recommendation Ranking

### Visualization

* **SFML**

### Data Storage

* CSV files

---

## 📁 Project Structure

```text
Social-Network/
│
├── src/
│   ├── main.cpp
│   ├── Graph.cpp
│   ├── Graph.h
│   ├── Algorithms.cpp
│   └── Algorithms.h
│
├── data/
│   ├── user.csv
│   └── friendship.csv
│
├── assets/
│   └── ...
│
├── screenshots/
│   └── ...
│
└── README.md
```

---

##  Complexity Analysis

### BFS Traversal

For a graph containing **V vertices** and **E edges**:

**Time Complexity**

```text
O(V + E)
```

**Space Complexity**

```text
O(V)
```

The adjacency-list representation allows the system to efficiently traverse the social network without repeatedly processing the same users.

---

## 💡 Why BFS?

BFS is particularly suitable for social networks because it naturally explores users according to their **degrees of separation**.

```text
1st Degree → Friends
2nd Degree → Friends of Friends
3rd Degree → Extended Connections
```

This allows the system to efficiently discover nearby users in the social graph while maintaining the relationship distance between users.

---

##  Learning Outcomes

This project demonstrates practical implementation of:

* Graph data structures
* Adjacency-list representation
* BFS traversal
* Queue-based graph algorithms
* Hash/map-based visited tracking
* Social network modeling
* Recommendation systems
* Algorithmic complexity analysis
* File-based data management
* C++ object-oriented programming
* SFML-based visualization

---

##  Future Improvements

Possible extensions include:

* 🤖 Machine-learning-based recommendations
* 📈 Advanced user similarity scoring
* 🧠 Personalized recommendation models
* 👥 Community detection
* 🔗 Weighted social graphs
* 📊 Network analytics and statistics
* 🔐 User authentication
* ☁️ Database integration
* 🌐 Web-based version of the system

---

## 👩‍💻Project

Developed as a **Data Structures & Algorithms project** to demonstrate how graph algorithms can be applied to real-world social networking problems.

**Core Idea:**

> Represent the social network as a graph, explore it using BFS, and rank potential friends using social similarity.
