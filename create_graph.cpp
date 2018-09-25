#include "create_graph.h"
#include <list>
#include <fstream>
#include <string>

void Graph::DFS(int vertice, bool visited[]){
    visited[vertice] = true;
    // std::cout << vertice << " ";

    std::list<int>::iterator iter;
    for (iter = adjMatrix[vertice].begin(); iter != adjMatrix[vertice].end(); ++iter){
        if (!visited[*iter]){
            DFS(*iter, visited);
        }
    }
}

void Graph::connectedComponents(){
    bool *visited = new bool[numVertices];

    for (int vertice = 0; vertice < numVertices; vertice++){
        visited[vertice] = false;
    }

    for (int vertice = 0; vertice < numVertices; vertice++){
        if (visited[vertice] == false){
            DFS(vertice, visited);
            // std::cout << "\n";
            numConnectedComponents++;
        }
    }

    delete[] visited;
}

int Graph::getNumConnectedComponents(){
    return numConnectedComponents;
}

int Graph::getMinDegree(){
    return minDegree;
}

int Graph::getMaxDegree(){
    return maxDegree;
}

void Graph::print(){
    std::cout << "Number of connected components: " << getNumConnectedComponents() << std::endl;
    for (int sz = 0; sz < numVertices; ++sz){
        int size = adjMatrix[sz].size();
        std::cout << "Degree of vertex " << sz << " is: " << size << std::endl;
        if (size < minDegree){
            minDegree = size;
        }
        if (size > maxDegree){
            maxDegree = size;
        }
    }
    std::cout << "Min Degree: " << getMinDegree() << std::endl;
    std::cout << "Max Degree: " << getMaxDegree() << std::endl;
    std::cout <<"INPUT FILE: " << inpFile << std::endl;
}

void Graph::write(){
    std::ofstream writeFile;
    size_t lastindex = inpFile.find_last_of(".");
    writeFile.open(inpFile.substr(0, lastindex) + ".csv");

    writeFile << "Vertex,Degree\n";

    for (int sz = 0; sz < numVertices; ++sz){
        int size = adjMatrix[sz].size();
        writeFile << std::to_string(sz) + "," + std::to_string(size) << std::endl;

        if (size < minDegree){
            minDegree = size;
        }
        if (size > maxDegree){
            maxDegree = size;
        }
    }
    writeFile.close();
}

Graph::Graph(int numNodes, std::string inputFile): numVertices(numNodes), numConnectedComponents(0), minDegree(1000), maxDegree(-1), inpFile(inputFile){
    adjMatrix = new std::list<int>[numVertices];
}

void Graph::addEdge(int fromNode, int toNode){
    if (std::find(adjMatrix[fromNode].begin(), adjMatrix[fromNode].end(), toNode) ==  adjMatrix[fromNode].end()){
        adjMatrix[fromNode].push_back(toNode);
    }
    if (std::find(adjMatrix[toNode].begin(), adjMatrix[toNode].end(), fromNode) ==  adjMatrix[toNode].end()){
        adjMatrix[toNode].push_back(fromNode);
    }
}

void Graph::run(){
    connectedComponents();
    std::cout << "Number of connected components: " << getNumConnectedComponents() << std::endl;
    // print();
    write();
    std::cout << "Min Degree: " << getMinDegree() << std::endl;
    std::cout << "Max Degree: " << getMaxDegree() << std::endl; 
}

Graph::~Graph(){
    delete[] adjMatrix;
}