/**
 * @file /src/main.cpp
 *
 * @brief Qt based gui.
 *
 * @date 2021 陈泽华
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QApplication>
#include "../include/main_window.hpp"

/*****************************************************************************
** Main
*****************************************************************************/

int main(int argc, char **argv) {

    /*********************
    ** Qt
    **********************/
    QApplication app(argc, argv);
    robot_qt::MainWindow robot_qt(argc,argv);
    robot_qt.setAttribute(Qt::WA_DeleteOnClose);  //当w窗口关闭后，让Qt彻底释放这个界面资源
    robot_qt.show();
    app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    int result = app.exec();

	return result;
}
