#include "models/services/UserService.hpp"
namespace Services {
UserService::UserService(Repository::IRepository<Entities::User> &repository_) noexcept : repository(repository_) {}

void UserService::Create(const Entities::User &entity) { repository.Create(entity); }

void UserService::Update(const Entities::User &entity) { repository.Update(entity); }

void UserService::Remove(unsigned int entity_id) { repository.Remove(entity_id); }

}  // namespace Services
