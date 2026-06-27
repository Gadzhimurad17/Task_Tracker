#include "models/repository/TaskRepo.hpp"
namespace Repository {

TaskRepo::TaskRepo(DatabaseManager &db_) : db(db_) {}

void TaskRepo::Create(const Entities::Task &entity) const {
    pqxx::work txn(db.GetConn());

    std::string query{R"(
        INSERT INTO tasks
        VALUES($1,$2,$3,$4,$5,$6,$7,$8)
        )"};

    txn.exec_params(query, entity.GetTaskId(), entity.GetTaskName(), entity.StatusToString(entity.GetStatus()),
                    entity.PriorityToString(entity.GetPriority()), entity.GetDescription(), entity.GetCreatedBy(),
                    entity.GetAssignedTo(), entity.GetDeadline());
    txn.commit();
}

void TaskRepo::Update(const Entities::Task &entity) {
    pqxx::work txn(db.GetConn());

    std::string query{R"(
        UPDATE tasks
            SET task_id=$1,task_name=$2,status=$3,priority=$4,description=$5,created_by=$6,assigned_to=$7,deadline=$8
        )"};

    txn.exec_params(query, entity.GetTaskId(), entity.GetTaskName(), entity.StatusToString(entity.GetStatus()),
                    entity.PriorityToString(entity.GetPriority()), entity.GetDescription(), entity.GetCreatedBy(),
                    entity.GetAssignedTo(), entity.GetDeadline());
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
const std::optional<Entities::Task> TaskRepo::Get(unsigned int entity_id) const {
    pqxx::work txn(db.GetConn());
    std::string query{R"(
            SELECT *
            FROM tasks
            WHERE task_id=$1;
        )"};
    pqxx::result result = txn.exec_params(query, entity_id);

    const pqxx::row r = result[0];

    unsigned int task_id = r["task_id"].as<unsigned>();
    std::string task_name = r["task_name"].as<std::string>();

    const Entities::Status status = Entities::Task::StringToStatus(r["status"].as<std::string>());
    const Entities::Priority priority = Entities::Task::StringToPriority(r["priority"].as<std::string>());

    std::string description = r["description"].as<std::string>();
    unsigned int created_by = r["created_by"].as<int>();
    unsigned int assigned_to = r["assigned_to"].as<int>();
    std::string deadline = r["deadline"].as<std::string>();

    return Entities::Task{task_id, task_name, priority, status, description, created_by, assigned_to, deadline};
}

}  // namespace Repository
