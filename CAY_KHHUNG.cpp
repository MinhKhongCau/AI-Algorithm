#include <bits/stdc++.h>

using namespace std;

int n, A[100][100], T[100][100];
bool kt[100]; //kt = 0 se thuoc V, kt = 1 se thuoc V_H

void Init(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> A[i][j];
        }
    }
    for(int i = 1 ; i <= n ; i++) kt[i] = 1;
}

void Prim(int s){
    kt[s] = 0;
    int Max, soCanh = 0, u, v, l = n;
    while(l){
        Max = INT_MAX;
        for(int i = 1 ; i <= n ; i++){
            if(kt[i] == 0){
                for(int j = 1 ; j <= n ; j++){
                    if(kt[j] == 1){
                        if(A[i][j] < Max && A[i][j] != 0){
                            Max = A[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }
        T[u][v] = A[u][v];
        T[v][u] = A[u][v];
        kt[v] = 0;
        l--;
    }
    cout << n << endl;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= n ; j++){
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    Init();
    Prim(1);
    return 0;
}

