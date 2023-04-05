#pragma once

#include <list>
#include <map>
#include <iostream>

using namespace std;

struct Graph_DFS {
    map<int, bool> visited;
    map<int, list<int> > adj;

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void DFSUtil(int v, int target) {
        visited[v] = true;
        cout << v << " ";
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                DFSUtil(*i, target);
    }


    void DFS(int target) {
        for (auto i: adj) {
//            cout << i.first << endl;
            if (!visited[i.first]) DFSUtil(i.first, target);
        }
    }
};
