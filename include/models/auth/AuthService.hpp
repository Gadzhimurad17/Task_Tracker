#pragma once
#include "models/auth/ISessionManager.hpp"
namespace Authentication {
class AuthService : public ISessionManager {
private:
    Authentication::ISessionManager &session;

public:
    AuthService(){};
};
}  // namespace Authentication
