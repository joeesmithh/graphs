#ifndef LIST_GRAPH_CPP_
#define LIST_GRAPH_CPP_
#include "ListGraph.h"
#include "GraphVertex.h"
#include <vector>

template<class LabelType>
void ListGraph<LabelType>::depthfirst(const std::function<void(GraphVertex<LabelType>&)>& visit)
{
	if (root != nullptr)
	{
		std::vector<std::shared_ptr<GraphVertex<DataType>>> traversed;
		root->depthFirst(traversed, visit);
	}
}

template<class LabelType>
ListGraph<LabelType>::ListGraph()
{
}

template<class LabelType>
int ListGraph<LabelType>::getNumVertices() const
{
	return numVertices;
}

template<class LabelType>
int ListGraph<LabelType>::getNumEdges() const
{
	return numEdges;
}

template<class LabelType>
bool ListGraph<LabelType>::add(LabelType startKey, LabelType endKey, int edgeWeight)
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

template<class LabelType>
bool ListGraph<LabelType>::remove(LabelType start, LabelType end)
{
	return false;
}

template<class LabelType>
LabelType ListGraph<LabelType>::getRoot() const
{
	return root->getLabel();
}

template<class LabelType>
int ListGraph<LabelType>::getEdgeWeight(LabelType start, LabelType end) const
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

