#ifndef GUI_GRAPH_CPP
#define GUI_GRAPH_CPP
#include "GUIGraph.h"
#include "GUIVertex.h"

template<class DataType>
GUIGraph<DataType>::GUIGraph(QWidget* parent)
{
	scene = new QGraphicsScene();
	view = new QGraphicsView(scene, parent);
	view->setScene(scene);
	view->setRenderHint(QPainter::RenderHint::TextAntialiasing);

	//populateGraph(50);

	/*auto func = [](GUIVertex* vertex) {
		vertex->setPen(QPen(QColor(0, 0, 255)));
	};*/
}

template<class DataType>
QGraphicsView* GUIGraph<DataType>::getView()
{
	return view;
}

template<class DataType>
void GUIGraph<DataType>::addVertex()
{

	GUIVertex<int> vert(0, 0, 30, 30, 8);
	GUIVertex<int> vert2(-50, -50, 30, 30, 12);
	scene->addItem(vert.getEllipse());
	scene->addItem(vert2.getEllipse());

	vertices.add(vert, vert2, 1);

	vertices.depthFirstTraversal([](GUIVertex<int>& i)
	{
		std::cout << "Data: " << i.getData() << std::endl;
		i.setColor(QColor(34, 92, 205));
	});
}

template<class DataType>
void GUIGraph<DataType>::populateGraph(const int& vertices)
{
	/* Create ellipses */
	//GUIVertex* previous = nullptr;
	//for (int i = 1, j = 1; i <= vertices; i++)
	//{
	//	/* Accumulate radius multiplier */
	//	if (((2 + i) % 3) == 0) {
	//		j++;
	//	}

	//	GUIVertex* vertex = new GUIVertex((j * VERTEX_SPACING) * -cos(i), (j * VERTEX_SPACING) * -sin(i),
	//		VERTEX_SCALE, VERTEX_SCALE,
	//		QString::number(i));

	//	if (previous != nullptr)
	//		GUIGraph::vertices.add(previous, vertex, 1);

	//	/* Create and add ellipse to scene */
	//	scene()->addItem(vertex);

	//	previous = vertex;
	//}
}

#endif // !GUI_GRAPH_CPP