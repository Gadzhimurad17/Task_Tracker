#include "models/historymanager/HistoryManager.hpp"

namespace HistoryManager {
void HistoryManager::AddInUndoHistory(const Entities::Task &entity) { undoHistory.push(std::move(entity)); }
void HistoryManager::AddInRedoHistory(const Entities::Task &entity) { redoHistory.push(std::move(entity)); }
const Entities::Task &HistoryManager::GetUndoTop() const {
    if (undoHistory.empty())
        throw std::out_of_range("Undo history is empty");

    return undoHistory.top();
}
void HistoryManager::PopUndoTop() {
    if (undoHistory.empty())
        throw std::out_of_range("Undo history is empty");

    undoHistory.pop();
}
bool HistoryManager::UndoIsEmpty() const {
    if (undoHistory.empty()) {
        return true;
    }
    return false;
}
const Entities::Task &HistoryManager::GetRedoTop() const {
    if (redoHistory.empty())
        throw std::out_of_range("Redo history is empty");

    return redoHistory.top();
};
void HistoryManager::PopRedoTop() {
    if (redoHistory.empty())
        throw std::out_of_range("Redo history is empty");

    redoHistory.pop();
};
bool HistoryManager::RedoIsEmpty() const {
    if (redoHistory.empty()) {
        return true;
    }
    return false;
};
}  // namespace HistoryManager
