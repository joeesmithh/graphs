/** An interface for the ADT undirected, connected graph.
	@file GraphInterface.h */
#ifndef GRAPH_INTERFACE_H_
#define GRAPH_INTERFACE_H_
#include <functional>

template<class DataType>
class GraphInterface
{
public:

	/** Gets the number of vertices in this graph.
		@return The number of vertices in the graph. */
	virtual int getNumVertices () const = 0;

	/** Gets the number of edges in this graph.
		@return The number of edges in the graph. */
	virtual int getNumEdges () const = 0;

	/** Creates an undirected edge in this graph between two vertices
			that have the given labels. If such vertices do not exist, creates
			them and adds them to the graph before creating the edge.
		@param start A label for the first vertex.
		@param end A label for the second vertex.
		@param edgeWeight The integer weight of the edge.
		@return True if the edge is created, or false otherwise. */
	virtual bool add (DataType start, DataType end, int edgeWeight) = 0;

	/** Removes an edge from this graph. If a vertex is left with no other edges,
			it is removed from the graph since this is a connected graph.
		@param start A label for the vertex at the beginning of the edge.
		@param end A label for the vertex at the end of the edge.
		@return True if the edge is removed, or false otherwise. */
	virtual bool remove (DataType start, DataType end) = 0;

	/** Gets the weight of an edge in this graph.
		@return The weight of the specified edge.
			If no such edge exists, returns a negative integer. */
	virtual int getEdgeWeight (DataType start, DataType end) const = 0;

	/** Performs a depth-first search of this graph beginning at the given
			vertex and calls a given function once for each vertex visited.
		@param start A label for the beginning vertex.
		@param visit A client-defined function that performs an operation on
			or with each visited vertex. */
	virtual void depthFirstTraversal(
		const std::function<void(DataType&)>& visit,
		const std::function<void(DataType&)>& revisit) = 0;

	/** Destroys this graph and frees its assigned memory. */
	virtual ~GraphInterface ()
	{}
}; // end GraphInterface
#endif