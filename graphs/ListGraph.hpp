#pragma once

#include "GraphInterface.hpp"

namespace Graphs {
class ListGraph : public IGraph {
public:
    ListGraph(const int vertexCount);
    ListGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> nextAdjacent;
    std::vector<std::vector<int>> prevAdjacent;
};
} // namespace Graphs
