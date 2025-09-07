#include <qgraphicsitem.h>

class GUIVertex : public QGraphicsEllipseItem {

private:
	QString label;

public:
	GUIVertex(const int& xpos, const int& ypos, const int& width, const int& height,
		const QString& label, QGraphicsItem* parent = (QGraphicsItem*)nullptr);

	bool operator==(const GUIVertex& other);
	bool operator!=(const GUIVertex& other);
};