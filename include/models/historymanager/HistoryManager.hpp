#pragma once
#include "models/entities/Task.hpp"
#include "models/historymanager/IHistoryManager.hpp"
#include <iostream>
#include <memory>
#include <stack>

namespace HistoryManager {

class HistoryManager final : public IHistoryManager<Entities::Task> {
    std::stack<Entities::Task> undoHistory;
    std::stack<Entities::Task> redoHistory;

public:
    HistoryManager(std::stack<Entities::Task> &uH, std::stack<Entities::Task> &rH)
        : undoHistory(std::move(uH)), redoHistory(std::move(rH)){};

    void AddInUndoHistory(const Entities::Task &entity) override;
    const Entities::Task &GetUndoTop() const override;
    void PopUndoTop() override;
    bool UndoIsEmpty() const override;

    void AddInRedoHistory(const Entities::Task &entity) override;
    const Entities::Task &GetRedoTop() const override;
    void PopRedoTop() override;
    bool RedoIsEmpty() const override;
};

}  // namespace HistoryManager
