#ifndef GRAPH_VERTEX_H_
#define GRAPH_VERTEX_H_
#include <memory>
#include <vector>
#include <functional>


template<class DataType>
class GraphVertex
{
private:
	DataType data;
	std::vector<std::shared_ptr<GraphVertex<DataType>>> edges; // Collection of pointers to neighbors vertices
	int edgeCount;

public:

	GraphVertex ();

	/** Instantiates a new disconnected vertex without edges.
		@param data The data to store in the new vertex. */
	GraphVertex (const DataType& data);

	/** Instantiates a new vertex with an edge to another
		@param data The data to store in the new vertex. 
		@param edgeToVertex The vertex to connect to. */
	GraphVertex (const DataType& data, const std::shared_ptr<GraphVertex<DataType>>& edgeToVertex);

	/** Form an edge to another vertex if it exists.
		@param vertex The vertex to connect to. 
		@returns True if this vertex was previously connected to a vertex with data matching the given vertex,
					false if an edge was created. */
	bool connectTo (const std::shared_ptr<GraphVertex<DataType>>& vertex);
	
	/** Remove an edge to another vertex if it exists.
		@param vertex The vertex to disconnect from.
		@returns True if vertex with data matching given vertex was disconnected, false otherwise. */
	bool disconnectFrom (const std::shared_ptr<GraphVertex<DataType>>& vertex);

	/** Retrieve the edge count.
		@returns The number of vertices that can be directed. */
	int getEdgeCount () const;

	/** Retrieve the label value.
		@returns The data stored in this vertex. */
	DataType getData () const;

	/** Set the label value. */
	void setData (const DataType& newData);
	void depthFirst (std::vector<GraphVertex<DataType>>& traversed, const std::function<void (GraphVertex<DataType>&)>& visit);

	/** Overloaded operators */
	bool operator >(const GraphVertex<DataType>& other);
	bool operator <(const GraphVertex<DataType>& other);
	bool operator >=(const GraphVertex<DataType>& other);
	bool operator <=(const GraphVertex<DataType>& other);
	bool operator ==(const GraphVertex<DataType>& other);
	bool operator !=(const GraphVertex<DataType>& other);

};
#include "GraphVertex.cpp"
#endif