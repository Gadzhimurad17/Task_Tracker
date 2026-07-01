#include "models/auth/SessionManager.hpp"
namespace Authentication {
void SessionManager::StartSession(const Entities::User &user) { currentUser = user; }
void SessionManager::EndSession() {}
bool SessionManager::IsLoggedIn() const {}
std::optional<Entities::User> SessionManager::GetCurrentUser() const {}
}  // namespace Authentication
