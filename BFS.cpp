#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

/*
    Input:
    Adjacent list: 
    A: [B, C],
    B: [A, D, E],
    C: [A, F],
    D: [B],
    E: [B, F],
    F: [C, E]
*/

vector<char> BFS(map<char, vector<char>> *map, char start, char target) {
    queue<char> bfs_queue; 
    set<char> visited;
    
    vector<char> result;
    bfs_queue.push(start);
    result.push_back(start);
    while (!bfs_queue.empty()) {
        char state = bfs_queue.front();
        bfs_queue.pop();
        visited.insert(state);

        auto neighbor = map->find(state);
        for (char near: neighbor->second) {
            if (near == target) {
                result.push_back(near);
                return result;
            }
            if (visited.find(near) == visited.end()) {
                bfs_queue.push(near);
                visited.insert(near);
                result.push_back(near);
            }
        }
    }
}

/*
    Author: Quang Minh
    Create At: 13/1/2025
    Beadth First Search
*/
int main () {
    /*
        Init component:
    */

    map<char, vector<char>> map;

    map['A'] = {'B', 'D'};
    map['B'] = {'A', 'C', 'E'};
    map['C'] = {'B', 'F'};
    map['D'] = {'A', 'E'};
    map['E'] = {'B', 'D', 'F'};
    map['F'] = {'C', 'E'};


    /*
        Find one point
        Example:
        Start at A
        Find to F
    */

    char start = 'B';
    char target = 'F';
    vector<char> path = BFS(&map, start, target);

    cout << "Path from " << start << " to " << target << ": ";
    for (char c : path) {
        cout << c << " ";
    }

    return 0;
}