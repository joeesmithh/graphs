#include "stdafx.h"
#include "main_window.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    main_window window;
    window.show();
    return app.exec();
}
