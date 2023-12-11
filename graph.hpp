#ifndef GRAPH
#define GRAPH

#include <vector>
#include <queue>


int rows = 5;
int columns = 5;

std::vector<int> VISITED = std::vector<int>(rows, 0);

std::vector<std::vector<int>> Graph(rows, std::vector<int>(columns, 0));


std::queue<int> QUEUE;

#endif