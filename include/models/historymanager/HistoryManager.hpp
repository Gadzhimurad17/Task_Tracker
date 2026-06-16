#pragma once
#include <stack>
// #include <memory>
#include "../Task.hpp"
namespace Entities {
class HistoryManager {

public:
    std::stack<Task> undoHistory;
    std::stack<Task> redoHistory;
    HistoryManager() = default;
    HistoryManager(std::stack<Task> &uH) : undoHistory(std::move(uH)){};

    void AddInUndo(const Task &task);
    void AddInRedo(const Task &task);
};
}  // namespace Entities
