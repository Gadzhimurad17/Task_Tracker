#pragma once
#include "models/entities/Projects.hpp"
#include "models/historymanager/IHistoryManager.hpp"
#include "models/services/IService.hpp"
namespace Services {
class ProjectsService final : public Services::IService<Entities::Projects> {
private:
    HistoryManager::IHistoryManager<Entities::Projects> &historyManager;
    Repository::IRepository<Entities::Projects> &repository;

public:
    ProjectsService(HistoryManager::IHistoryManager<Entities::Projects> &historyManager_,
                    Repository::IRepository<Entities::Projects> &repository_) noexcept;
    void Create(const Entities::Projects &entity) override;
    void Update(const Entities::Projects &entity) override;
    void Remove(unsigned int entity_id) override;

    void Undo() override;
    void Redo() override;
};
}  // namespace Services
