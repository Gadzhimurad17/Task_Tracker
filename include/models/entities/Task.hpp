#pragma once
#include <string>
namespace Entities {

enum class Status { created = 0, in_progress = 1, in_review = 2, completed = 3, rejected = 4 };

enum class Priority { low = 0, medium = 1, high = 2, critical = 3 };

class Task final {
private:
    unsigned int task_id = 0;
    std::string title;
    Status status;
    Priority priority;
    std::string description;
    unsigned int created_by;
    unsigned int assigned_to;
    std::string deadline;

public:
    static unsigned int counter;

    Task(const Status &status_, const std::string &title_, const Priority &priority_, const std::string &description_,
         unsigned int created_by_, unsigned int assigned_to_, const std::string &deadline_);

    Task(const Task &other);

    Task &operator=(const Task &other);

    Task &operator=(Task &&other) noexcept;

    Task(Task &&other) noexcept;

public:
    static std::string StatusToString(Status s);

    static std::string PriorityToString(Priority p);

    unsigned int GetTaskId() const;
    Status GetStatus() const;
    const std::string GetTitle() const;
    Priority GetPriority() const;
    const std::string &GetDescription() const;
    unsigned int GetCreatedBy() const;
    unsigned int GetAssignedTo() const;
    const std::string &GetDeadline() const;

    void SetStatus(Status s) { this->status = s; }

    void SetTitle(std::string t) { this->title = t; }

    void SetPriority(Priority p) { this->priority = p; }
};
}  // namespace Entities
