#ifndef GUI_VERTEX_H
#define GUI_VERTEX_H

#include <qgraphicsitem.h>

template<class DataType>
class GUIVertex {

private:
	DataType data;
	QGraphicsEllipseItem* ellipse;

public:
	GUIVertex(const int& xpos, const int& ypos, const int& width, const int& height,
		const DataType& data, QGraphicsItem* parent = (QGraphicsItem*)nullptr);

	/* Assign a color to the vertex border.
		@param color The color to assign. */
	void setColor(const QColor& color);

	QGraphicsEllipseItem* getEllipse() const;
	DataType getData() const;

	bool operator==(const GUIVertex<DataType>& other) const;
	bool operator!=(const GUIVertex<DataType>& other) const;
};
#include "GUIVertex.cpp"
#endif // !GUI_VERTEX_H