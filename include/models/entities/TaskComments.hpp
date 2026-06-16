#pragma once
#include <string>
namespace Entities {
class TaskComments {
private:
    unsigned int comment_id;
    unsigned int task_id;
    unsigned int user_id;
    std::string &comment_text;

public:
    TaskComments(unsigned int comment_id_l,unsigned int task_id_,
                 unsigned int user_id_,std::string &comment_text_);

    unsigned int GetCommentId() const;
    unsigned int GetTaskId() const;
    unsigned int GetUserId() const;
    std::string &GetCommentText() const;
};
}  // namespace Entities
