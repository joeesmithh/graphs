#include "GUIGraph.h"


GUIGraph::GUIGraph(QWidget* parent) : QGraphicsView(parent)
{
	setScene(new QGraphicsScene(this));
	setRenderHint(QPainter::RenderHint::TextAntialiasing);
	
	populateGraph(50);

	auto func = [](GUIVertex* vertex) {
		vertex->setPen(QPen(QColor(0, 0, 255)));
	};
	vertices.depthFirstTraversal(vertices.getRoot(), func);
}

void GUIGraph::populateGraph(const int& vertices)
{
	/* Create ellipses */
	GUIVertex* previous = nullptr;
	for (int i = 1, j = 1; i <= vertices; i++)
	{
		/* Accumulate radius multiplier */
		if (((2 + i) % 3) == 0) {
			j++;
		}

		GUIVertex* vertex = new GUIVertex((j * VERTEX_SPACING) * -cos(i), (j * VERTEX_SPACING) * -sin(i),
			VERTEX_SCALE, VERTEX_SCALE,
			QString::number(i));

		if (previous != nullptr)
			GUIGraph::vertices.add(previous, vertex, 1);

		/* Create and add ellipse to scene */
		scene()->addItem(vertex);

		previous = vertex;
	}
}