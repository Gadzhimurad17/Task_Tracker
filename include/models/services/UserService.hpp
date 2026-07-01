#pragma once
#include "models/auth/ISessionManager.hpp"
#include "models/entities/User.hpp"
#include "models/repository/IRepository.hpp"
#include "models/services/IService.hpp"
#include <iostream>
namespace Services {
class UserService final : public IService<Entities::User> {
private:
    Repository::IRepository<Entities::User> &repository;
    Authentication::ISessionManager &session;

public:
    UserService(Repository::IRepository<Entities::User> &repository_) noexcept;
    void Create(const Entities::User &entity) override;
    void Update(const Entities::User &entity) override;
    void Remove(unsigned int entity_id) override;
};
}  // namespace Services
