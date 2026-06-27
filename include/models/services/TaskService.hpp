#pragma once
#include "models/entities/Task.hpp"
#include "models/historymanager/IHistoryManager.hpp"
#include "models/services/IService.hpp"
#include <iostream>

namespace Services {
class TaskService final : public IService<Entities::Task> {
private:
    HistoryManager::IHistoryManager<Entities::Task> &historyManager;
    Repository::IRepository<Entities::Task> &repository;

public:
    TaskService(HistoryManager::IHistoryManager<Entities::Task> &historyManager_,
                Repository::IRepository<Entities::Task> &repository_) noexcept;
    void Create(const Entities::Task &entity) override;
    void Update(const Entities::Task &entity) override;
    void Undo() override;
    void Redo() override;
    // void Remove(unsigned int entity_id) override;
};
}  // namespace Services
