#pragma once
#include "models/entities/Users.hpp"
#include "models/repository/DatabaseManager.hpp"
#include "models/repository/IRepository.hpp"

namespace Repository {
class UsersRepo : public IRepository<Entities::Users> {
private:
    DatabaseManager &db;

public:
    UsersRepo(DatabaseManager &db_);
    void Create(const Entities::Users &entity) override;
    void Update(const Entities::Users &entity) override;
    void Remove(unsigned int entity_id) override;
};
}  // namespace Repository
