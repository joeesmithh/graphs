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
	connect(createDialog, &create_vertex_dialog::add, getGraph(), &GUIGraph::addVertex);

	setCentralWidget(graph->getView());
	//graph.addVertex();
}

main_window::~main_window()
{
}

GUIGraph* main_window::getGraph()
{
	if (graph == nullptr) {
		graph = new GUIGraph(this);
	}

	return graph;
}

void main_window::createActions()
{
	addVertex = new QAction(tr("&Create Vertex"), this);
	QMainWindow::menuBar()->addAction(addVertex);
	connect(addVertex, &QAction::triggered, createDialog, &QDialog::show);

	traverseStep = new QAction(tr("&Traverse"), this);
	QMainWindow::menuBar()->addAction(traverseStep);
	connect(traverseStep, &QAction::triggered, getGraph(), &GUIGraph::traverse);

}


