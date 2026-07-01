#include "models/auth/PasswordHash.hpp"
#include <sodium.h>
#include <stdexcept>

namespace Authentication {

std::string PasswordHash::generate(const std::string &password) {
    char hashed_password[crypto_pwhash_STRBYTES];

    if (crypto_pwhash_str(
            hashed_password, password.c_str(), password.length(),
            crypto_pwhash_OPSLIMIT_INTERACTIVE,  // Лимит операций
            crypto_pwhash_MEMLIMIT_INTERACTIVE  // Лимит оперативной памяти
            ) != 0) {
        throw std::runtime_error("Ошибка libsodium: не удалось сгенерировать хеш (нехватка памяти).");
    }

    return std::string(hashed_password);
}

bool PasswordHash::verify(const std::string &hash, const std::string &password) {
    int result = crypto_pwhash_str_verify(hash.c_str(), password.c_str(), password.length());

    return result == 0;
}

}  // namespace Authentication
