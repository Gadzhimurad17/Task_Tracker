#pragma once
#include <string>

namespace Authentication {

struct PasswordHash {
public:
    PasswordHash() = delete;

    static std::string generate(const std::string &password);

    static bool verify(const std::string &hash, const std::string &password);
};

}  // namespace Authentication
