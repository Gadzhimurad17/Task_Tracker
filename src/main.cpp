#include "../include/TaskManager.hpp"
// #include "../include/repository/PostgresTask.hpp"
#include "../include/historymanager/HistoryManager.hpp"
// #include <iostream>
// #include <memory>
#include <vector>


int main() {
    Task makeDir = Task(
        Status::in_progress, "Make Directory",
        Priority::low);
    Task doProject =
    Task(Status::created, "Do Project", Priority::medium);
    Task removeDir = Task(Status::created,"Remove Directory",Priority::medium);
    std::vector<Task> tasks;
    std::stack<Task> tasksHistory;
    HistoryManager hm(tasksHistory);
    TaskManager tasks1(tasks,hm);

    tasks1.AddTask(makeDir);
    tasks1.AddTask(doProject);
    tasks1.AddTask(removeDir);

    tasks1.Print(1);
    tasks1.Print(2);
    tasks1.Print(3);


    tasks1.ChangePriority(1,Priority::critical);
    tasks1.ReturnLastAction(1);
    tasks1.Print(4);

}
