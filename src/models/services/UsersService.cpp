#include "models/services/UsersService.hpp"
namespace Services {
UsersService::UsersService(Repository::IRepository<Entities::Users> &repository_) noexcept : repository(repository_) {}

void UsersService::Create(const Entities::Users &entity) { repository.Create(entity); }

void UsersService::Update(const Entities::Users &entity) { repository.Update(entity); }

void UsersService::Remove(unsigned int entity_id) { repository.Remove(entity_id); }

}  // namespace Services
