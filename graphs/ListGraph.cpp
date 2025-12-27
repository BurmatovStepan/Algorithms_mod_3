#include "GraphUtils.hpp"
#include "ListGraph.hpp"


namespace Graphs {
ListGraph::ListGraph(const int vertexCount) : nextAdjacent(vertexCount), prevAdjacent(vertexCount) {}

ListGraph::ListGraph(const IGraph& graph) : nextAdjacent(graph.VerticesCount()), prevAdjacent(graph.VerticesCount()) {
    Graphs::CopyEdges(*this, graph);
}

void ListGraph::AddEdge(int from, int to) {
    nextAdjacent[from].push_back(to);
    prevAdjacent[to].push_back(from);
}

int ListGraph::VerticesCount() const {
    return static_cast<int>(nextAdjacent.size());
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    return nextAdjacent[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    return prevAdjacent[vertex];
}
} // namespace Graphs
