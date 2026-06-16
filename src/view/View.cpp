#include "view/View.hpp"
View::MainWindow::MainWindow()
{
    setCentralWidget(new QWidget);
}

View::MainWindow::~MainWindow() = default;

void View::MainWindow::createGlobalWindow()
{
    this->setMinimumSize(1000, 1000);
    this->setStyleSheet(R"(
       QMainWindow{
            background-color:#3a3d44;
        }
    )");
}
