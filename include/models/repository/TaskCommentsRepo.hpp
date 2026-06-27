#pragma once
#include "models/entities/TaskComments.hpp"
#include "models/repository/DatabaseManager.hpp"
#include "models/repository/IRepository.hpp"

namespace Repository {

class TaskCommentsRepo : public IRepository<Entities::TaskComments> {
private:
    DatabaseManager &db;

public:
    TaskCommentsRepo(DatabaseManager &db_);
    void Create(const Entities::TaskComments &entity) const override;
    void Update(const Entities::TaskComments &entity) override;
    void Remove(unsigned int entity_id) override;
};

}  // namespace Repository
