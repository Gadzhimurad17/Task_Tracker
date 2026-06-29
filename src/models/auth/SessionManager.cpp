#include "models/auth/SessionManager.hpp"
namespace Authentication {
void SessionManager::StartSession(const Entities::Users &user) {
    
}
void SessionManager::EndSession() {}
bool SessionManager::IsLoggedIn() const {}
std::optional<Entities::Users> SessionManager::GetCurrentUser() const {}
}  // namespace Authentication
