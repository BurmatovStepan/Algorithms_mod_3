#pragma once

#include "GraphInterface.hpp"

namespace Graphs {
class MatrixGraph : public IGraph {
public:
    MatrixGraph(const int vertexCount);
    MatrixGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<bool>> adjacencyMatrix;
};
} // namespace Graphs
