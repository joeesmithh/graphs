#include "GUIGraph.h"
#include <memory>

GUIGraph::GUIGraph(QWidget* parent)
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

QGraphicsView* GUIGraph::getView()
{
	return view;
}

void GUIGraph::addVertex(const int& xPos, const int& yPos,
	const QString& label, const QString& label_connectTo)
{
	auto newVertex = std::make_shared<GUIVertex>(0, 0, 30, 30, label);
	auto connectVertex = std::make_shared<GUIVertex>(xPos, yPos, 30, 30, label_connectTo);
	vertices.add(*newVertex, *connectVertex, [this](GUIVertex& vert) {
		vert.display();
		scene->addItem(vert.getEllipse());
		}, 
		1);
	std::cout << "Size: " << vertices.getNumVertices() << std::endl;
}

void GUIGraph::populateGraph(const int& vertices)
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