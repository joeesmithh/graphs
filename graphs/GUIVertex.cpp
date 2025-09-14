#include "GUIVertex.h"
#include <qgraphicsscene.h>
#include <iostream>
#include <cmath>


GUIVertex::GUIVertex() : ellipse(nullptr)
{
}

GUIVertex::GUIVertex(const int& xpos, const int& ypos, const int& width,
	const int& height, const QString& label) : GUIVertex()
{
	this->xPos = xpos;
	this->yPos = ypos;
	this->width = width;
	this->height = height;
	this->label = label;
}

void GUIVertex::setColor(const QColor& color)
{
	pen.setColor(color);
	ellipse->setPen(pen);
}

void GUIVertex::setEdgeColors(const QColor& color)
{
	auto children = ellipse->childItems();
	for (auto c : children) {
		if (c->type() == QGraphicsLineItem::Type) {
			QGraphicsLineItem* line = qgraphicsitem_cast<QGraphicsLineItem*>(c);
			linePen.setColor(color);
			qgraphicsitem_cast<QGraphicsLineItem*>(c)->setPen(linePen);
		}
	}
}

void GUIVertex::display(QGraphicsScene* scene)
{
	if (ellipse == nullptr) {
		ellipse = new QGraphicsEllipseItem(0, 0, width, height);

		// Set vertex pen
		pen = QPen(QColor(255, 255, 255));
		pen.setWidth(2);
		ellipse->setPen(pen);

		// Set line pen
		linePen = pen;
		linePen.setStyle(Qt::DashLine);

		// Create label text as child
		QGraphicsTextItem* text = new QGraphicsTextItem(label, ellipse);
		QFont font = text->font();
		font.setBold(true);
		text->setFont(font);

		// Center align label text
		auto text_width = text->boundingRect().width();
		auto text_height = text->boundingRect().height();
		text->setPos(QPointF((width - text_width) / 2, (height - text_height) / 2));

		// Position the ellipse
		ellipse->setPos(xPos, yPos);
		scene->addItem(ellipse);
	}
}

void GUIVertex::makeEdge(const GUIVertex& other)
{
	int to_xPos = other.xPos;
	int to_yPos = other.yPos;
	int to_width = other.width;
	int to_height = other.height;

	// Calculate distance to other vertex
	int xDist = to_xPos - xPos;
	int yDist = to_yPos - yPos;
	auto dist = sqrt(pow(xDist, 2) + pow(yDist, 2));

	// Calculate unit vector to other vertex
	auto xDir = (to_xPos - xPos) / dist;
	auto yDir = (to_yPos - yPos) / dist;

	// Calculate relative line endpoint offsets
	auto xOffset = (width / 2) + (xDir * width / 2);
	auto yOffset = (height / 2) + yDir * height / 2;
	auto to_xOffset = (xDist + (to_width / 2)) - (xDir * width / 2);
	auto to_yOffset = (yDist + (to_height / 2)) - (yDir * height / 2);

	// Create edge line
	QGraphicsLineItem* edge = new QGraphicsLineItem(ellipse);

	// Set pen
	linePen.setColor(QColor(255, 255, 255));
	edge->setPen(linePen);

	// Set line endpoints
	edge->setLine(xOffset, yOffset, to_xOffset, to_yOffset);
}

QGraphicsEllipseItem* GUIVertex::getEllipse() const
{
	return ellipse;
}

QString GUIVertex::getLabel() const
{
	return label;
}

bool GUIVertex::operator==(const GUIVertex& other) const
{
	return label == other.label;
}


bool GUIVertex::operator!=(const GUIVertex& other) const
{
	return label != other.label;
}