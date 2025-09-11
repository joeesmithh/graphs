#ifndef GRAPH_VERTEX_CPP_
#define GRAPH_VERTEX_CPP_
#include "GraphVertex.h"
#include <algorithm>
#include <iostream>

template<class DataType>
GraphVertex<DataType>::GraphVertex()
{}

template<class DataType>
GraphVertex<DataType>::GraphVertex(const DataType& data)
	: data(data), edgeCount(0), traversed(false)
{}

template<class DataType>
GraphVertex<DataType>::GraphVertex(const DataType& data,
								   GraphVertex<DataType>& edgeToVertex) : GraphVertex(data)
{
	edges.push_back(edgeToVertex);
}

template<class DataType>
bool GraphVertex<DataType>::equalTo(const GraphVertex& other) const
{
	return data == other.getData();
}

template<class DataType>
bool GraphVertex<DataType>::getTraversed() const
{
	return traversed;
}

template<class DataType>
void GraphVertex<DataType>::setTraversed(const bool& state)
{
	traversed = state;
}

template<class DataType>
bool GraphVertex<DataType>::connectTo(const std::shared_ptr<GraphVertex<DataType>>& other)
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

template<class DataType>
bool GraphVertex<DataType>::disconnectFrom(GraphVertex<DataType>& vertex)
{

	/* Check whether the caller is connected to a vertex with data matching given vertex
		and delete the vertex from edges if so. */
	for (auto curVertex = begin(edges); curVertex < end(edges); ++curVertex)
	{
		if (*curVertex == vertex)
		{
			edges.erase(curVertex);
			edgeCount--;
			return true;
		}
	}

	return false;
}

template<class DataType>
void GraphVertex<DataType>::depthFirst(const std::function<void(GraphVertex<DataType>&)>& visit)
{
	/* Visit this vertex */
	visit(*this);

	/* Mark this vertex as traversed */
	setTraversed(true);

	if (edgeCount > 0)
	{
		/* Traverse connected edges */
		for (auto edgeVertex = edges.begin(); edgeVertex < edges.end(); ++edgeVertex)
		{
			if (!(*edgeVertex)->getTraversed()) {

				/* If vertex has not been traversed, traverse */
				std::cout << "Traversing vertex: " << (*edgeVertex)->getData() << std::endl;
				(*edgeVertex)->depthFirst(visit);
			}		
		}
	}

	setTraversed(false);
}

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
DataType GraphVertex<DataType>::getData() const
{
	return data;
}

template<class DataType>
bool GraphVertex<DataType>::operator>(const GraphVertex<DataType>& other)
{
	return data > other.data;
}

template<class DataType>
bool GraphVertex<DataType>::operator<(const GraphVertex<DataType>& other)
{
	return data < other.data;
}

template<class DataType>
bool GraphVertex<DataType>::operator>=(const GraphVertex<DataType>& other)
{
	return data >= other.data;
}

template<class DataType>
bool GraphVertex<DataType>::operator<=(const GraphVertex<DataType>& other)
{
	return data <= other.data;
}

template<class DataType>
bool GraphVertex<DataType>::operator==(const GraphVertex<DataType>& other)
{
	return data == other.data;
}

template<class DataType>
bool GraphVertex<DataType>::operator!=(const GraphVertex<DataType>& other)
{
	return !(this == other);
}

#endif