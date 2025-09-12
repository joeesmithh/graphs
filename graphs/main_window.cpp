#include "main_window.h"



main_window::main_window(QWidget* parent)
	: QMainWindow(parent)
{
	/* Window setup */
	setupUi(this);
	setWindowTitle("Graphs");

	createActions();

	/* Scene setup */
	graph = GUIGraph<int>(this);
	setCentralWidget(graph.getView());
	graph.addVertex();
}

main_window::~main_window()
{
}

void main_window::createActions()
{
	addVertex = new QAction(tr("&Create Vertex"), this);
	QMainWindow::menuBar()->addAction(addVertex);
}


