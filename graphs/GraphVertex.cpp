#ifndef GRAPH_VERTEX_CPP_
#define GRAPH_VERTEX_CPP_
#include "GraphVertex.h"
#include <algorithm>

template<class LabelType>
GraphVertex<LabelType>::GraphVertex ()
{}

template<class LabelType>
void GraphVertex<LabelType>::depthFirst (std::vector<std::shared_ptr<GraphVertex<LabelType>>>& traversed, const std::function<void (GraphVertex<LabelType>&)>& visit)
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
GraphVertex<DataType>::GraphVertex (const DataType& label): label(label)
{}

template<class LabelType>
GraphVertex<LabelType>::GraphVertex (const LabelType& label, const std::shared_ptr<GraphVertex<LabelType>>& edgeToVertex): label (label)
{
	edges.push_back (edgeToVertex);
}

template<class LabelType>
bool GraphVertex<LabelType>::connectTo (const std::shared_ptr<GraphVertex<LabelType>>& vertex)
{
	bool isConnected = false;

	for (int i = 0; i < edgeCount; i++)
		if (*edges.at (i) == vertex->getLabel ())
			isConnected = true;

	if (!isConnected)
	{
		edges.push_back (vertex);
		edgeCount++;
		isConnected = true;
	}
		
	

	return isConnected;
}

template<class LabelType>
bool GraphVertex<LabelType>::disconnectFrom (const std::shared_ptr<GraphVertex<LabelType>>& vertex)
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

template<class LabelType>
int GraphVertex<LabelType>::getEdgeCount () const
{
	return edgeCount;
}

template<class LabelType>
void GraphVertex<LabelType>::setLabel (const LabelType& newLabel)
{
	label = newLabel;
}

template<class LabelType>
LabelType GraphVertex<LabelType>::getLabel () const
{
	return label;
}

template<class LabelType>
bool GraphVertex<LabelType>::operator>(const GraphVertex<LabelType>& other)
{
	return label > other.label;
}

template<class LabelType>
bool GraphVertex<LabelType>::operator<(const GraphVertex<LabelType>& other)
{
	return label < other.label;
}

template<class LabelType>
bool GraphVertex<LabelType>::operator>=(const GraphVertex<LabelType>& other)
{
	return label >= other.label;
}

template<class LabelType>
bool GraphVertex<LabelType>::operator<=(const GraphVertex<LabelType>& other)
{
	return label <= other.label;
}

template<class LabelType>
bool GraphVertex<LabelType>::operator==(const GraphVertex<LabelType>& other)
{
	return label == other.label;
}

#endif