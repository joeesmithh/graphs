#ifndef GRAPH_VERTEX_CPP_
#define GRAPH_VERTEX_CPP_
#include "GraphVertex.h"
#include <algorithm>

template<class DataType>
GraphVertex<DataType>::GraphVertex()
{
}

template<class DataType>
GraphVertex<DataType>::GraphVertex(const DataType& data) : data(data)
{
}

template<class DataType>
GraphVertex<DataType>::GraphVertex(const DataType& data,
	const std::shared_ptr<GraphVertex<DataType>>& edgeToVertex) : data(data)
{
	edges.push_back(edgeToVertex);
}

template<class DataType>
bool GraphVertex<DataType>::connectTo(const std::shared_ptr<GraphVertex<DataType>>& vertex)
{
	/* Check whether the caller is already connected to a vertex with data matching given vertex */
	for (auto curVertex = begin(edges); curVertex < end(edges); ++curVertex) {
		if (*(*curVertex) == *vertex) {
			return true;
		}
	}

	/* If caller is not connected to a vertex with data matching given vertex */
	edges.push_back(vertex);
	edgeCount++;

	return false;
}

template<class DataType>
bool GraphVertex<DataType>::disconnectFrom(const std::shared_ptr<GraphVertex<DataType>>& vertex)
{

	/* Check whether the caller is connected to a vertex with data matching given vertex
		and delete the vertex from edges if so. */
	for (auto curVertex = begin(edges); curVertex < end(edges); ++curVertex) {
		if (*(*curVertex) == *vertex) {
			edges.erase(curVertex);
			edgeCount--;
			return true;
		}
	}

	return false;
}

template<class DataType>
void GraphVertex<DataType>::depthFirst(std::vector<GraphVertex<DataType>>& traversed,
	const std::function<void(GraphVertex<DataType>&)>& visit)
{
	/* Visit this vertex */
	visit(*this);

	/* Mark this vertex as traversed */
	traversed.push_back(*this);

	/* Traverse connected edges */
	for (auto curVertex = begin(edges); curVertex < end(edges); ++curVertex) {
		
		/* If vertex has not been traversed, traverse */
		auto marked = std::find(begin(traversed), end(traversed), *(*curVertex));
		if (*marked == *end(traversed)) {
			(*curVertex)->depthFirst(traversed, visit);
		}
	}
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
	return !(data == other.data);
}

#endif