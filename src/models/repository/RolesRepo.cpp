#include "models/repository/RolesRepo.hpp"
#include <iostream>

namespace Repository
{
void RolesRepo::Create(const Entities::Roles &entity)
{
    try
    {
        pqxx::work txn(conn);
        std::string query = R"(
            INSERT INTO Roles
            VALUES ($1,$2);
        )";
        txn.exec_params(query, entity.GetRoleId(), entity.GetRoleName());
        txn.commit();
    }
    catch (const pqxx::sql_error &e)
    {
        throw std::runtime_error("Ошибка добавления проекта: " + std::string(e.what()));
    }
}

void RolesRepo::Update(const Entities::Roles &entity)
{
    try
    {
        pqxx::work txn(conn);

        const std::string query = R"(
            UPDATE projects SET
                project_name=$1,description=$2
                WHERE project_id=$3
        )";
        txn.exec_params(query, entity.GetRoleName(), entity.GetRoleId());
        txn.commit();
    }
    catch (const pqxx::sql_error &e)
    {
        throw std::runtime_error("Ошибка изменения роли: " + std::string(e.what()));
    }
}

void RolesRepo::Remove(unsigned int entity_id)
{
    try
    {
        pqxx::work txn(conn);

        const std::string query = R"(
            DELETE FROM projects
            WHERE role_id=$1
        )";

        txn.exec_params(query, entity_id);
        txn.commit();
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error("Ошибка удаления роли: " + std::string(e.what()));
    }
}
} // namespace Repository
