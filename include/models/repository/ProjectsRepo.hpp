#pragma once
#include "models/entities/Projects.hpp"
#include "models/repository/DatabaseManager.hpp"
#include "models/repository/IRepository.hpp"
#include <pqxx/pqxx>
namespace Repository
{
class ProjectsRepo : public IRepository<Entities::Projects>
{
  private:
    DatabaseManager &db;

  public:
    ProjectsRepo(DatabaseManager &db_) : db(db_){};
    void Create(const Entities::Projects &entity) override;
    // Entities::Projects Find(unsigned int entity_id) override;
    void Update(const Entities::Projects &entity) override;
    void Remove(unsigned int entity_id) override;
};
} // namespace Repository
