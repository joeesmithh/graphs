#include "main_window.h"



main_window::main_window(QWidget* parent)
	: QMainWindow(parent)
{
	/* Window setup */
	setupUi(this);
	setWindowTitle("Graphs");

	/* Scene setup */
	graph = new GUIGraph(this);
	setCentralWidget(graph);
}

main_window::~main_window()
{
}


