#include "GUIVertex.h"
#include <qgraphicsscene.h>

GUIVertex::GUIVertex(const int& xpos, const int& ypos, const int& width, const int& height,
	const QString& label, QGraphicsItem* parent) : QGraphicsEllipseItem(0, 0, width, height, parent)
{
	GUIVertex::label = label;

	setPen(QPen(QColor(255, 255, 255)));

	/* Create label text as child */
	QGraphicsTextItem* text = new QGraphicsTextItem(label, this);
	QString string = "Hi";

	/* Center align label text */
	auto text_width = text->boundingRect().width();
	auto text_height = text->boundingRect().height();
	text->setPos(QPointF((width - text_width) / 2, (height - text_height) / 2));

	/* Position the ellipse */
	setPos(xpos, ypos);
}

bool GUIVertex::operator==(const GUIVertex& other)
{
	return (QString::compare(label, other.label, Qt::CaseInsensitive)) == 0;
}

bool GUIVertex::operator!=(const GUIVertex& other)
{
	return !(label == other.label);
}
