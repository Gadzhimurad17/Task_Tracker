#pragma once
#include "models/entities/Roles.hpp"
#include "models/historymanager/IHistoryManager.hpp"
#include "models/services/IService.hpp"
namespace Services {
class RolesService final : public IService<Entities::Roles> {
private:
    Repository::IRepository<Entities::Roles> &repository;

public:
    RolesService(Repository::IRepository<Entities::Roles> &repository_) noexcept;
    void Create(const Entities::Roles &entity) override;
    void Update(const Entities::Roles &entity) override;
    void Remove(unsigned int entity_id) override;
};
}  // namespace Services
