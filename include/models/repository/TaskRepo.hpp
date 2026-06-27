#pragma once
#include "models/entities/Task.hpp"
#include "models/repository/DatabaseManager.hpp"
#include "models/repository/IRepository.hpp"

#include <string>
namespace Repository {
class TaskRepo : public IRepository<Entities::Task> {
private:
    DatabaseManager &db;

public:
    TaskRepo(DatabaseManager &db_);
    void Create(const Entities::Task &entity) const override;
    void Update(const Entities::Task &entity) override;
    void Remove(unsigned int entity_id) override;
    const std::optional<Entities::Task> Get(unsigned int entity_id) const override;
};
}  // namespace Repository
