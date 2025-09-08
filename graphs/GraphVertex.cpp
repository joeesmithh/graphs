#ifndef GRAPH_VERTEX_CPP_
#define GRAPH_VERTEX_CPP_
#include "GraphVertex.h"
#include <algorithm>

template<class DataType>
GraphVertex<DataType>::GraphVertex ()
{}

template<class DataType>
void GraphVertex<DataType>::depthFirst (std::vector<std::shared_ptr<GraphVertex<DataType>>>& traversed, const std::function<void (GraphVertex<DataType>&)>& visit)
{
	visit (*this);
	auto me = std::make_shared<GraphVertex<DataType>> (*this);
	traversed.push_back (me);
	for (int i = 0; i < edgeCount; i++)
	{
		edges.at(i)->depthFirst (traversed, visit);
	}
}

template<class DataType>
GraphVertex<DataType>::GraphVertex (const DataType& data): data(data)
{}

template<class DataType>
GraphVertex<DataType>::GraphVertex (const DataType& data, const std::shared_ptr<GraphVertex<DataType>>& edgeToVertex): data (data)
{
	edges.push_back (edgeToVertex);
}

template<class DataType>
bool GraphVertex<DataType>::connectTo (const std::shared_ptr<GraphVertex<DataType>>& vertex)
{
	bool isConnected = false;

	for (int i = 0; i < edgeCount; i++)
		if (*edges.at (i) == vertex->getData ())
			isConnected = true;

	if (!isConnected)
	{
		edges.push_back (vertex);
		edgeCount++;
		isConnected = true;
	}
		
	

	return isConnected;
}

template<class DataType>
bool GraphVertex<DataType>::disconnectFrom (const std::shared_ptr<GraphVertex<DataType>>& vertex)
{
	bool isDisconnectable = false;

	auto edge = std::find (edges.begin (), edges.end (), vertex);
	if (edge != edges.end ())
	{
		edges.erase (edge);
		edgeCount--;
		isDisconnectable = true;
	}

	return isDisconnectable;
}

template<class DataType>
int GraphVertex<DataType>::getEdgeCount () const
{
	return edgeCount;
}

template<class DataType>
void GraphVertex<DataType>::setData (const DataType& newData)
{
	data = newData;
}

template<class DataType>
DataType GraphVertex<DataType>::getData () const
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

#endif