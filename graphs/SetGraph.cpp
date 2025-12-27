#include "SetGraph.hpp"
#include "GraphUtils.hpp"


namespace Graphs {
SetGraph::SetGraph(const int vertexCount) : nextAdjacent(vertexCount), prevAdjacent(vertexCount) {}

SetGraph::SetGraph(const IGraph& graph) : nextAdjacent(graph.VerticesCount()), prevAdjacent(graph.VerticesCount()) {
    Graphs::CopyEdges(*this, graph);
}

void SetGraph::AddEdge(int from, int to) {
    nextAdjacent[from].insert(to);
    prevAdjacent[to].insert(from);
}

int SetGraph::VerticesCount() const {
    return nextAdjacent.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    return {nextAdjacent[vertex].begin(), nextAdjacent[vertex].end()};
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    return {prevAdjacent[vertex].begin(), prevAdjacent[vertex].end()};
}
} // namespace Graphs
