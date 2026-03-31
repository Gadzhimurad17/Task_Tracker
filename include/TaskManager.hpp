#pragma once
#include "Task.hpp"
#include <list>
// #include <memory>
#include <vector>
#include "historymanager/HistoryManager.hpp"
class TaskManager{
    private:
        std::vector<Task> tasks;
        HistoryManager historyManager{};
    public:
        explicit TaskManager(std::vector<Task>& tasks1,HistoryManager hManager):
            tasks(std::move(tasks1)),
            historyManager(hManager)
        {

        };
        void AddTask(Task& task);
        void Print(const uint id);
        Task& GetTask(const uint ID);
        void RemoveTask(const uint ID);
        void ChangeStatus(const uint ID,Status&& s);
        void ChangePriority(const uint ID,Priority&& p);
        void ReturnLastAction(uint ID);


};
