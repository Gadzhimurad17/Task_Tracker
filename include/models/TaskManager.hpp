#pragma once
#include "Task.hpp"
// #include <memory>
#include "historymanager/HistoryManager.hpp"
#include <vector>
namespace Entities
{
class TaskManager
{
  private:
    std::vector<Task> tasks;
    HistoryManager historyManager{};

  public:
    explicit TaskManager(std::vector<Task> &tasks_, std::stack<Task> uH)
        : tasks(tasks_), historyManager(uH){

                         };
    void AddTask(Task &task);
    void Print(const unsigned int id);
    const Task *GetTask(const unsigned int task_id) const;
    Task *GetTask(const unsigned int task_id);
    void RemoveTask(const unsigned int task_id);
    void ChangeStatus(const unsigned int task_id, Status &&s);
    void ChangePriority(const unsigned int task_id, Priority &&p);
    void Undo();
    void Redo();
};
} // namespace Entities
