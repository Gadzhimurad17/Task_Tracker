#include "models/entities/Task.hpp"

namespace Entities
{

Task::Task(const Status &status_, const std::string &title_, const Priority &priority_,
           const std::string &description_, unsigned int created_by_, unsigned int assigned_to_,
           const std::string &deadline_)
    : status(status_), title(title_), priority(priority_), description(description_),
      created_by(created_by_), assigned_to(assigned_to_), deadline(deadline_)
{
    task_id = ++counter;
}

Task::Task(const Task &other)
    : task_id(other.task_id), status(other.status), title(other.title), priority(other.priority),
      description(other.description), created_by(other.created_by), assigned_to(other.assigned_to),
      deadline(other.deadline)
{
}

Task &Task::operator=(const Task &other)
{
    if (this == &other)
        return *this;

    task_id = other.task_id;
    status = other.status;
    title = other.title;
    priority = other.priority;
    description = other.description;
    created_by = other.created_by;
    assigned_to = other.assigned_to;
    deadline = other.deadline;

    return *this;
}

Task &Task::operator=(Task &&other) noexcept
{
    if (this == &other)
        return *this;

    std::swap(task_id, other.task_id);
    std::swap(status, other.status);
    std::swap(title, other.title);
    std::swap(priority, other.priority);
    std::swap(description, other.description);
    std::swap(created_by, other.created_by);
    std::swap(assigned_to, other.assigned_to);
    std::swap(deadline, other.deadline);

    return *this;
}

Task::Task(Task &&other) noexcept
    : task_id(other.task_id), status(other.status), title(other.title), priority(other.priority),
      description(other.description), created_by(other.created_by), assigned_to(other.assigned_to),
      deadline(other.deadline)
{
    other.task_id = 0;
}

unsigned int Task::GetTaskId() const
{
    return task_id;
}
Status Task::GetStatus() const
{
    return this->status;
}
const std::string Task::GetTitle() const
{
    return this->title;
}
Priority Task::GetPriority() const
{
    return this->priority;
}
const std::string &Task::GetDescription() const
{
    return this->description;
}
unsigned int Task::GetCreatedBy() const
{
    return this->created_by;
}
unsigned int Task::GetAssignedTo() const
{
    return this->assigned_to;
}
const std::string &Task::GetDeadline() const
{
    return this->deadline;
}
std::string Task::PriorityToString(Priority p)
{
    switch (p)
    {
    case Priority::critical:
        return "critical";
    case Priority::high:
        return "high";
    case Priority::medium:
        return "medium";
    case Priority::low:
        return "low";
    }
    return "Unknown";
}

std::string Task::StatusToString(Status s)
{
    switch (s)
    {
    case Status::completed:
        return "completed";
    case Status::created:
        return "created";
    case Status::in_progress:
        return "in_progress";
    case Status::in_review:
        return "in_review";
    case Status::rejected:
        return "rejected";
    }
    return "Unknown";
}
unsigned int Task::counter = 0;

} // namespace Entities
