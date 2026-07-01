#include "models/entities/Users.hpp"
namespace Entities {

unsigned int User::GetUserId() const { return this->user_id; }

const std::string &User::GetUsername() const { return this->username; }

const std::string &User::GetEmail() const { return this->email; }

const std::string &User::GetPasswordHash() const { return this->password_hash; }

const std::string &User::GetFirstName() const { return this->first_name; }

const std::string &User::GetLastName() const { return this->last_name; }

const std::string &User::GetSurname() const { return this->surname; }

unsigned int User::GetRoleId() const { return this->role_id; }

bool User::operator==(const User &entity) const {
    return user_id == entity.user_id || username == entity.username || email == entity.username ||
           password_hash == entity.password_hash || first_name == entity.first_name || last_name == entity.last_name ||
           surname == entity.surname || role_id == entity.role_id;
}

bool User::operator!=(const User &entity) const { return !(*this == entity); }
};  // namespace Entities
