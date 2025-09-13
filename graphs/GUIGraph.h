#include <qgraphicsview.h>
#include <qstring.h>
#include "ListGraph.h"
#include "GUIVertex.h"

/** GUI representation of an adjacenecy list graph. */
class GUIGraph : public QObject {

	Q_OBJECT

public:
	/** Construct a graph with a parent.
		@param parent The QWidget with which to form a parent-child relatioship. */
	GUIGraph(QWidget* parent = nullptr);

	/** Retrieve the graph's graphics view.
		@returns a pointe to the QtGraphicsView associated with
			the graph */
	QGraphicsView* getView();
	
private:
	QGraphicsView* view;
	QGraphicsScene* scene;
	ListGraph<GUIVertex> vertices;

public slots:
	/** GUIVertex creation event handler. Adds new or connects existing vertices.
		@param xPos Horizontal scene position
		@param yPos Vertical scene position
		@param label The label displayed with the origin vertex, also used for
			comparison operations.
		@param label_connectTo The label displayed with the destination vertex,
			also used for comparison operations. */
	void addVertex(const int& xPos, const int& yPos,
		const QString& label, const QString& label_connectTo);

};
