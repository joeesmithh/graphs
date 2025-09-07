#include <QMainWindow>
#include "ui_main_window.h"
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qgraphicsitem.h>
#include <cmath>
#include "ListGraph.h"
#include "GUIVertex.h"

class main_window : public QMainWindow, public Ui::main_windowClass
{
	Q_OBJECT

public:
	main_window(QWidget *parent = nullptr);
	~main_window();

private:
	QGraphicsScene* scene;
	QGraphicsView* view;

	void createGraph(const int& vertices); 
};

