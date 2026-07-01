#pragma once
#include "models/auth/ISessionManager.hpp"
#include "models/entities/User.hpp"
#include <optional>
#include <string>
namespace Authentication {
class SessionManager : public ISessionManager {
private:
    std::optional<Entities::User> currentUser;

public:
    SessionManager() = default;
    
    void StartSession(const Entities::User &user) override;
    void EndSession() override;
    bool IsLoggedIn() const override;
    std::optional<Entities::User> GetCurrentUser() const override;
};
}  // namespace Authentication
