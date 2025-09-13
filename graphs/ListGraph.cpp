#ifndef LIST_GRAPH_CPP_
#define LIST_GRAPH_CPP_
#include "ListGraph.h"
#include "GraphVertex.h"
#include <vector>
#include <iostream>

template<class DataType>
ListGraph<DataType>::ListGraph() : root(nullptr), numVertices(0), numEdges(0)
{
}

template<class DataType>
int ListGraph<DataType>::getNumVertices() const
{
	return numVertices;
}

template<class DataType>
int ListGraph<DataType>::getNumEdges() const
{
	return numEdges;
}

template<class DataType>
bool ListGraph<DataType>::add(DataType startKey, DataType endKey, const std::function<void(DataType&)>& addAction, int edgeWeight)
{
	// If no root, create root with startKey and connect it to new vertex with endKey
	if (root == nullptr)
	{
		root = std::make_shared<GraphVertex<DataType>>(startKey);
		addAction(root->getData());

		auto endVertex = std::make_shared<GraphVertex<DataType>>(endKey);
		addAction(endVertex->getData());
		root->connectTo(endVertex);
		numVertices += 2;
	}
	else // There was a root, search for start and end key with depth-first search
	{
		std::shared_ptr<GraphVertex<DataType>> startPtr = nullptr;
		std::shared_ptr<GraphVertex<DataType>> endPtr = nullptr;
		depthFirst([startKey, endKey, &startPtr, &endPtr](std::shared_ptr<GraphVertex<DataType>> vertex)
			{
				if (startKey == vertex->getData()) 
					startPtr = vertex;

				if (endKey == vertex->getData())
					endPtr = vertex;
			}, [](std::shared_ptr<GraphVertex<DataType>> vertex) {});

		// If the start key was found, connect either to existing vertex with end key, 
		// or new vertex with end key
		if (startPtr != nullptr)
		{
			if (endPtr != nullptr)
				startPtr->connectTo(endPtr);
			else {
				auto endVertex = std::make_shared<GraphVertex<DataType>>(endKey);
				addAction(endVertex->getData());
				startPtr->connectTo(endVertex);
				numVertices++;
			}
		}
	}

	return false;
}

template<class DataType>
bool ListGraph<DataType>::add(DataType startKey, DataType endKey, int edgeWeight)
{
	return add(startKey, endKey, [](DataType& data) {}, edgeWeight);
}

template<class DataType>
bool ListGraph<DataType>::remove(DataType start, DataType end)
{
	return false;
}

template<class DataType>
int ListGraph<DataType>::getEdgeWeight(DataType start, DataType end) const
{
	return 0;
}

template<class DataType>
void ListGraph<DataType>::depthFirstTraversal(const std::function<void(DataType&)>& visit,
	const std::function<void(DataType&)>& revisit)
{
	depthFirst(
		[visit](std::shared_ptr<GraphVertex<DataType>> vertex) {visit(vertex->getData());},
		[revisit](std::shared_ptr<GraphVertex<DataType>> vertex) {revisit(vertex->getData());});
}

template<class DataType>
void ListGraph<DataType>::depthFirst(
	const std::function<void(std::shared_ptr<GraphVertex<DataType>>)>& visit,
	const std::function<void(std::shared_ptr<GraphVertex<DataType>>)>& revisit)
{
	if (root != nullptr)
	{
		root->depthFirst(root, traversedStack, visit);
	}

	untraverse(revisit);
}

template<class DataType>
void ListGraph<DataType>::untraverse(const std::function<void(std::shared_ptr<GraphVertex<DataType>>)>& revisit)
{
	// Reverse traverse
	while (traversedStack.size() != 0) {

		// Get and pop vertex
		auto vertex = traversedStack.top();
		traversedStack.pop();

		// Reset traversed flag
		vertex->setIsTraversed(false);

		// Call lambda function parameter with popped vertex as the argument
		revisit(vertex);
	}
}
#endif

