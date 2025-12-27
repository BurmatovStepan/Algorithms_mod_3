add_library(graphs
    GraphInterface.hpp
    GraphUtils.hpp
    ArcGraph.hpp
    ArcGraph.cpp
    ListGraph.hpp
    ListGraph.cpp
    MatrixGraph.hpp
    MatrixGraph.cpp
    SetGraph.hpp
    SetGraph.cpp
)

target_include_directories(graphs PUBLIC .)
