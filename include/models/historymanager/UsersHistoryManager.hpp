#pragma once
#include "models/entities/Users.hpp"
#include "models/historymanager/IHistoryManager.hpp"
#include <stack>
namespace HistoryManager {
class UsersHistoryManager final : public IHistoryManager<Entities::Users> {
    std::stack<Entities::Users> undoHistory;
    std::stack<Entities::Users> redoHistory;

public:
    
};
}  // namespace HistoryManager
