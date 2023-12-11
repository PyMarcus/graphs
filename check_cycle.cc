#include "graph.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define X ios_base::sync_with_stdio(0);

vector <int> cycle;

void initEdges(){
    // 1-4 4-1
    Graph[0][3] = 1;
    Graph[3][0] = 1;
    // 1-2 2-1
    Graph[0][1] = 1;
    Graph[1][0] = 1;
    // 2-5 5-2
    Graph[1][4] = 1;
    Graph[4][1] = 1;
    // 2-3 3-2
    Graph[1][2] = 1;
    Graph[2][1] = 1;
    // 3-5 5-3
    Graph[2][4] = 1;
    Graph[4][2] = 1;
}

void findCycles(int row){
    VISITED[row] = 1;
    
    cout << "Visiting node: " << row + 1 << endl;

    for(int i = row; i < rows; i++){
        for(int j = row; j < columns; j++){
            if(!VISITED[j] && Graph[i][j] != 0){
                findCycles(j);
            }else{
                if(VISITED[j] && j != row && Graph[i][j] != 0){
                auto it = find(cycle.begin(), cycle.end(), j);
                if(it == cycle.end())
                    cycle.push_back(j);
                }
            }
        }
    }
}

int main(){
    X
    initEdges();
    
    findCycles(0);
    
    for(auto node : cycle)
        cout << "cycle detected on node " << node + 1 << endl;
    return 0;
}