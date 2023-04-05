#pragma once

#include <list>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

struct Graph_BFS {
    int V;
    vector<list<int> > adj;

    Graph_BFS(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void BFS(int target) {
        int s = 0;
        vector<bool> visited;
        visited.resize(V, false);
        list<int> queue;
        visited[s] = true;
        queue.push_back(s);
        while (!queue.empty()) {
            s = queue.front();
            cout << s << " ";
//            if (s == target) return;
            queue.pop_front();
            for (auto adjacent: adj[s]) {
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    queue.push_back(adjacent);
                }
            }
        }
//        cout << endl;
    }
};
