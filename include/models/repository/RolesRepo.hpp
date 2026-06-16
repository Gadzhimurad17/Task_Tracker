#pragma once
#include "models/entities/Roles.hpp"
#include "models/repository/DatabaseManager.hpp"
#include "models/repository/IRepository.hpp"
#include <pqxx/pqxx>
namespace Repository {
class RolesRepo : public IRepository<Entities::Roles> {
private:
    DatabaseManager &db;

public:
    RolesRepo(DatabaseManager &db_) : db(db_){};
    void Create(const Entities::Roles &entity) override;
    void Update(const Entities::Roles &entity) override;
    void Remove(unsigned int entity_id) override;
};
}  // namespace Repository
