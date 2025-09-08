#ifndef GRAPH_VERTEX_H_
#define GRAPH_VERTEX_H_
#include <memory>
#include <vector>
#include <functional>


template<class DataType>
class GraphVertex
{
private:
	DataType label;
	std::vector<std::shared_ptr<GraphVertex<DataType>>> edges; // Collection of pointers to neighbors vertices
	int edgeCount;

public:

	GraphVertex ();
	GraphVertex (const DataType& label);
	GraphVertex (const DataType& label, const std::shared_ptr<GraphVertex<DataType>>& edgeToVertex);

	/** Form an edge to another vertex if it exists. */
	bool connectTo (const std::shared_ptr<GraphVertex<DataType>>& vertex);
	
	/** Remove an edge to another vertex if it exists. */
	bool disconnectFrom (const std::shared_ptr<GraphVertex<DataType>>& vertex);

	/** Retrieve the edge count. */
	int getEdgeCount () const;

	/** Set the label value. */
	void setLabel (const DataType& newLabel);
	void depthFirst (std::vector<std::shared_ptr<GraphVertex<DataType>>>& traversed, const std::function<void (GraphVertex<DataType>&)>& visit);

	bool operator >(const GraphVertex<DataType>& other);
	bool operator <(const GraphVertex<DataType>& other);
	bool operator >=(const GraphVertex<DataType>& other);
	bool operator <=(const GraphVertex<DataType>& other);
	bool operator ==(const GraphVertex<DataType>& other);

	/** Retrieve the label value. */
	DataType getLabel () const;
};
#include "GraphVertex.cpp"
#endif