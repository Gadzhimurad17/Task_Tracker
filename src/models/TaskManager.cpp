#include "models/TaskManager.hpp"
#include "models/historymanager/HistoryManager.hpp"
#include <cstddef>
#include <iostream>
#include <stdexcept>
namespace Entities {

void TaskManager::AddTask(Task &task) {
    tasks.push_back(std::move(task));
    historyManager.AddInUndo(task);
}

void TaskManager::Print(const unsigned int task_id) {
    for (const auto &x : tasks) {
        if (task_id == x.GetTaskId()) {
            std::cout << x.GetTitle() << ' ' << Task::StatusToString(x.GetStatus()) << ' '
                      << Task::PriorityToString(x.GetPriority()) << std::endl;
        }
    }
}

const Task *TaskManager::GetTask(const unsigned int task_id) const {
    for (const auto &x : tasks) {
        if (x.GetTaskId() == task_id) {
            return &x;
            break;
        }
    }
    throw std::runtime_error("Task not found");
}
Task *TaskManager::GetTask(const unsigned int task_id) {
    for (auto &x : tasks) {
        if (x.GetTaskId() == task_id) {
            return &x;
            break;
        }
    }
    throw std::runtime_error("Task not found");
}
void TaskManager::RemoveTask(const unsigned int task_id) {
    std::erase_if(tasks, [task_id](const Task &task) { return task.GetTaskId() == task_id; });
}

void TaskManager::ChangeStatus(const unsigned int task_id, Status &&s) {
    Task &task = *GetTask(task_id);
    historyManager.AddInUndo(task);
    task.SetStatus(s);
    historyManager.AddInRedo(task);
}

void TaskManager::ChangePriority(const unsigned int task_id, Priority &&p) {
    Task &task(*GetTask(task_id));
    historyManager.AddInUndo(task);
    task.SetPriority(p);
}

void TaskManager::Undo() {
    if (historyManager.undoHistory.empty()) {
        std::cerr << "История пуста" << std::endl;
        return;
    }

    Task &&task1 = std::move(historyManager.undoHistory.top());
    size_t index{task1.GetTaskId() - 1};
    historyManager.undoHistory.pop();
    historyManager.AddInRedo(tasks[index]);
    if (index <= tasks.size()) {

        tasks[index] = task1;
    } else {
        throw std::out_of_range("Попытка обратиться к элементам вне диапазона");
    }
}
void TaskManager::Redo() {
    if (historyManager.redoHistory.empty()) {
        std::cerr << "Redo История пуста" << std::endl;
        return;
    }
    Task &&task1 = std::move(historyManager.redoHistory.top());
    historyManager.redoHistory.pop();
    size_t index{task1.GetTaskId() - 1};
    if (index <= tasks.size()) {
        tasks[index] = task1;
    } else {
        throw std::out_of_range("Попытка обратиться к элементам вне диапазона redoHistory");
    }
}
}  // namespace Entities
