#pragma once
#include "models/entities/User.hpp"
#include <optional>

namespace Authentication {

class ISessionManager {
public:
    virtual ~ISessionManager() = default;

    virtual void StartSession(const Entities::User &user) = 0;
    virtual void EndSession() = 0;
    virtual bool IsLoggedIn() const = 0;
    virtual std::optional<Entities::User> GetCurrentUser() const = 0;
};

}  // namespace Authentication
