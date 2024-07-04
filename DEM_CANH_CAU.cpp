#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> ds_ke[1000];//danh sach ke
vector<pair<int,int>> v;//danh sach canh
int matrix[500][500];// ma tran
int visited[1000];// danh dau dinh da xet
int point, side;

void reinit() {
    for (int i = 0; i < sizeof(visited)/sizeof(int); i++) {
        visited[i] = 0;
    }
}

void dfs1(int p) {
    visited[p] = 1;
    for (int t : ds_ke[p]) {
        if (!visited[t]) {
            dfs1(t);
        }
    }
}

void dfs2(int p, int f, int e) {
    visited[p] = 1;
    for (int t : ds_ke[p]) {
        if ((p == f && t == e) || (p == e && t == f)) continue;
        if (!visited[t]) {
            dfs2(t,f,e);
        }
    }
}

void canh_cau() {
    int tplt = 0;
    int ans = 0;
    for (int i = 1; i <= point; i++) {
        if (!visited[i]) {
            tplt++;
            dfs1(i);
        }
    }
    for (auto t : v) {
        int x = t.first, y = t.second;
        int dem = 0;
        reinit();
        for (int j = 1; j <= point; j++) {
            if (!visited[j]) {
                dem++;
                dfs2(j,x,y);
            }
        }
        if (tplt < dem) {
            ans++;
        }
    }
    cout<< ans;
}

int main() {
    string str;
    bool mt = false, ls = false, la = false;
    getline(cin,str);
    stringstream ss1(str);
    vector<int> tt1;
    while (ss1>>str) { 
        tt1.push_back(stoi(str));
    }
    if (tt1.size() == 1) {
        vector<int> tt;
        point = tt1[0];
        getline(cin,str);
        stringstream ss2(str);

        while (ss2>>str) { 
            tt.push_back(stoi(str));
        }
        if (tt.size() == point) {
            mt = true;
            pair<int,int> p1;
            for (int j = 1; j <= point; j++) {
                matrix[1][j] = tt[j-1];
                if (tt[j-1] == 1) {
                    p1.first = 1, p1.second = j;
                    v.push_back(p1);
                    ds_ke[1].push_back(j);
                    ds_ke[j].push_back(1);
                }
            }
        }
        else {
            la = true;
            pair<int,int> p1;
            bool first = true;
            for (int t: tt) {
                if (first) {
                    first = false;
                    continue;
                }
                ds_ke[1].push_back(t);
                p1.first = 1; p1.second = t;
                v.push_back(p1);
            }
        }
    }
    if (tt1.size() == 2) {
        point = tt1[0];
        side = tt1[1];
        ls = true;
    }
    //cin.ignore();
    if (la) {
        for (int i = 2; i <= point; i++) {
            getline(cin,str);
            stringstream ss(str);
            string s;
            vector<int> test;
            bool first = true;
            while (ss>>s) {
                if (first) {
                    first = false;
                    continue;
                }
                test.push_back(stoi(s));
            }
            pair<int,int> p1;
            for (int t: test) {
                ds_ke[i].push_back(t);
                if (i > t) continue;
                p1.first = i; p1.second = t;
                v.push_back(p1);
            }
        }
    }
    if (mt) {
        for (int i = 2; i <= point; i++) {
            for (int j = 1; j<=point; j++) {
                int k; cin>>k;
                matrix[i][j] = k;
            }
        }
        pair<int,int> p1;
        for (int i = 2; i <= point; i++) {
            for (int j = i; j <= point; j++) {
                if (matrix[i][j] == 1) {
                    ds_ke[i].push_back(j);
                    ds_ke[j].push_back(i);
                    p1.first = i, p1.second = j;
                    v.push_back(p1);
                }
            }
        }
    }
    if (ls) {
        for (int i = 1; i <= side; i++) {
            getline(cin,str);
            stringstream ss(str);
            string s;
            pair<int,int> test;
            ss>>s;
            test.first = stoi(s);
            ss>>s;
            test.second = stoi(s);
            v.push_back(test);
        }
        for (auto t : v) {
            ds_ke[t.first].push_back(t.second);
            ds_ke[t.second].push_back(t.first);
        }
    }
    canh_cau();
    return 0;
} 