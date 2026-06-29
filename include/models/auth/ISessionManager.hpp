#pragma once
#include "models/entities/Users.hpp"
#include <optional>

namespace Authentication {

class ISessionManager {
public:
    virtual ~ISessionManager() = default;

    virtual void StartSession(const Entities::Users &user) = 0;
    virtual void EndSession() = 0;
    virtual bool IsLoggedIn() const = 0;
    virtual std::optional<Entities::Users> GetCurrentUser() const = 0;
};

}  // namespace Authentication
