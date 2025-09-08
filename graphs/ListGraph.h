#ifndef LIST_GRAPH_H_
#define LIST_GRAPH_H_
#include <memory>
#include "GraphVertex.h"
#include "GraphInterface.h"

/** A directed and weighted adjacency list graph. */
template<class DataType>
class ListGraph: public GraphInterface<DataType>
{
private:
	std::shared_ptr<GraphVertex<DataType>> root;
	int numVertices;
	int numEdges;

public:

	/** Default constructor. */
	ListGraph ();

	/** Gets the number of vertices in this graph.
		@return The number of vertices in the graph. */
	int getNumVertices () const;

	/** Gets the number of edges in this graph.
		@return The number of edges in the graph. */
	int getNumEdges () const;

	/** Creates an undirected edge in this graph between two vertices
			that have the given labels. If such vertices do not exist, creates
			them and adds them to the graph before creating the edge.
		@param start A label for the first vertex.
		@param end A label for the second vertex.
		@param edgeWeight The integer weight of the edge.
		@return True if the edge is created, or false otherwise. */
	bool add (DataType startKey, DataType endKey, int edgeWeight);

	/** Removes an edge from this graph. If a vertex is left with no other edges,
			it is removed from the graph since this is a connected graph.
		@param start A label for the vertex at the beginning of the edge.
		@param end A label for the vertex at the end of the edge.
		@return True if the edge is removed, or false otherwise. */
	bool remove (DataType start, DataType end);

	DataType getRoot() const;

	/** Gets the weight of an edge in this graph.
		@return The weight of the specified edge.
			If no such edge exists, returns a negative integer. */
	int getEdgeWeight (DataType start, DataType end) const;

	/** Performs a depth-first search of this graph beginning at the given
			vertex and calls a given function once for each vertex visited.
		@param start A label for the beginning vertex.
		@param visit A client-defined function that performs an operation on
			or with each visited vertex. */
	void depthFirstTraversal (DataType start, const std::function<void(DataType&)>& visit);

	void depthfirst (const std::function<void (GraphVertex<DataType>&)>& visit);
};

#include "ListGraph.cpp"
#endif
