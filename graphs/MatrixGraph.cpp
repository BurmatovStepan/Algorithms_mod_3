#include "GraphUtils.hpp"
#include "MatrixGraph.hpp"


namespace Graphs {
MatrixGraph::MatrixGraph(const int vertexCount) : adjacencyMatrix(vertexCount, std::vector<bool>(vertexCount, 0)) {}

MatrixGraph::MatrixGraph(const IGraph& graph) : adjacencyMatrix(graph.VerticesCount(), std::vector<bool>(graph.VerticesCount(), 0)) {
    Graphs::CopyEdges(*this, graph);
}

void MatrixGraph::AddEdge(int from, int to) {
    adjacencyMatrix[from][to] = 1;
}

int MatrixGraph::VerticesCount() const {
    return adjacencyMatrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;

    for (int i = 0; i < VerticesCount(); ++i) {
        if (adjacencyMatrix[vertex][i]) {
            result.push_back(i);
        }
    }

    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for (int i = 0; i < VerticesCount(); ++i) {
        if (adjacencyMatrix[i][vertex]) {
            result.push_back(i);
        }
    }

    return result;
}
} // namespace Graphs
