#include "main_window.h"



main_window::main_window(QWidget* parent)
	: QMainWindow(parent)
{
	/* Window setup */
	setupUi(this);
	setWindowTitle("Graphs");

	/* Scene setup */
	scene = new QGraphicsScene(this);
	view = new QGraphicsView(scene, this);
	view->setRenderHint(QPainter::RenderHint::TextAntialiasing);
	setCentralWidget(view);

	createGraph(50);
}

main_window::~main_window()
{
}

void main_window::createGraph(const int& vertices)
{
	/* Create ellipses */
	int ellipse_scale = 32;
	double pi = 3.14159;
	int distance_mult = 24;
	QGraphicsEllipseItem* previous = nullptr;
	for (int i = 1, j = 1; i <= vertices; i++)
	{
		/* Accumulate radius multiplier */
		if (((2 + i) % 3) == 0) {
			j++;
		}

		/* Create and add ellipse to scene */
		scene->addItem(new GUIVertex((j * distance_mult) * -cos(i), (j * distance_mult) * -sin(i),
			ellipse_scale, ellipse_scale,
			QString::number(i)));
	}
}

