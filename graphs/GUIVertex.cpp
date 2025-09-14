#include "GUIVertex.h"
#include <qgraphicsscene.h>
#include <iostream>


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
	ellipse->setPen(QPen(color));
}

void GUIVertex::display(QGraphicsScene* scene)
{
	ellipse = new QGraphicsEllipseItem(0, 0, width, height);
	ellipse->setPen(QPen(QColor(255, 255, 255)));

	// Create label text as child
	QGraphicsTextItem* text = new QGraphicsTextItem(label, ellipse);

	// Center align label text
	auto text_width = text->boundingRect().width();
	auto text_height = text->boundingRect().height();
	text->setPos(QPointF((width - text_width) / 2, (height - text_height) / 2));

	// Position the ellipse
	ellipse->setPos(xPos, yPos);

	scene->addItem(ellipse);
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