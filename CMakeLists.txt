cmake_minimum_required(VERSION 3.12)
project(SimpleGraphics)

set(CMAKE_CXX_STANDARD 11)

add_library(SimpleGraphics src/Location.cpp src/Location.h src/Position.cpp src/Position.h src/Node.cpp src/Node.h src/Nodes/TextNode.cpp src/Nodes/TextNode.h test.cpp src/Nodes/AxesNode.cpp src/Nodes/AxesNode.h src/Nodes/PointNode.cpp src/Nodes/PointNode.h src/Nodes/Grid.cpp src/Nodes/Grid.h)