#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
using namespace std;

struct graph {
    vector<pair<int,int>> v;
    int point,side;
    vector<int> w_num;
    bool dir = false;
};

void Init_graph(graph &gr) {
    for (int i = 1; i <= gr.side; i++) {
        string str;
        getline(cin,str);
        stringstream ss(str);
        string s;
        pair<int,int> p;
        vector<string> v_str;
        // Store point in graph
        while (ss>>s) 
            v_str.push_back(s);
        // get first - second
        p.first = stoi(v_str[0]);
        p.second = stoi(v_str[1]);
        // Case graph have weight number
        if (v_str.size() == 3) {
            gr.w_num.push_back(stoi(v_str[2]));
        }
        gr.v.push_back(p);
    }
    //Check directory
    map<int,int> m;
    for (auto t : gr.v) {
        if (m[t.second] == NULL) {
            m[t.first] = t.second;
        } else {
            gr.dir = true;
        }
    }
}

void Edge_to_Adjacency(graph gr) {
    vector<int> a[300];
    vector<int> weight[300];
    for (auto t : gr.v) {
        a[t.first].push_back(t.second);
        if (!gr.dir) 
            a[t.second].push_back(t.first);
    }
    if (gr.w_num.size() != 0) {
        int k = 0;
        for (auto t : gr.v) {
            weight[t.first].push_back(gr.w_num[k]);
            if (!gr.dir)
                weight[t.second].push_back(gr.w_num[k]);
            k++;
        }
    }
    cout<<gr.point<<"\n";
    int temp = 0;
    for (int i = 1; i <= gr.point; i++) {
        temp += a[i].size();
        cout<<temp<<" ";
        for (int t : a[i]) {
            cout<<t<<" ";
        }
        cout<<"\n";
    }
    if (gr.w_num.size() != 0) {
        temp = 0;
        for (int i = 1; i <= gr.point; i++) {
            temp += a[i].size();
            cout<<temp<<" ";
            for (int t : weight[i]) {
                cout<<t<<" ";
            }
            cout<<"\n";
        }
    }
}

int main() {
    graph gr;
    cin>>gr.point>>gr.side;
    cin.ignore();
    Init_graph(gr);
    Edge_to_Adjacency(gr);

    return 0;
}




