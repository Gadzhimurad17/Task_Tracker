#pragma once
#include <string>
namespace Entities {
class TaskComments {
private:
    unsigned int comment_id;
    std::string &comment_text;
    unsigned int task_id;
    unsigned int user_id;

public:
    TaskComments(unsigned int comment_id_l, std::string &comment_text_, unsigned int task_id_,
                 unsigned int user_id_) noexcept;

    unsigned int GetCommentId() const;
    std::string &GetProjectName() const;
    unsigned int GetTaskId() const;
    unsigned int GetUserId() const;
};
}  // namespace Entities
