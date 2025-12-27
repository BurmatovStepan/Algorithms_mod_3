#pragma once

#include "GraphInterface.hpp"

namespace Graphs {
    inline void CopyEdges(IGraph& target, const IGraph& source) {
        for (int i = 0; i < source.VerticesCount(); ++i) {
            for (int to : source.GetNextVertices(i)) {
                target.AddEdge(i, to);
            }
        }
    }
}
