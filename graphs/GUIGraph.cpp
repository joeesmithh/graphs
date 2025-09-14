#include "GUIGraph.h"
#include <memory>

GUIGraph::GUIGraph(QWidget* parent)
{
	scene = new QGraphicsScene();
	view = new QGraphicsView(scene, parent);
	view->setScene(scene);
	view->setRenderHint(QPainter::RenderHint::TextAntialiasing);
}

QGraphicsView* GUIGraph::getView() { return view; }

void GUIGraph::addVertex(const int& xPos, const int& yPos,
	const QString& label, const QString& label_connectTo)
{
	// Initialize dummy vertex for search key
	auto newVertex = std::make_shared<GUIVertex>(0, 0, 30, 30, label);

	// Initialize new vertex to connect to, if needed
	auto connectVertex = std::make_shared<GUIVertex>(xPos * 40, yPos * 40, 30, 30, label_connectTo);

	auto addAction = [this](GUIVertex& left, GUIVertex& right) {
		// Initialize newly created vertices in scene if needed
		if (left.getEllipse() == nullptr) {
			left.display(scene);
		}

		if (right.getEllipse() == nullptr) {
			right.display(scene);
		}
		};

	// Connect the two vertices based on key values
	vertices.add(*newVertex, *connectVertex, addAction, 1);
}

void GUIGraph::traverse()
{
	auto visit = [](GUIVertex& vert) {
		vert.setColor(QColor(0, 0, 255));
		};

	auto revisit = [](GUIVertex& vert) {
		vert.setColor(QColor(255, 255, 255));
		};

	vertices.depthStep(visit, revisit);
}


