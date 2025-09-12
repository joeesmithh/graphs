#ifndef GUI_VERTEX_CPP_
#define GUI_VERTEX_CPP_

#include "GUIVertex.h"
#include <qgraphicsscene.h>



template<class DataType>
GUIVertex<DataType>::GUIVertex(const int& xpos, const int& ypos, const int& width, const int& height,
							   const DataType& data, QGraphicsItem* parent) : data(data)
{
	ellipse = new QGraphicsEllipseItem(0, 0, width, height, parent);
	ellipse->setPen(QPen(QColor(255, 255, 255)));


	// Create label text as child
	QVariant label = data;
	QGraphicsTextItem* text = new QGraphicsTextItem(label.toString(), ellipse);

	// Center align label text
	auto text_width = text->boundingRect().width();
	auto text_height = text->boundingRect().height();
	text->setPos(QPointF((width - text_width) / 2, (height - text_height) / 2));

	// Position the ellipse
	ellipse->setPos(xpos, ypos);
		
}

template<class DataType>
QGraphicsEllipseItem* GUIVertex<DataType>::getEllipse() const
{
	return ellipse;
}

template<class DataType>
DataType GUIVertex<DataType>::getData() const
{
	return data;
}

template<class DataType>
bool GUIVertex<DataType>::operator==(const GUIVertex<DataType>& other) const
{
	return data == other.data;
}

template<class DataType>
bool GUIVertex<DataType>::operator!=(const GUIVertex<DataType>& other) const
{
	return !(*this == other);
}

#endif // !GUI_VERTEX_CPP_
