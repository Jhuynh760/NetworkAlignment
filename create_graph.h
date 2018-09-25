#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <string>

class Graph{
    private:
        int numVertices;
        int numConnectedComponents;
        int minDegree;
        int maxDegree;
        std::string inpFile;
        std::list<int> *adjMatrix;

        void DFS(int numVertices, bool visited[]);
        void connectedComponents();
        int getNumConnectedComponents();
        int getMinDegree();
        int getMaxDegree();
        void print();
        void write();
    public:
        Graph(int numNodes, std::string inputFile);
        void addEdge(int fromNode, int toNode);
        void run();
        ~Graph();
}; 
