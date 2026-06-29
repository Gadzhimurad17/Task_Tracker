#include "models/historymanager/HistoryManager.hpp"

namespace HistoryManager {
void TaskHistoryManager::AddInUndoHistory(const Entities::Task &entity) { undoHistory.push(std::move(entity)); }
void TaskHistoryManager::AddInRedoHistory(const Entities::Task &entity) { redoHistory.push(std::move(entity)); }
const Entities::Task &TaskHistoryManager::GetUndoTop() const {
    if (undoHistory.empty())
        throw std::out_of_range("Undo history is empty");

    return undoHistory.top();
}
void TaskHistoryManager::PopUndoTop() {
    if (undoHistory.empty())
        throw std::out_of_range("Undo history is empty");

    undoHistory.pop();
}
bool TaskHistoryManager::UndoIsEmpty() const {
    if (undoHistory.empty()) {
        return true;
    }
    return false;
}
const Entities::Task &TaskHistoryManager::GetRedoTop() const {
    if (redoHistory.empty())
        throw std::out_of_range("Redo history is empty");

    return redoHistory.top();
};
void TaskHistoryManager::PopRedoTop() {
    if (redoHistory.empty())
        throw std::out_of_range("Redo history is empty");

    redoHistory.pop();
};
bool TaskHistoryManager::RedoIsEmpty() const {
    if (redoHistory.empty()) {
        return true;
    }
    return false;
};
}  // namespace HistoryManager
