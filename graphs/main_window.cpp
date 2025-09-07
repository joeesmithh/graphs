#include "main_window.h"

main_window::main_window(QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);

	setWindowTitle("Graphs");
}

main_window::~main_window()
{}

