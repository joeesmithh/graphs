#ifndef LIST_GRAPH_CPP_
#define LIST_GRAPH_CPP_
#include "ListGraph.h"
#include "GraphVertex.h"
#include <vector>

template<class DataType>
void ListGraph<DataType>::depthfirst(const std::function<void(GraphVertex<DataType>&)>& visit)
{
	if (root != nullptr)
	{
		std::vector<std::shared_ptr<GraphVertex<DataType>>> traversed;
		root->depthFirst(traversed, visit);
	}
}

template<class DataType>
ListGraph<DataType>::ListGraph()
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
bool ListGraph<DataType>::add(DataType startKey, DataType endKey, int edgeWeight)
{
	if (root == nullptr)
	{
		root = std::make_shared<GraphVertex<DataType>>(startKey);
	}
	else
	{
		depthfirst([startKey, endKey](GraphVertex<DataType>& label)
			{
				if (startKey == label.getLabel())
				{
					label.connectTo(std::make_shared<GraphVertex<DataType>>(endKey));
				}
			});
	}
	numVertices++;

	return false;
}

template<class DataType>
bool ListGraph<DataType>::remove(DataType start, DataType end)
{
	return false;
}

template<class DataType>
DataType ListGraph<DataType>::getRoot() const
{
	return root->getLabel();
}

template<class DataType>
int ListGraph<DataType>::getEdgeWeight(DataType start, DataType end) const
{
	return 0;
}

template<class DataType>
void ListGraph<DataType>::depthFirstTraversal(DataType start, const std::function<void(DataType&)>& visit)
{
	depthfirst([visit](GraphVertex<DataType>& label) {

		auto l = label.getLabel();
		visit(l);
		});
}

#endif

