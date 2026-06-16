#pragma once
#include <string>
namespace Entities
{
class Roles
{
  private:
    unsigned int role_id;
    std::string role_name;

  public:
    explicit Roles(unsigned int role_id_, std::string &role_name_);
    unsigned int GetRoleId() const;
    const std::string &GetRoleName() const;
};
} // namespace Entities
