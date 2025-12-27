#pragma once

#include "GraphInterface.hpp"

namespace Graphs {
class ArcGraph : public IGraph {
public:
    ArcGraph(const int vertexCount);
    ArcGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    struct Edge {
        int from = 0;
        int to = 0;

        Edge(int from, int to) : from(from), to(to) {}
    };

    std::vector<Edge> edges;
    int vertexCount;
};
} // namespace Graphs
