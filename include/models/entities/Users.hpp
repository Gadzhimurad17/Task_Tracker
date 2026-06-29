#pragma once
#include <string>

namespace Entities {
class Users {
private:
    unsigned int user_id;
    std::string username;
    std::string email;
    std::string password_hash;
    std::string first_name;
    std::string last_name;
    std::string surname;
    unsigned int role_id;

public:
    Users(unsigned int user_id_, const std::string &username_, const std::string &email_,
          const std::string &password_hash_, const std::string &first_name_, const std::string &last_name_,
          const std::string &surname_, unsigned int role_id_)
        : user_id(user_id_), username(username_), email(email_), password_hash(password_hash_), first_name(first_name_),
          last_name(last_name_), surname(surname_), role_id(role_id_){};
    unsigned int GetUserId() const;
    const std::string &GetUsername() const;
    const std::string &GetEmail() const;
    const std::string &GetPasswordHash() const;
    const std::string &GetFirstName() const;
    const std::string &GetLastName() const;
    const std::string &GetSurname() const;
    unsigned int GetRoleId() const;

public:
    bool operator!=(const Users &entity) const;
    bool operator==(const Users &entity) const;
};
}  // namespace Entities
