#pragma once

#include <QMainWindow>
#include "ui_main_window.h"

class main_window : public QMainWindow, public Ui::main_windowClass
{
	Q_OBJECT

public:
	main_window(QWidget *parent = nullptr);
	~main_window();

private:
	 
};

