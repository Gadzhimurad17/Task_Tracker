#pragma once
#include "models/auth/ISessionManager.hpp"
#include "models/entities/Users.hpp"
#include <optional>
#include <string>
namespace Authentication {
class SessionManager : public ISessionManager {
private:
    std::optional<Entities::Users> currentUser;

public:
    SessionManager() = default;
    void StartSession(const Entities::Users &user) override;
    void EndSession() override;
    bool IsLoggedIn() const override;
    std::optional<Entities::Users> GetCurrentUser() const override;
};
}  // namespace Authentication
