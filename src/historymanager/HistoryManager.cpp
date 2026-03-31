#include "../../include/historymanager/HistoryManager.hpp"
void HistoryManager::AddInHistory(const Task& task){
    tasksHistory.push(task);
}
