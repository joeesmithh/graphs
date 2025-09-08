#ifndef MATRIX_GRAPH_H_
#define MATRIX_GRAPH_H_
#include "GraphInterface.h"
#include <memory>

/** A directed and weighted adjacency matrix graph. */
template<class LabelType>
class MatrixGraph: public GraphInterface<LabelType>
{
private:
	const int DEFAULT_SIZE = 32;
	int numVertices;
	int numEdges;
	int maxVertices;
	std::unique_ptr<int[]> edgeMatrix; // 1D array to represent a pseudo-2D neighbor adjacency matrix with edge weights.
	std::unique_ptr<LabelType[]> vertices; // 1D array to represent a pseudo-2D naieghbor adjacency matrix

	int getColumn (const int& vertexIndex) const;
	int getRow (const int& vertexIndex) const;
	int getLabelIndex (const LabelType& label) const;

	/** Gets the vertex with the given label.
		@pre label is associated with a vertex in the graph.
		@label The label of which to retrieve the vertex. 
		@return The pointer to the vertex with the label, or a pointer
			to vertices.get() + numVertices otherwise. */
	int getLabelVertex (const LabelType& label) const;

	/** Determines whether a vertex reference is valid.
		@vertex A pointer to the vertex for which to check validity. 
		@returns True if the pointer points to a vertex in the graph, false if not. */
	bool isGraphVertex (LabelType* vertex) const;

	/** Converts a pointer to a vertex to an index.
		@return the index of vertex to which the pointer points,
			and returns numVertices otherwise. */
	int getVertexIndex (LabelType* vertex) const;

	/** Convert a vertex index to its respective edge list within the matrix.
		@vertexIndex The index of the vertex within the vertices array.
		@return a index within the edge matrix which begins at vertex index's row. */
	int getMatrixRowIndex (int vertexIndex) const;

	int rowToMatrixIndex (const int& row) const;
	void depthfirst (const int& vertexIndex, std::unique_ptr<bool[]>& traversed, void visit(LabelType&));
	bool addVertex (const LabelType& label);

public:

	/** Default constructor. */
	MatrixGraph ();

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
	bool add (LabelType startKey, LabelType endKey, int edgeWeight);

	/** Removes an edge from this graph. If a vertex is left with no other edges,
			it is removed from the graph since this is a connected graph.
		@param start A label for the vertex at the beginning of the edge.
		@param end A label for the vertex at the end of the edge.
		@return True if the edge is removed, or false otherwise. */
	bool remove (LabelType start, LabelType end);

	/** Removes and disconnects a vertex from this graph.
		@param label A label for the vertex to remove.
		@return True if the vertex is removed, or false otherwise. */
	bool removeVertex (LabelType label);

	/** Gets the weight of an edge in this graph.
		@return The weight of the specified edge.
			If no such edge exists, returns a negative integer. */
	int getEdgeWeight (LabelType start, LabelType end) const;

	/** Performs a depth-first search of this graph beginning at the given
			vertex and calls a given function once for each vertex visited.
		@param start A label for the beginning vertex.
		@param visit A client-defined function that performs an operation on
			or with each visited vertex. */
	void depthFirstTraversal (LabelType start, void visit (LabelType&));
};
#include "MatrixGraph.cpp"
#endif