#pragma once
#include "models/auth/ISessionManager.hpp"
#include "models/entities/Users.hpp"
#include "models/repository/IRepository.hpp"
#include "models/services/IService.hpp"
#include <iostream>
namespace Services {
class UsersService final : public IService<Entities::Users> {
private:
    Repository::IRepository<Entities::Users> &repository;
    Authentication::ISessionManager &session;

public:
    UsersService(Repository::IRepository<Entities::Users> &repository_) noexcept;
    void Create(const Entities::Users &entity) override;
    void Update(const Entities::Users &entity) override;
    void Remove(unsigned int entity_id) override;
};
}  // namespace Services
