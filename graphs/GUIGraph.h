#ifndef GUI_GRAPH_H
#define GUI_GRAPH_H

#include <qgraphicsview.h>
#include "ListGraph.h"
#include "GUIVertex.h"

template<class DataType>
class GUIGraph {

public:
	GUIGraph(QWidget* parent = nullptr);
	QGraphicsView* getView();
	void addVertex();

private:
	int VERTEX_SCALE = 32;
	int VERTEX_SPACING = 24;

	QGraphicsView* view;
	QGraphicsScene* scene;
	ListGraph<GUIVertex<DataType>> vertices;

	void populateGraph(const int& vertices);
};
#include "GUIGraph.cpp"
#endif // !GUI_GRAPH_H
