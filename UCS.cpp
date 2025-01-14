#include <iostream>
#include <queue>
#include <map>
#include <set>

using namespace std;

vector<char> UCS(map<char, vector<pair<char,int>>> *graph, char start, char target) {
    priority_queue<
        pair<int, char>,
        vector<pair<int, char>>,
        greater<pair<int, char>>
    > ucs_queue;
    set<char> visited;
    map<char,char> parent;

    ucs_queue.push({0,start});

    parent[start] = start;

    while (!ucs_queue.empty()) {
        // Get the node with the smallest cost
        auto [current_cost, state] = ucs_queue.top();
        ucs_queue.pop();

        // Skip if the node is already visited
        if (visited.find(state) != visited.end()) {
            continue;
        }

        visited.insert(state);

        /*
            if find to target
        */
        if (state == target) {
            vector<char> path;
            char child = target;
            while (child != start) {
                path.push_back(child);

                child = parent[child];
            }
            path.push_back(start);
            return path;
        }

        auto neighbors = graph->find(state);
        for (auto [neighbor, edge_cost]: neighbors->second) {
            /*
                if the value had been queue
            */
            if (visited.find(neighbor) == visited.end()) {
                int cost = edge_cost + current_cost;
                ucs_queue.push({cost, neighbor});

                parent[neighbor] = state;
            }
        }
    }
    // If the target is unreachable
    return {};
}

int main () {

    /*
        Init component:
    */

    map<char, vector<pair<char,int>>> graph;

    graph['A'] = {{'B',5}, {'D',3}};
    graph['B'] = {{'C',2}};
    graph['C'] = {{'E',6}, {'G',8}};
    graph['D'] = {{'E',2}, {'F',2}};
    graph['E'] = {{'B',4}};
    graph['F'] = {{'G',3}};
    graph['G'] = {{'E',4}};
    


    /*
        Find one point
        Example:
        Start at A
        Find to F
    */

    char start = 'A';
    char target = 'F';
    vector<char> path = UCS(&graph, start, target);

    cout << "Path from " << start << " to " << target << ": ";
    for (char c : path) {
        cout << c << " ";
    }
}