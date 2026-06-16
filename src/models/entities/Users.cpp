#include "models/entities/Users.hpp"
namespace Entities {

unsigned int Users::GetUserId() const { return this->user_id; }

const std::string &Users::GetUsername() const { return this->username; }

const std::string &Users::GetEmail() const { return this->email; }

const std::string &Users::GetPasswordHash() const { return this->password_hash; }

const std::string &Users::GetFirstName() const { return this->first_name; }

const std::string &Users::GetLastName() const { return this->last_name; }

const std::string &Users::GetSurname() const { return this->surname; }

unsigned int Users::GetRoleId() const { return this->role_id; }

};  // namespace Entities
