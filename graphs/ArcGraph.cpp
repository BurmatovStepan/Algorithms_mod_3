#include "ArcGraph.hpp"
#include "GraphUtils.hpp"


namespace Graphs {
ArcGraph::ArcGraph(const int vertexCount) : vertexCount(vertexCount) {}

ArcGraph::ArcGraph(const IGraph& graph) : vertexCount(graph.VerticesCount()) {
    Graphs::CopyEdges(*this, graph);
}

void ArcGraph::AddEdge(int from, int to) {
    edges.push_back({from, to});
}

int ArcGraph::VerticesCount() const {
    return vertexCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;

    for (const Edge& edge : edges) {
        if (edge.from == vertex) {
            result.push_back(edge.to);
        }
    }

    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for (const Edge& edge : edges) {
        if (edge.to== vertex) {
            result.push_back(edge.from);
        }
    }

    return result;
}
} // namespace Graphs
