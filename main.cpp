#include <iostream>
#include <chrono>
#include <iomanip>
#include <random>
#include <vector>

#include "graph_bfs.h"
#include "graph_dfs.h"

using namespace std;

void functions(void (*f)(int), int target) {
    auto start_timer = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    f(target);

    auto end_timer = chrono::high_resolution_clock::now();

    double time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end_timer - start_timer).count();

    time_taken *= 1e-9;
    cout << " " << time_taken << setprecision(4) << endl;
}

int main() {
    //input zone ballanced
    Graph_BFS g(13);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 8);
    g.addEdge(5, 9);
    g.addEdge(6, 10);
    g.addEdge(7, 11);
    g.addEdge(8, 12);

    Graph_DFS g1;
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(0, 4);
    g1.addEdge(1, 5);
    g1.addEdge(2, 6);
    g1.addEdge(3, 7);
    g1.addEdge(4, 8);
    g1.addEdge(5, 9);
    g1.addEdge(6, 10);
    g1.addEdge(7, 11);
    g1.addEdge(8, 12);

    //input zone unballanced
    Graph_BFS g2(13);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(1, 3);
    g2.addEdge(1, 4);
    g2.addEdge(1, 5);
    g2.addEdge(3, 6);
    g2.addEdge(4, 7);
    g2.addEdge(4, 8);
    g2.addEdge(4, 9);
    g2.addEdge(8, 11);
    g2.addEdge(11, 12);
    g2.addEdge(5, 9);
    g2.addEdge(5, 10);

    Graph_DFS g3;
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 5);
    g3.addEdge(3, 6);
    g3.addEdge(4, 7);
    g3.addEdge(4, 8);
    g3.addEdge(4, 9);
    g3.addEdge(8, 11);
    g3.addEdge(11, 12);
    g3.addEdge(5, 9);
    g3.addEdge(5, 10);

    double avg_time_bfs_bal = 0;
    double avg_time_dfs_bal = 0;
    double avg_time_bfs_unbal = 0;
    double avg_time_dfs_unbal = 0;
    for (int i=1; i<=100000; i++) {
        // testing zone BFS ballanced
        cout << "BAL BFS ";
        {
            auto start_timer = chrono::high_resolution_clock::now();
            ios_base::sync_with_stdio(false);

            g.BFS(7);

            auto end_timer = chrono::high_resolution_clock::now();

            double time_taken =
                    chrono::duration_cast<chrono::nanoseconds>(end_timer - start_timer).count();

            time_taken *= 1e-9;
            avg_time_bfs_bal += time_taken;
            cout << " " << time_taken << setprecision(4) << endl;
        }

        // testing zone DFS ballanced
        cout << "BAL DFS ";
        {
            auto start_timer = chrono::high_resolution_clock::now();
            ios_base::sync_with_stdio(false);

            g1.DFS(7);

            auto end_timer = chrono::high_resolution_clock::now();

            double time_taken =
                    chrono::duration_cast<chrono::nanoseconds>(end_timer - start_timer).count();

            time_taken *= 1e-9;
            avg_time_dfs_bal += time_taken;
            cout << " " << time_taken << setprecision(4) << endl;
        }

        // testing zone BFS unballanced
        cout << "UNBAL BFS ";
        {
            auto start_timer = chrono::high_resolution_clock::now();
            ios_base::sync_with_stdio(false);

            g2.BFS(7);

            auto end_timer = chrono::high_resolution_clock::now();

            double time_taken =
                    chrono::duration_cast<chrono::nanoseconds>(end_timer - start_timer).count();

            time_taken *= 1e-9;
            avg_time_bfs_unbal += time_taken;
            cout << " " << time_taken << setprecision(4) << endl;
        }

        // testing zone DFS bunallanced
        cout << "UNBAL DFS ";
        {
            auto start_timer = chrono::high_resolution_clock::now();
            ios_base::sync_with_stdio(false);

            g3.DFS(7);

            auto end_timer = chrono::high_resolution_clock::now();

            double time_taken =
                    chrono::duration_cast<chrono::nanoseconds>(end_timer - start_timer).count();

            time_taken *= 1e-9;
            avg_time_dfs_unbal += time_taken;
            cout << " " << time_taken << setprecision(4) << endl;
        }
    }

    cout << avg_time_bfs_bal/100000 << endl;
    cout << avg_time_dfs_bal/100000 << endl;
    cout << avg_time_bfs_unbal/100000 << endl;
    cout << avg_time_dfs_unbal/100000 << endl;
}