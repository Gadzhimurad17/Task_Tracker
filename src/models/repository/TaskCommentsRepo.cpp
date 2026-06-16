#include "models/repository/TaskCommentsRepo.hpp"
namespace Repository {

TaskCommentsRepo::TaskCommentsRepo(DatabaseManager &db_) : db(db_) {}

void TaskCommentsRepo::Create(const Entities::TaskComments &entity) {
    pqxx::work txn(db.GetConn());

    const std::string query = R"(
            INSERT INTO task_comments
            (comment_id,task_id,user_id,comment_text)
            VALUES ($1, $2, $3, $4);
        )";

    txn.exec_params(query, entity.GetCommentId(), entity.GetTaskId(), entity.GetUserId(), entity.GetCommentText());
    txn.commit();
}

void TaskCommentsRepo::Update(const Entities::TaskComments &entity) {
    pqxx::work txn(db.GetConn());

    const std::string query = R"(
            UPDATE task_comments
            SET comment_id=$1,task_id=$2,user_id=$3,comment_text=$4;
        )";

    txn.exec_params(query, entity.GetCommentId(), entity.GetTaskId(), entity.GetUserId(), entity.GetCommentText());
    txn.commit();
}

void TaskCommentsRepo::Remove(unsigned int entity_id) {
    pqxx::work txn(db.GetConn());

    const std::string query = R"(
            DELETE FROM task_comments
            WHERE comment_id=$1
        )";

    txn.exec_params(query, entity_id);
    txn.commit();
}
}  // namespace Repository
