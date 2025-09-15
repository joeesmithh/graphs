#include "create_vertex_dialog.h"
#include <iostream>

create_vertex_dialog::create_vertex_dialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	setMaximumSize(sizeHint());

	connect(button_add, &QPushButton::pressed, this, &create_vertex_dialog::addPressed);
}

create_vertex_dialog::~create_vertex_dialog()
{}

void create_vertex_dialog::showEvent(QShowEvent* event)
{
	QWidget* parent = parentWidget();
	QPointF parentPos = parent->pos();
	QSize parentSize = parent->size();

	// Top-center the dialog when shown
	setGeometry(
		parentPos.x() + (parentSize.width() - width()) / 2,
		parentPos.y() + height() / 2, 
		width(), 
		height());
}

void create_vertex_dialog::addPressed() {
	// TODO:
	// Need to parse labels before sending signal
	emit add(edit_xPos->value(), edit_yPos->value(),
		edit_label->text(), edit_connectTo->text());

	edit_label->setText(edit_connectTo->text());
	edit_connectTo->clear();
}