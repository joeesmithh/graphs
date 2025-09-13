#pragma once

#include <QDialog>
#include "ui_create_vertex_dialog.h"

class create_vertex_dialog : public QDialog, public Ui::create_vertex_dialog
{
	Q_OBJECT

public:
	create_vertex_dialog(QWidget *parent = nullptr);
	~create_vertex_dialog();

private:


public slots:
	void addPressed();



signals:
	void add(const int& xpos, const int& ypos,
		const QString& label, const QString& connectLabel);

	 
};

