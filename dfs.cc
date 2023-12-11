#include "graph.hpp"
#include <cstdlib>
#include <ios>
#include <iostream>

using namespace std;

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

void print(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << Graph[i][j] << ' ';
        }
        cout << '\n';
    }
}

// the depth first search visits the all nodes that are reacheable from the starting node
void dfs(int row){
    for(int i = row; i < rows; i++){
        for(int j = row; j < columns; j++){
            if(Graph[i][j]!=0 && VISITED[i] == 0){
                cout << "visiting node: " << i + 1 <<  '\n';
                VISITED[i] = 1;
                dfs(j);
                break;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);

    initEdges();
    print();
    dfs(0);
    
    return EXIT_SUCCESS;
}