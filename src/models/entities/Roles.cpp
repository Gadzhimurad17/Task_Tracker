#include "models/entities/Roles.hpp"
namespace Entities {

Roles::Roles(unsigned int role_id_, std::string &role_name_) : role_id(role_id_), role_name(role_name_){};

unsigned int Roles::GetRoleId() const { return role_id; }

const std::string &Roles::GetRoleName() const { return role_name; }

}  // namespace Entities
