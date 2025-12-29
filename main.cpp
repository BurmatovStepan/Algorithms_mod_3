#include "graphs/GraphInterface.hpp"

#include "graphs/ArcGraph.hpp"
#include "graphs/ListGraph.hpp"
#include "graphs/MatrixGraph.hpp"
#include "graphs/SetGraph.hpp"

#include <iostream>
#include <algorithm>


void PrintGraph(const Graphs::IGraph& graph) {
    std::cout << "Graph with " << graph.VerticesCount() << " vertices" << '\n';

    for (int i = 0; i < graph.VerticesCount(); ++i) {
        std::cout << i << ": ";

        const auto& nextVertices = graph.GetNextVertices(i);
        for (int vertex : nextVertices) {
            std::cout << vertex << ' ';
        }

        std::cout << '\n';
    }
}


bool CheckForwardGraphEquality(const Graphs::IGraph& self, const Graphs::IGraph& other) {
    if (self.VerticesCount() != other.VerticesCount()) {
        return false;
    }

    for (int i = 0; i < self.VerticesCount(); ++i) {
        std::vector<int> nextSelf = self.GetNextVertices(i);
        std::vector<int> nextOther = other.GetNextVertices(i);

        std::sort(nextSelf.begin(), nextSelf.end());
        std::sort(nextOther.begin(), nextOther.end());

        if (nextSelf != nextOther) {
            return false;
        }
    }

    return true;
}


bool CheckBackwardGraphEquality(const Graphs::IGraph& self, const Graphs::IGraph& other) {
    if (self.VerticesCount() != other.VerticesCount()) {
        return false;
    }

    for (int i = 0; i < self.VerticesCount(); ++i) {
        std::vector<int> nextSelf = self.GetPrevVertices(i);
        std::vector<int> nextOther = other.GetPrevVertices(i);

        std::sort(nextSelf.begin(), nextSelf.end());
        std::sort(nextOther.begin(), nextOther.end());

        if (nextSelf != nextOther) {
            return false;
        }
    }

    return true;
}

void ConversionTest() {
    Graphs::ListGraph original(7);

    original.AddEdge(0, 1);
	original.AddEdge(0, 3);
	original.AddEdge(0, 4);
	original.AddEdge(1, 2);
	original.AddEdge(1, 3);
	original.AddEdge(3, 4);
	original.AddEdge(3, 6);
	original.AddEdge(4, 6);

    Graphs::ArcGraph arcGraph(original);
    Graphs::MatrixGraph matrixGraph(arcGraph);
    Graphs::SetGraph setGraph(matrixGraph);

    std::cout << "Original -> ArcGraph:\n";
    std::cout << "Forward: " << (CheckForwardGraphEquality(original, arcGraph) ? "YES" : "NO") << '\n';
    std::cout << "Backward: " << (CheckBackwardGraphEquality(original, arcGraph) ? "YES" : "NO") << "\n\n";

    std::cout << "Original -> MatrixGraph:\n";
    std::cout << "Forward: " << (CheckForwardGraphEquality(original, matrixGraph) ? "YES" : "NO") << '\n';
    std::cout << "Backward: " << (CheckBackwardGraphEquality(original, matrixGraph) ? "YES" : "NO") << "\n\n";

    std::cout << "Original -> setGraph:\n";
    std::cout << "Forward: " << (CheckForwardGraphEquality(original, setGraph) ? "YES" : "NO") << '\n';
    std::cout << "Backward: " << (CheckBackwardGraphEquality(original, setGraph) ? "YES" : "NO") << "\n\n";
}

void DisconnectedLoopsTest() {
    Graphs::ArcGraph arcGraph(3);
    Graphs::ListGraph listGraph(3);
    Graphs::MatrixGraph matrixGraph(3);
    Graphs::SetGraph setGraph(3);

    for (int i = 0; i < 3; ++i) {
        arcGraph.AddEdge(i, i);
        listGraph.AddEdge(i, i);
        matrixGraph.AddEdge(i, i);
        setGraph.AddEdge(i, i);
    }

    std::cout << "---  ArcGraph  ---\n";
    PrintGraph(arcGraph);

    std::cout << "---  ListGraph  ---\n";
    PrintGraph(listGraph);

    std::cout << "---  MatrixGraph  ---\n";
    PrintGraph(matrixGraph);

    std::cout << "---  SetGraph  ---\n";
    PrintGraph(setGraph);
}


void ProcessTask() {
    ConversionTest();
    DisconnectedLoopsTest();
}

int main() {
    ProcessTask();
    return 0;
}
