#include "controllers/Controller.hpp"
#include "models/entities/Projects.hpp"
#include "models/repository/DatabaseManager.hpp"
#include "models/repository/ProjectsRepo.hpp"
#include "view/HMenu.hpp"
#include "view/SideBar.hpp"
#include "view/View.hpp"
#include <QApplication>
#include <QDockWidget>
#include <QHBoxLayout>
#include <QIcon>
#include <QProgressBar>
#include <QPushButton>
#include <QScrollBar>
#include <QTimer>
#include <QVBoxLayout>
#include <memory>
#include <pqxx/pqxx>
int main(int argc, char *argv[]) {
#if 0
    QApplication app(argc, argv);
    View::MainWindow window{};
    window.createGlobalWindow();

    SidePannels::SideBar sideBar(&window);
    sideBar.setMinimumSize(300, 600);
    HorisontalMenu::HMenu hMenu{};
    sideBar.AddButton("Add Task");
    sideBar.AddButton("Tasks");
    sideBar.AddButton("Change Task");
    sideBar.Seperate();
    sideBar.AddIcon("Settings", "/home/gadzhimurad/Task_Tracker/src/Settings.png");
    window.show();
    app.exec();
#endif
    Entities::Projects pr(2, "name", "smthng", 2);
    Repository::DatabaseManager db;
    Repository::ProjectsRepo repo(db);
    repo.Create(pr);
}
