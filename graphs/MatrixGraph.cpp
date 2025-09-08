#ifndef MATRIX_GRAPH_CPP_
#define MATRIX_GRAPH_CPP_
#include "MatrixGraph.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

template<class LabelType>
int MatrixGraph<LabelType>::getColumn (const int& vertexIndex) const
{
	return vertexIndex - (getRow (vertexIndex) * maxVertices);
}

template<class LabelType>
int MatrixGraph<LabelType>::getRow (const int& vertexIndex) const
{
	return vertexIndex / maxVertices;
}

template<class LabelType>
int MatrixGraph<LabelType>::getLabelIndex (const LabelType& label) const
{
	auto beg = vertices.get ();
	auto end = vertices.get () + numVertices;
	int index = std::find (beg, end, label) - beg;

	if (!(index < numVertices))
		index = -1;

	return index;
}

template<class LabelType>
int MatrixGraph<LabelType>::getLabelVertex (const LabelType& label) const
{
	auto vertex = std::find (vertices.get (), vertices.get () + numVertices, label);
	int index = vertex != vertices.get () + numVertices ? vertex - vertices.get () : -1;

	return index;
}

template<class LabelType>
bool MatrixGraph<LabelType>::isGraphVertex (LabelType* vertex) const
{
	bool isVertex = false; // Assume false
	if ((vertex - vertices.get ()) < numVertices)
		isVertex = true;

	return isVertex;
}

template<class LabelType>
int MatrixGraph<LabelType>::getVertexIndex (LabelType* vertex) const
{
	return vertex - vertices.get ();
}

template<class LabelType>
int MatrixGraph<LabelType>::getMatrixRowIndex (int vertexIndex) const
{
	return vertexIndex * maxVertices;
}

template<class LabelType>
int MatrixGraph<LabelType>::rowToMatrixIndex (const int& row) const
{
	return row * numVertices;
}

template<class LabelType>
void MatrixGraph<LabelType>::depthfirst (const int& vertexIndex, std::unique_ptr<bool[]>& traversed, void visit (LabelType&))
{
	// Visit this vertex if it has not already been visited
	if (vertexIndex < numVertices && vertexIndex >= 0
		&& traversed[vertexIndex] == false)
	{
		visit (vertices[vertexIndex]);

		// Mark the vertex as traversed
		traversed[vertexIndex] = true;

		// We will need to consult the adjacency matrix for edge information.
		// Convert vertex index to matrix index with pointer to label.
		int matrixRowBeg = getMatrixRowIndex (vertexIndex);
		int matrixRowEnd = matrixRowBeg + maxVertices;

		// Search matrix row for connected neighbors
		for (int i = matrixRowBeg; i < matrixRowEnd; i++)
		{
			if (edgeMatrix[i] > 0)
			{
				int neighborIndex = i - matrixRowBeg;

				// Traverse edge to neighbor
				depthfirst (neighborIndex, traversed, visit);
			}

		}
	}

	// Traverse disconnected
	for (auto i = 0; i < numVertices; i++)
		if (traversed[i] == false)
			depthfirst (i, traversed, visit);
}

template<class LabelType>
bool MatrixGraph<LabelType>::addVertex (const LabelType& label)
{
	bool isValid = true; // Assume addition valid

	// If room for one
	if (numVertices < maxVertices)
	{
		vertices[numVertices] = label;
		numVertices++;
	}
	else // If no room
	{
		isValid = false; // Addition not possible
	}

	return isValid;
}

template<class LabelType>
MatrixGraph<LabelType>::MatrixGraph ()
{
	numVertices = 0;
	numEdges = 0;
	maxVertices = DEFAULT_SIZE;
	edgeMatrix = std::make_unique<int[]> (maxVertices * maxVertices);
	vertices = std::make_unique<LabelType[]> (maxVertices);
}

template<class LabelType>
int MatrixGraph<LabelType>::getNumVertices () const
{
	return numVertices;
}

template<class LabelType>
int MatrixGraph<LabelType>::getNumEdges () const
{
	return numEdges;
}

template<class LabelType>
bool MatrixGraph<LabelType>::add (LabelType startKey, LabelType endKey, int edgeWeight)
{
	bool isValidAddition = false; // Assume edge addition valid

	// If a vertex for the start label does not exist and
	// the addition of it to the graph was successful.
	int start = getLabelIndex (startKey);
	int end = getLabelIndex (endKey);

	
	if (end >= 0 && start >= 0) // If both start and end are invalid
	{
		isValidAddition = true;

	} // Either end valid or both are valid
	else if (end >= 0) // if end valid, and start invalid
	{
		if (numVertices < maxVertices) // if room
		{
			addVertex (startKey);
			start = numVertices - 1;
			isValidAddition = true;
		}
	}
	else if (start >= 0) // if start valid, and end invalid
	{
		if (numVertices < maxVertices) // if room
		{
			addVertex (endKey);
			end = numVertices - 1;
			isValidAddition = true;
		}
	}
	else
	{
		if ((numVertices + 1) < maxVertices) // if room
		{
			start = numVertices;
			end = numVertices + 1;
			addVertex (startKey);
			addVertex (endKey);
			isValidAddition = true;
		}
	}

	// If an edge addition is definitely possible
	if (isValidAddition)
	{

		// Form the weighted relationship by row
		edgeMatrix[getMatrixRowIndex(start) + end] = edgeWeight;
		edgeMatrix[getMatrixRowIndex(end) + start] = edgeWeight;

		numEdges++;
	}

	return isValidAddition;
}

template<class LabelType>
bool MatrixGraph<LabelType>::remove (LabelType start, LabelType end)
{
	auto begRef = std::find (vertices.get (), vertices.get () + numVertices, start);
	auto endRef = std::find (begRef, vertices.get () + numVertices, end);

	// If both a start and end vertex was located
	if (endRef != vertices.get () + numVertices)
	{
		int begIndex = begRef - vertices.get ();
		int endIndex = endRef - vertices.get ();

		// Get edge matrix references
		int* edges[2] =
		{
			edgeMatrix.get () + ((begIndex * maxVertices) + endIndex),
			edgeMatrix.get () + ((endIndex * maxVertices) + begIndex)
		};

		// If an edge exists from start to end
		if (*edges[0] > 0)
		{
			*edges[0] = 0;
			*edges[1] = 0;
		}
	}

	return false;
}

template<class LabelType>
bool MatrixGraph<LabelType>::removeVertex (LabelType label)
{
	int removeVertexIndex = getLabelVertex (label);
	bool isSuccessful = true;

	// If a vertex with the given label exists
	if (removeVertexIndex != -1)
	{
		numVertices--;
		vertices[removeVertexIndex] = vertices[numVertices];

		// Disconnect edge between final element and remove vertex
		int removeTailEdge = getMatrixRowIndex (numVertices) + removeVertexIndex;
		int tailRemoveEdge = getMatrixRowIndex (removeVertexIndex) + maxVertices;
		edgeMatrix[removeTailEdge] = 0;
		edgeMatrix[tailRemoveEdge] = 0;


		// Convert edge matrix row values to that of the last vertex
		for (int removeColumnIndex = getMatrixRowIndex (removeVertexIndex), tailColumnIndex = getMatrixRowIndex (numVertices - 1);
			 removeColumnIndex < getMatrixRowIndex (removeVertexIndex) + numVertices;
			 removeColumnIndex++, tailColumnIndex++)
		{
			int distance = removeColumnIndex - getMatrixRowIndex (removeVertexIndex);

			edgeMatrix[removeColumnIndex] = edgeMatrix[tailColumnIndex];										// Swap edges at remove index
			edgeMatrix[getMatrixRowIndex (distance) + removeVertexIndex]
				= edgeMatrix[getMatrixRowIndex (distance) + numVertices];	// Swap column edges.

			edgeMatrix[tailColumnIndex] = 0;
			edgeMatrix[getMatrixRowIndex (distance) + numVertices] = 0;
		}

		
		//vertices[numVertices] = 0;
	}
	else
		isSuccessful = false;

	return isSuccessful;
}

template<class LabelType>
int MatrixGraph<LabelType>::getEdgeWeight (LabelType start, LabelType end) const
{
	return 0;
}

template<class LabelType>
void MatrixGraph<LabelType>::depthFirstTraversal (LabelType start, void visit (LabelType&))
{
	int vertexIndex = getLabelIndex (start);
	if (vertexIndex != -1)
	{
		auto traversed = std::make_unique<bool[]> (maxVertices);
		depthfirst (vertexIndex, traversed, visit);
	}
}

#endif
