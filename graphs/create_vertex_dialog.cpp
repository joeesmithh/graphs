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

void create_vertex_dialog::addPressed() {
	// TODO:
	// Need to parse labels before sending signal
	emit add(edit_xPos->value(), edit_yPos->value(),
		edit_label->text(), edit_connectTo->text());

	edit_label->setText(edit_connectTo->text());
	edit_connectTo->clear();
}