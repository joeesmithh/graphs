#include <qgraphicsview.h>
#include "ListGraph.h"
#include "GUIVertex.h"

class GUIGraph : public QGraphicsView {

public:
	GUIGraph(QWidget* parent = nullptr);

private:
	int VERTEX_SCALE = 32;
	int VERTEX_SPACING = 24;

	ListGraph<GUIVertex*> vertices;

	void populateGraph(const int& vertices);
};
