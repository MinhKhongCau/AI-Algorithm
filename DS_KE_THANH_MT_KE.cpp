#include <bits/stdc++.h>

using namespace std;

int A[100][100];

int main(){
    //freopen("Input.txt", "r", stdin);
    int V, dinh, dem = 0, ke[1000], wei[1000], beg[100];
    bool first;
    string s;

    cin >> V;
    cin.ignore();

    int soCanh = 0, j = 0;
    beg[1] = 1;

    while(getline(cin, s)){
        dem++;
        stringstream ss(s);
        first = true;
        if(dem <= V){
            while(ss >> dinh){
                if(first) beg[dem + 1] = dinh + 1;
                else{
                    soCanh++;
                    ke[soCanh] = dinh;
                    wei[soCanh] = 1;
                }
                first = false;
            }
        }
        else{
            first = true;
            while(ss >> dinh){
                if(!first){
                    j++;
                    wei[j] = dinh;   
                }        
                first = false;
            }
        }
    }
    j = 1;
    while(j <= V){
        for(int i = beg[j] ; i <= beg[j + 1] - 1 ; i++) {
            A[j][ke[i]] = wei[i]; 
        }
        j++;
    }
    cout << V << endl;
    for(int i = 1 ; i <= V ; i++){
        for(j = 1 ; j <= V ; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

