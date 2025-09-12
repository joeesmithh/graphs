#include "main_window.h"



main_window::main_window(QWidget* parent)
	: QMainWindow(parent)
{
	/* Window setup */
	setupUi(this);
	setWindowTitle("Graphs");

	/* Scene setup */
	graph = GUIGraph<int>(this);
	setCentralWidget(graph.getView());
	graph.addVertex();
}

main_window::~main_window()
{
}


