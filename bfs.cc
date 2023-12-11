#include "graph.hpp"
#include <cstdlib>
#include <iostream>
#include <iterator>

using namespace std;

#define X ios_base::sync_with_stdio(0);

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

// the breath first search visits the nodes in increasing order of their distance of the starting node
void bfs(int row){
    if(VISITED[row] == 0 && row == 0){
        QUEUE.push(0);
    }

    if(!VISITED[row]){
         cout << "Visiting node " << row + 1 << '\n';
        VISITED[row] = 1;
        while(!QUEUE.empty()){
            for(int j = 0; j < columns; j++){
                if(Graph[row][j] != 0 && VISITED[j] == 0){
                    QUEUE.push(j);
                }
            }
            QUEUE.pop();
            bfs(QUEUE.front());
        }
    }
}


int main(){
    X
    
    initEdges();
    print();
    bfs(0);   
     
    return EXIT_SUCCESS;
}