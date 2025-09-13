#ifndef GRAPH_VERTEX_CPP_
#define GRAPH_VERTEX_CPP_
#include "GraphVertex.h"
#include <algorithm>
#include <iostream>

template<class DataType>
GraphVertex<DataType>::GraphVertex() : edgeCount(0), isTraversed(false)
{
}

template<class DataType>
GraphVertex<DataType>::GraphVertex(const DataType& data)
	: GraphVertex()
{
	GraphVertex::data = data;
}

template<class DataType>
bool GraphVertex<DataType>::equalTo(GraphVertex<DataType>& other)
{
	return data == other.getData();
}

template<class DataType>
bool GraphVertex<DataType>::getIsTraversed() const
{
	return isTraversed;
}

template<class DataType>
void GraphVertex<DataType>::setIsTraversed(const bool& state)
{
	isTraversed = state;
}

template<class DataType>
bool GraphVertex<DataType>::connectTo(std::shared_ptr<GraphVertex<DataType>> other)
{
	if (edgeCount > 0)
	{
		/* Check whether calling vertex is already connected to a vertex with data matching given vertex */
		for (auto edgeVertex = edges.begin(); edgeVertex < edges.end(); edgeVertex++) {
			if ((*edgeVertex)->equalTo(*other)) {
				return true;
			}
		}
	}

	/* If caller is not connected to a vertex with data matching given vertex */
	edges.push_back(other);
	edgeCount++;

	return false;
}

//template<class DataType>
//bool GraphVertex<DataType>::disconnectFrom(GraphVertex<DataType>& vertex)
//{
//
//	/* Check whether the caller is connected to a vertex with data matching given vertex
//		and delete the vertex from edges if so. */
//	for (auto curVertex = begin(edges); curVertex < end(edges); ++curVertex)
//	{
//		if (*curVertex == vertex)
//		{
//			edges.erase(curVertex);
//			edgeCount--;
//			return true;
//		}
//	}
//
//	return false;
//}

//template<class DataType>
//void GraphVertex<DataType>::depthFirst(std::shared_ptr<GraphVertex<DataType>> thisPtr,
//	const std::stack<std::shared_ptr<GraphVertex<DataType>>>& traversedStack,
//	const std::function<void(std::shared_ptr<GraphVertex<DataType>>)>& visit)
//{
//
//
//}

template<class DataType>
int GraphVertex<DataType>::getEdgeCount() const
{
	return edgeCount;
}

template<class DataType>
void GraphVertex<DataType>::setData(const DataType& newData)
{
	data = newData;
}

template<class DataType>
void GraphVertex<DataType>::depthFirst(std::shared_ptr<GraphVertex<DataType>> thisPtr,
	std::stack<std::shared_ptr<GraphVertex<DataType>>>& traversedStack,
	const std::function<void(std::shared_ptr<GraphVertex<DataType>>)>& visit)
{
	if (getIsTraversed()) {
		return;
	}

	// Flag, push to stack, and visit
	setIsTraversed(true);
	traversedStack.push(thisPtr);
	visit(thisPtr);

	// Depth first search all edges
	for (auto it = edges.begin(); it < edges.end(); ++it) {
		auto edgeVertex = *it;
		edgeVertex->depthFirst(edgeVertex, traversedStack, visit);
	}
}

template<class DataType>
DataType& GraphVertex<DataType>::getData()
{
	return data;
}

template<class DataType>
bool GraphVertex<DataType>::operator>(const GraphVertex<DataType>& other) const
{
	return data > other.data;
}

template<class DataType>
bool GraphVertex<DataType>::operator<(const GraphVertex<DataType>& other) const
{
	return data < other.data;
}

template<class DataType>
bool GraphVertex<DataType>::operator>=(const GraphVertex<DataType>& other) const
{
	return data >= other.data;
}

template<class DataType>
bool GraphVertex<DataType>::operator<=(const GraphVertex<DataType>& other) const
{
	return data <= other.data;
}

template<class DataType>
bool GraphVertex<DataType>::operator==(const GraphVertex<DataType>& other) const
{
	return data == other.data;
}

template<class DataType>
bool GraphVertex<DataType>::operator!=(const GraphVertex<DataType>& other) const
{
	return !(*this == other);
}

#endif