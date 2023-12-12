#include <cstdlib>
#include <iostream>
#include <vector>


using namespace std;

#define X ios_base::sync_with_stdio(0);
#define INFINITY 0x7F800000

const int ROWS = 5;
const int COLUMNS = 6;

vector<vector<int>> Graph = vector(ROWS, vector<int>(COLUMNS, 0));
vector<vector<int>> Distance = vector(ROWS, vector<int>(COLUMNS, INFINITY));

void init();

void print(vector<vector<int>> graph);

void dijkstra();

int totalDistance();

int main(){
    X 
    
    init();
    dijkstra();
    
    return EXIT_SUCCESS;
}

void init(){
    // a - b
    Graph[0][1] = 2;
    
    // a - c
    Graph[0][2] = 4;
    
    // b - c
    Graph[1][2] = 1;
    
    // b - d
    Graph[1][3] = 4;
    
    // b - e
    Graph[1][4] = 2;
    
    // c - e
    Graph[2][4] = 3;
    
    // e - d
    Graph[4][3] = 3;
    
    // d - f
    Graph[3][5] = 2;
    
    // e - f
    Graph[4][5] = 2;

    // starting vertex: a
    Distance[0][0] = 0;
    
    cout << "Original matrix" << endl;
    print(Graph);
    cout << "Distance matrix" << endl;
    print(Distance);
}

void print(vector<vector<int>> graph){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
}

void dijkstra(){
   
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            for(int column = 0; column < COLUMNS; column++){
                if(Distance[i][j] > 0 && Graph[i][j] > 0){
                if(Graph[i][j] <= Graph[i][column] && Graph[i][column] > 0 && Distance[i][j] > Graph[i][j]){
                    Distance[i][j] = Graph[i][j];
                }
            }
            }
        }
    }
    cout << "New distance matrix " << endl;
    print(Distance);
    cout << "Total distance = " << totalDistance() << endl;
}

int totalDistance(){
    int sum = 0;
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            for(int c = 0; c < COLUMNS; c++){
                if(Distance[i][j] < Distance[i][c] && Distance[i][c] != INFINITY){
                    sum += Distance[i][j];
                }
            }
        }
    }
    
    return sum;
}