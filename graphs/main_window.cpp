#include "main_window.h"
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qgraphicsitem.h>
#include <cmath>

main_window::main_window(QWidget* parent)
	: QMainWindow(parent)
{
	setupUi(this);

	setWindowTitle("Graphs");
	QGraphicsScene* scene = new QGraphicsScene(this);
	QGraphicsView* view = new QGraphicsView(scene, this);
	//view->setRenderHint(QPainter::RenderHint::TextAntialiasing);

	/* Create ellipses */
	int ellipse_scale = 32;
	double pi = 3.14159;
	int distance_mult = 24;
	for (int i = 1, j = 1; i <= 40; i++)
	{
		/* Accumulate radius multiplier */
		if (((2 + i) % 3) == 0) {
			j++;
		}

		/* Create and add ellipse to scene */
		QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem(0, 0, ellipse_scale, ellipse_scale);
		ellipse->setPen(QPen(QColor(255, 255, 255)));
		scene->addItem(ellipse);

		/* Create ellipse label child */
		QGraphicsTextItem* text = new QGraphicsTextItem(QString::number(i), ellipse);

		/* Center align label */
		auto text_width = text->boundingRect().width();
		auto text_height = text->boundingRect().height();
		auto ellipse_width = ellipse->rect().width();
		auto ellipse_height = ellipse->rect().height();
		text->setPos(QPointF((ellipse_width - text_width) / 2, (ellipse_height - text_height) / 2));
		QGraphicsLineItem* line = new QGraphicsLineItem(ellipse_width / 2, ellipse_height / 2, 50, 50, ellipse);
		line->setPen(QPen(QColor(255, 255, 255)));

		/* Position the ellipse */
		ellipse->setPos((j * distance_mult) * -cos(i), (j * distance_mult) * -sin(i));

	}
	setCentralWidget(view);
}

main_window::~main_window()
{}

