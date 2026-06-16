#include "models/entities/TaskComments.hpp"

namespace Entities {
TaskComments::TaskComments(unsigned int comment_id_, std::string &comment_text_, unsigned int task_id_,
                           unsigned int user_id_) noexcept
    : comment_id(comment_id_), comment_text(comment_text_), task_id(task_id_), user_id(user_id_){};

unsigned int TaskComments::GetCommentId() const { return comment_id; }

std::string &TaskComments::GetProjectName() const { return comment_text; }

unsigned int TaskComments::GetTaskId() const { return task_id; }

unsigned int TaskComments::GetUserId() const { return user_id; }

}  // namespace Entities
