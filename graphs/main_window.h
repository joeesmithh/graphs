#include <QMainWindow>
#include "ui_main_window.h"
#include "ListGraph.h"
#include "GUIGraph.h"
#include <cmath>

class main_window : public QMainWindow, public Ui::main_windowClass
{
	Q_OBJECT

public:
	main_window(QWidget *parent = nullptr);
	~main_window();

private:
	GUIGraph* graph;
};

