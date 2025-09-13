#include <QMainWindow>
#include "ui_main_window.h"
#include "ListGraph.h"
#include "GUIGraph.h"
#include "create_vertex_dialog.h"
#include <cmath>

class main_window : public QMainWindow, public Ui::main_windowClass
{
	Q_OBJECT

public:
	main_window(QWidget *parent = nullptr);
	~main_window();

private:
	create_vertex_dialog* createDialog;

	GUIGraph* graph;
	QAction* addVertex;
	QAction* traverseStep;

	GUIGraph* getGraph();
	void createActions();
};

