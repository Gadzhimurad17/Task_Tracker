#include "models/repository/ProjectsRepo.hpp"
#include <iostream>
#include <string>
namespace Repository {
void ProjectsRepo::Create(const Entities::Projects &entity) const {
    try {
        pqxx::work txn(db.GetConn());

        const std::string query = R"(
            INSERT INTO projects
            (project_id,project_name,description,created_by)
            VALUES ($1, $2, $3, $4);
        )";

        txn.exec_params(query, entity.GetProjectId(), entity.GetProjectName(), entity.GetDescription(),
                        entity.GetCreatedBy());
        txn.commit();
    } catch (const pqxx::sql_error &e) {
        throw std::runtime_error("Ошибка добавления проекта: " + std::string(e.what()));
    }
}
void ProjectsRepo::Update(const Entities::Projects &entity) {
    try {
        pqxx::work txn(db.GetConn());

        const std::string query = R"(
            UPDATE projects SET
                project_name=$1,description=$2
                WHERE project_id=$3
        )";
        txn.exec_params(query, entity.GetProjectName(), entity.GetDescription(), entity.GetProjectId());
        txn.commit();
    } catch (const pqxx::sql_error &e) {
        throw std::runtime_error("Ошибка изменения проекта: " + std::string(e.what()));
    }
}
void ProjectsRepo::Remove(unsigned int entity_id) {
    try {
        pqxx::work txn(db.GetConn());

        const std::string query = R"(
            DELETE FROM projects
            WHERE project_id=$1
        )";

        txn.exec_params(query, entity_id);
        txn.commit();
    } catch (const std::exception &e) {
        throw std::runtime_error("Ошибка удаления проекта: " + std::string(e.what()));
    }
}

}  // namespace Repository
