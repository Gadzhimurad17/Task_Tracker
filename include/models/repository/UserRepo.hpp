#pragma once
#include "models/entities/User.hpp"
#include "models/repository/DatabaseManager.hpp"
#include "models/repository/IRepository.hpp"

namespace Repository {
class UserRepo : public IRepository<Entities::User> {
private:
    DatabaseManager &db;

public:
    UserRepo(DatabaseManager &db_);
    void Create(const Entities::User &entity) const override;
    void Update(const Entities::User &entity) override;
    void Remove(unsigned int entity_id) override;
};
}  // namespace Repository
