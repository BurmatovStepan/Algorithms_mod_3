// Требования: время работы O((N+M)logN), где N-количество городов, M-известных дорог между ними.
// Граф должен быть реализован в виде класса.
//
// Формат входных данных.
// Первая строка содержит число N – количество городов.
// Вторая строка содержит число M - количество дорог.
// Каждая следующая строка содержит описание дороги (откуда, куда, время в пути).
// Последняя строка содержит маршрут (откуда и куда нужно доехать).
//
// Формат выходных данных.
// Вывести длину самого выгодного маршрута.
// ┌─────────────┬─────────────┐
// │     in      │     out     │
// ├─────────────┼─────────────┤
// │  6          │  9          │
// │  9          │             │
// │  0 3 1      │             │
// │  0 4 2      │             │
// │  1 2 7      │             │
// │  1 3 2      │             │
// │  1 4 3      │             │
// │  1 5 3      │             │
// │  2 5 3      │             │
// │  3 4 4      │             │
// │  3 5 6      │             │
// │  0 2        │             │
// └─────────────┴─────────────┘


#include <iostream>
#include <vector>
#include <queue>
#include <limits>


namespace MyGraph {
class ListGraph {
private:
    struct Node {
        int vertex = 0;
        int pathLength = 0;

        Node(int vertex, int pathLength) : vertex(vertex), pathLength(pathLength){}

        friend bool operator<(const Node& self, const Node& other) {
            return self.pathLength > other.pathLength;
        }
    };

    std::vector<std::vector<Node>> nextAdjacent;

public:
    ListGraph(const int vertexCount) : nextAdjacent(vertexCount) {}

    void AddEdge(int from, int to, int pathLength) {
        nextAdjacent[from].push_back({to, pathLength});
        nextAdjacent[to].push_back({from, pathLength});
    }

    int VerticesCount() const {
        return static_cast<int>(nextAdjacent.size());
    }

    std::vector<Node> GetNextVertices(int vertex) const {
        return nextAdjacent[vertex];
    }

    int FindShortestPath(int from, int to) {
        std::vector<int> distance(VerticesCount(), std::numeric_limits<int>::max());
        std::priority_queue<Node> queue;

        distance[from] = 0;

        queue.push({from, 0});

        while (!queue.empty()) {
            Node currentNode = queue.top();
            queue.pop();

            if (currentNode.pathLength > distance[currentNode.vertex]) {
                continue;
            }

            for (const Node& nextVertex : GetNextVertices(currentNode.vertex)) {
                int newDistance = distance[currentNode.vertex] + nextVertex.pathLength;

                if (newDistance < distance[nextVertex.vertex]) {
                    distance[nextVertex.vertex] = newDistance;
                    queue.push({nextVertex.vertex, newDistance});
                }
            }
        }

        return distance[to];
    }
};
} // namespace MyGraph


void ProcessTask() {
    int cityCount = 0;
    int roadCount = 0;

    std::cin >> cityCount >> roadCount;

    MyGraph::ListGraph graph(cityCount);

    int from = 0;
    int to = 0;
    int lenght = 0;
    for (int i = 0; i < roadCount; ++i) {
        std::cin >> from >> to >> lenght;
        graph.AddEdge(from, to, lenght);
    }

    std::cin >> from >> to;

    std::cout << graph.FindShortestPath(from, to);
}

int main() {
    ProcessTask();
    return 0;
}
