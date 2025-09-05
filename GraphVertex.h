#ifndef GRAPH_VERTEX_H_
#define GRAPH_VERTEX_H_
#include <memory>
#include <vector>
#include <functional>


template<class LabelType>
class GraphVertex
{
private:
	LabelType label;
	std::vector<std::shared_ptr<GraphVertex<LabelType>>> edges; // Collection of pointers to neighbors
	int edgeCount;

public:

	GraphVertex ();
	GraphVertex (const LabelType& label);
	GraphVertex (const LabelType& label, const std::shared_ptr<GraphVertex<LabelType>>& edgeToVertex);

	/** Form an edge to another vertex if it exists. */
	bool connectTo (const std::shared_ptr<GraphVertex<LabelType>>& vertex);
	
	/** Remove an edge to another vertex if it exists. */
	bool disconnectFrom (const std::shared_ptr<GraphVertex<LabelType>>& vertex);

	/** Retrieve the edge count. */
	int getEdgeCount () const;

	/** Set the label value. */
	void setLabel (const LabelType& newLabel);
	void depthFirst (std::vector<std::shared_ptr<GraphVertex<LabelType>>>& traversed, const std::function<void (GraphVertex<LabelType>&)>& visit);

	bool operator >(const GraphVertex<LabelType>& other);
	bool operator <(const GraphVertex<LabelType>& other);
	bool operator >=(const GraphVertex<LabelType>& other);
	bool operator <=(const GraphVertex<LabelType>& other);
	bool operator ==(const GraphVertex<LabelType>& other);

	/** Retrieve the label value. */
	LabelType getLabel () const;
};
#include "GraphVertex.cpp"
#endif