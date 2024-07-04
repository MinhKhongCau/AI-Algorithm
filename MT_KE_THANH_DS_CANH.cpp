#include <iostream>
#include <vector>
using namespace std;

struct graph {
    int matrix[300][300];
    int point,side = 0;
    bool w_num = false,dir = false;
};

void InitMatrix(graph &gr) {
    cin>>gr.point;
    for (int i = 1; i <= gr.point; i++) {
        for (int j = 1; j<=gr.point; j++) {
            int k; cin>>k;
            gr.matrix[i][j] = k;
        }
    }
}

int InitGraph(graph &gr) {
    for (int i = 1; i <= gr.point; i++) {
        for (int j = i ; j <= gr.point; j++) {
            if (gr.matrix[i][j] != gr.matrix[j][i]) gr.dir = true;
            if (gr.matrix[i][j] != 0 && gr.matrix[i][j] != 1) gr.w_num = true;
        }
    }
    if (gr.dir) {
        for (int i = 1; i <= gr.point; i++) {
        for (int j = 1; j <= gr.point; j++)
            if (gr.matrix[i][j] != 0) gr.side++;
        }
    } else {
        for (int i = 1; i <= gr.point; i++) {
            for (int j = i; j <= gr.point; j++)
                if (gr.matrix[i][j] != 0) gr.side++;
        }
    }
    return 1;
}

void Charge_Matrix_to_List(graph gr) {
    cout<<gr.point<<" "<<gr.side<<endl;
    if (gr.dir == false) {
        for (int i = 1; i<=gr.point; i++) {
            for (int j = i; j<=gr.point; j++) {
                if (gr.matrix[i][j] != 0) {
                    if (gr.w_num == true) {
                        cout<<i<<" "<<j<<" "<<gr.matrix[i][j]<<"\n";
                    } else {
                        cout<<i<<" "<<j<<"\n";
                    }
                }
            }
        }
    } else {
        for (int i = 1; i<=gr.point; i++) {
            for (int j = 1; j<=gr.point; j++) {
                if (gr.matrix[i][j] != 0) {
                    if (gr.w_num == true) {
                        cout<<i<<" "<<j<<" "<<gr.matrix[i][j]<<"\n";
                    } else {
                        cout<<i<<" "<<j<<"\n";
                    }
                }
            }
        }
    }
}

int main() {
    graph gr;
    InitMatrix(gr);
    InitGraph(gr);
    Charge_Matrix_to_List(gr);

return 0;
}