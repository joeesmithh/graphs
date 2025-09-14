#include "qstring.h"
#include <qgraphicsitem.h>

class GUIVertex {

private:
	int xPos;
	int yPos;
	int width;
	int height;
	QString label;
	QGraphicsEllipseItem* ellipse;

public:
	GUIVertex();

	GUIVertex(const int& xpos, const int& ypos,
		const int& width, const int& height, const QString& datalabel);

	/* Assign a color to the vertex border.
		@param color The color to assign. */
	void setColor(const QColor& color);

	/* Initialize GUI elements. */
	void display(QGraphicsScene* scene);

	QGraphicsEllipseItem* getEllipse() const;
	QString getLabel() const;

	bool operator==(const GUIVertex& other) const;
	bool operator!=(const GUIVertex& other) const;
};