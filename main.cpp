#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <utility>
#include "create_graph.h"

int main(int argc, char* argv[]){
    if (argc < 1){
        std::cout << "No file name entered. Exiting program" << std::endl;
        return -1;
    }

    std::ifstream graphfile(argv[1]);

    if (graphfile.is_open() && graphfile.good()){
        // std::cout << "Opened " << argv[1] <<std::endl;
        std::string line = "";
        bool isFirstLine = true;
        int numNodes;
        std::vector<std::pair <int,int>> connections;
        while (getline(graphfile, line)){
            if (isFirstLine){
                numNodes = std::stoi(line);
                // std::cout << "Number of nodes: " << numNodes << std::endl;
                isFirstLine = false;
            }
            else{
                std::istringstream is(line);
                int node1, node2;
                is >> node1 >> node2;
                std::pair<int, int> p(node1, node2);
                connections.push_back(p);
                // std::cout << "Node " << node1 << " going to node " << node2 << std::endl;
            }
        }

        Graph graph(numNodes, argv[1]);
        for (auto p: connections){
            graph.addEdge(p.first, p.second);
        }
        
        graph.run();
    }
    else{
        std::cout << "Failed to open file" <<std::endl;
    }
    return 0;
}
