#include "main_window.h"



main_window::main_window(QWidget* parent)
	: QMainWindow(parent)
{
	/* Window setup */
	setupUi(this);
	setWindowTitle("Graphs");

	createDialog = new create_vertex_dialog(this);

	createActions();

	/* Scene setup */
	graph = new GUIGraph(this);
	connect(createDialog, &create_vertex_dialog::add, graph, &GUIGraph::addVertex);

	setCentralWidget(graph->getView());
	//graph.addVertex();
}

main_window::~main_window()
{
}

void main_window::createActions()
{
	addVertex = new QAction(tr("&Create Vertex"), this);
	connect(addVertex, &QAction::triggered, createDialog, &QDialog::show);

	QMainWindow::menuBar()->addAction(addVertex);
}


