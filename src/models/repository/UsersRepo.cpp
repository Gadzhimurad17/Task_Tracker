#include "models/repository/UsersRepo.hpp"
namespace Repository {
UsersRepo::UsersRepo(DatabaseManager &db_) : db(db_) {}

void UsersRepo::Create(const Entities::Users &entity) const {
    pqxx::work txn(db.GetConn());

    std::string query{R"(
        INSERT INTO users
        VALUES($1,$2,$3,$4,$5,$6,$7,$8)
    )"};

    txn.exec_params(query, entity.GetUserId(), entity.GetUsername(), entity.GetEmail(), entity.GetPasswordHash(),
                    entity.GetFirstName(), entity.GetLastName(), entity.GetSurname(), entity.GetRoleId());
    txn.commit();
}

void UsersRepo::Update(const Entities::Users &entity) {
    pqxx::work txn(db.GetConn());

    std::string query{R"(
        UPDATE users
        SET user_id=$1,username=$2,email=$3,priority=$4,password_hash=$5,first_name=$6,last_name=$7,role_id=$8
    )"};

    txn.exec_params(query, entity.GetUserId(), entity.GetUsername(), entity.GetEmail(), entity.GetPasswordHash(),
                    entity.GetFirstName(), entity.GetLastName(), entity.GetSurname(), entity.GetRoleId());
    txn.commit();
}
void UsersRepo::Remove(unsigned int entity_id) {
    pqxx::work txn(db.GetConn());

    std::string query{R"(
        DELETE FROM users
        WHERE user_id=$1
    )"};

    txn.exec_params(query, entity_id);
    txn.commit();
}
}  // namespace Repository
