#include "graphs/GraphInterface.hpp"

#include "graphs/ArcGraph.hpp"
#include "graphs/ListGraph.hpp"
#include "graphs/MatrixGraph.hpp"
#include "graphs/SetGraph.hpp"

#include <iostream>


void PrintGraph(const Graphs::IGraph* graph) {
    std::cout << "Graph with " << graph->VerticesCount() << " vertices" << '\n';

    for (int i = 0; i < graph->VerticesCount(); ++i) {
        std::cout << i << ": ";

        const auto& nextVertices = graph->GetNextVertices(i);
        for (int vertex : nextVertices) {
            std::cout << vertex << ' ';
        }

        std::cout << '\n';
    }
}


void ProcessTask() {
    Graphs::IGraph* graph = new Graphs::SetGraph(7);

    graph->AddEdge(0, 1);
	graph->AddEdge(0, 3);
	graph->AddEdge(0, 4);
	graph->AddEdge(1, 2);
	graph->AddEdge(1, 3);
	graph->AddEdge(2, 5);
	graph->AddEdge(3, 4);
	graph->AddEdge(3, 5);
	graph->AddEdge(3, 6);
	graph->AddEdge(4, 6);
	graph->AddEdge(6, 5);

    PrintGraph(graph);

    delete graph;
}

int main() {
    ProcessTask();
    return 0;
}
