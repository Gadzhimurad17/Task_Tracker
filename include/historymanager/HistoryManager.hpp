#pragma once
#include <stack>
// #include <memory>
#include "../Task.hpp"
struct HistoryManager{
        std::stack<Task> tasksHistory;
        const int khistorySize{10};
        HistoryManager()=default;
        HistoryManager(std::stack<Task>& tasksHistory1):
                tasksHistory(std::move(tasksHistory1))
        {};
        void AddInHistory(const Task& task);
};
