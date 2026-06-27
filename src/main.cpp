#include "models/historymanager/HistoryManager.hpp"
#include "models/repository/TaskRepo.hpp"
#include "models/services/TaskService.hpp"
#include <QApplication>
#include <QDockWidget>
#include <QHBoxLayout>
#include <QIcon>
#include <QProgressBar>
#include <QPushButton>
#include <QScrollBar>
#include <QTimer>
#include <QVBoxLayout>
#include <pqxx/pqxx>
int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
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
    std::stack<Entities::Task> undoHistory;
    std::stack<Entities::Task> redoHistory;
    HistoryManager::HistoryManager historyManager{undoHistory, redoHistory};
    Repository::DatabaseManager dbmanager;
    Repository::TaskRepo taskRepo(dbmanager);
    Services::TaskService ts(historyManager, taskRepo);
    Entities::Task task(1, "Create new task", Entities::Priority::high, Entities::Status::created,
                        "Need to create new task", 2, 2, "2026-06-26");
    ts.Create(task);
    Entities::Task task2(1, "Create new task and smthng", Entities::Priority::high, Entities::Status::created,
                         "Need to create new task", 2, 2, "2026-06-26");
    ts.Update(task2);
    ts.Undo();
    ts.Redo();
}
