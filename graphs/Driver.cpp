#include "stdafx.h"
#include "main_window.h"
#include <QtWidgets/QApplication>
#include "ListGraph.h"
#include "GraphVertex.h"
#include <iostream>

int main(int argc, char* argv[])
{

    QApplication app(argc, argv);
    main_window window;
    window.show();
    return app.exec();

    return 0;
}
