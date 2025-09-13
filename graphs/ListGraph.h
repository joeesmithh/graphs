#ifndef LIST_GRAPH_H_
#define LIST_GRAPH_H_
#include <memory>
#include "GraphVertex.h"
#include "GraphInterface.h"
#include <stack>

/** A directed and weighted adjacency list graph. */
template<class DataType>
class ListGraph : public GraphInterface<DataType>
{
private:
	std::shared_ptr<GraphVertex<DataType>> root;

	// traversedStack: populates on traversal then clears to reset traversal flags
	std::stack<std::shared_ptr<GraphVertex<DataType>>> traversedStack;

	// traversedQueue: populates on traversal, tracks traversal order, clears on new traverse
	std::stack<std::shared_ptr<GraphVertex<DataType>>> traverseOrderStack;

	/* Counters */
	int numVertices;
	int numEdges;

public:

	/** Default constructor. */
	ListGraph();

	/** Gets the number of vertices in this graph.
		@return The number of vertices in the graph. */
	int getNumVertices() const;

	/** Gets the number of edges in this graph.
		@return The number of edges in the graph. */
	int getNumEdges() const;

	/** Creates an undirected edge in this graph between two vertices
			that have the given labels. If such vertices do not exist, creates
			them and adds them to the graph before creating the edge.
		@param start A label for the first vertex.
		@param end A label for the second vertex.
		@param edgeWeight The integer weight of the edge.
		@return True if the edge is created, or false otherwise. */
	bool add(DataType startKey, DataType endKey, const std::function<void(DataType&)>& addAction, int edgeWeight);

	/** Creates an undirected edge in this graph between two vertices
			that have the given labels. If such vertices do not exist, creates
			them and adds them to the graph before creating the edge.
		@param start A label for the first vertex.
		@param end A label for the second vertex.
		@param edgeWeight The integer weight of the edge.
		@return True if the edge is created, or false otherwise. */
	bool add(DataType startKey, DataType endKey, int edgeWeight);

	/** Removes an edge from this graph. If a vertex is left with no other edges,
			it is removed from the graph since this is a connected graph.
		@param start A label for the vertex at the beginning of the edge.
		@param end A label for the vertex at the end of the edge.
		@return True if the edge is removed, or false otherwise. */
	bool remove(DataType start, DataType end);

	/** Gets the weight of an edge in this graph.
		@return The weight of the specified edge.
			If no such edge exists, returns a negative integer. */
	int getEdgeWeight(DataType start, DataType end) const;

	/** Performs a depth-first search of this graph beginning at the given
			vertex and calls a given function once for each vertex visited.
		@param start A label for the beginning vertex.
		@param visit A client-defined function that performs an operation on
			or with each visited vertex.
		@param revisit Lambda function taking reference to vertex data as an argument. */
	void depthFirstTraversal(const std::function<void(DataType&)>& visit,
		const std::function<void(DataType&)>& revisit);

	/** Depth first traversal helper method. Performs a depth-first traversal
		on the graph.
		@param visit A client-defined function that performs an operation on
			or with each visited vertex.
		@param revisit Lambda function taking shared pointer to vertex as an argument. */
	void depthFirst(
		const std::function<void(std::shared_ptr<GraphVertex<DataType>>)>& visit,
		const std::function<void(std::shared_ptr<GraphVertex<DataType>>)>& revisit);

	/** Step through a depth first traversal.
		@param visit A client-defined function that performs an operation on
			or with each visited vertex. */
	void depthStep(
		const std::function<void(DataType&)>& visit,
		const std::function<void(DataType&)>& revisit);

	void clearTraverseOrderStack();

	/** Pops traversed vertices from the traversed stack following a traversal.
		@param revisit Lambda function taking reference to a data type as an argument. */
	void untraverse(const std::function<void(std::shared_ptr<GraphVertex<DataType>>)>& revisit);
};

#include "ListGraph.cpp"
#endif
