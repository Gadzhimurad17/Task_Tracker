#include "models/historymanager/HistoryManager.hpp"

namespace Entities {

void HistoryManager::AddInUndo(const Task &task) { undoHistory.push(task); }
void HistoryManager::AddInRedo(const Task &task) { redoHistory.push(task); }
}  // namespace Entities
