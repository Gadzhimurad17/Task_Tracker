#include "models/repository/TaskRepo.hpp"
namespace Repository {

TaskRepo::TaskRepo(DatabaseManager &db_) : db(db_) {}

void TaskRepo::Create(const Entities::Task &entity) {
    pqxx::work txn(db.GetConn());

    std::string query{R"(
        INSERT INTO tasks
        VALUES($1,$2,$3,$4,$5,$6,$7,$8)
        )"};

    txn.exec_params(query, entity.GetTaskId(), entity.GetTaskName(), entity.GetStatus(), entity.GetPriority(),
                    entity.GetDescription(), entity.GetCreatedBy(), entity.GetAssignedTo(), entity.GetDeadline());
    txn.commit();
}

void TaskRepo::Update(const Entities::Task &entity) {
    pqxx::work txn(db.GetConn());

    std::string query{R"(
        UPDATE tasks
        SET task_id=$1,task_name=$2,status=$3,priority=$4,description=$5,created_by=$6,assigned_to=$7,deadline=$8
        )"};

    txn.exec_params(query, entity.GetTaskId(), entity.GetTaskName(), entity.GetStatus(), entity.GetPriority(),
                    entity.GetDescription(), entity.GetCreatedBy(), entity.GetAssignedTo(), entity.GetDeadline());
    txn.commit();
}

void TaskRepo::Remove(unsigned int entity_id) {
    pqxx::work txn(db.GetConn());
    std::string query{R"(
        DELETE FROM tasks
            WHERE task_id=$1
        )"};

    txn.exec_params(query, entity_id);
    txn.commit();
}
}  // namespace Repository
