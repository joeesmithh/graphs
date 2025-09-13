#ifndef GRAPH_VERTEX_H_
#define GRAPH_VERTEX_H_
#include <memory>
#include <vector>
#include <stack>
#include <functional>


template<class DataType>
class GraphVertex
{
private:
	DataType data;
	std::vector<std::shared_ptr<GraphVertex<DataType>>> edges;
	int edgeCount;
	bool isTraversed;

	/** Determine whether the given vertex contains data matching this vertex.
		@param other The vertex to be compared.
		@returns True if the two are equal, false otherwise. */
	bool equalTo(GraphVertex<DataType>& other);

	/** Retrieve the traversed state of this vertex.
		@returns True if this vertex has been traversed, false otherwise. */
	bool getIsTraversed() const;


public:

	/** Default constructor. */
	GraphVertex();

	/** Instantiates a new disconnected vertex without edges.
		@param data The data to store in the new vertex. */
	GraphVertex(const DataType& data);

	/** Assigns the traversal state of this vertex.
		@param The truth state to assign to this vertex. */
	void setIsTraversed(const bool& state);

	/** Form an edge to another vertex if it exists.
		@param vertex The vertex to connect to.
		@returns True if this vertex was previously connected to a vertex with data matching the given vertex,
					false if an edge was created. */
	bool connectTo(std::shared_ptr<GraphVertex<DataType>> other);

	///** Remove an edge to another vertex if it exists.
	//	@param vertex The vertex to disconnect from.
	//	@returns True if vertex with data matching given vertex was disconnected, false otherwise. */
	//bool disconnectFrom (GraphVertex<DataType>& vertex);

	/** Retrieve the edge count.
		@returns The number of vertices that can be directed. */
	int getEdgeCount() const;

	/** Retrieve reference to vertex data.
		@returns Reference to data stored in this vertex. */
	DataType& getData();

	/** Set the label value. */
	void setData(const DataType& newData);

	/** Performs a depth first search beginning at this vertex.
		@param thisPtr A shared pointer to the calling vertex.
		@param traversedStack Reference to a stack containing traversed vertices.
		@param visit Lambda function which takes a shared pointer as a parameter. */
	void depthFirst(std::shared_ptr<GraphVertex<DataType>> thisPtr,
		std::stack<std::shared_ptr<GraphVertex<DataType>>>& traversedStack,
		const std::function<void(std::shared_ptr<GraphVertex<DataType>>)>& visit);

	/** Overloaded operators */
	bool operator>(const GraphVertex<DataType>& other) const;
	bool operator<(const GraphVertex<DataType>& other) const;
	bool operator>=(const GraphVertex<DataType>& other) const;
	bool operator<=(const GraphVertex<DataType>& other) const;
	bool operator==(const GraphVertex<DataType>& other) const;
	bool operator!=(const GraphVertex<DataType>& other) const;

};
#include "GraphVertex.cpp"
#endif