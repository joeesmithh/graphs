#include <qgraphicsview.h>
#include <qstring.h>
#include "ListGraph.h"
#include "GUIVertex.h"

class GUIGraph : public QObject {

	Q_OBJECT

public:
	GUIGraph(QWidget* parent = nullptr);
	QGraphicsView* getView();
	

private:
	int VERTEX_SCALE = 32;
	int VERTEX_SPACING = 24;

	QGraphicsView* view;
	QGraphicsScene* scene;
	ListGraph<GUIVertex> vertices;

	void populateGraph(const int& vertices);

public slots:
	void addVertex(const int& cPos, const int& yPos,
		const QString& label, const QString& label_connectTo);

};
