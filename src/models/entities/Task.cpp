#include "models/entities/Task.hpp"

namespace Entities {

Task::Task(const unsigned int task_id_, const std::string &task_name_, const Priority &priority_, const Status &status_,
           const std::string &description_, unsigned int created_by_, unsigned int assigned_to_,
           const std::string &deadline_)
    : task_id(task_id_), status(status_), task_name(task_name_), priority(priority_), description(description_),
      created_by(created_by_), assigned_to(assigned_to_), deadline(deadline_) {}

Task::Task(const Task &other)
    : task_id(other.task_id), task_name(other.task_name), priority(other.priority), status(other.status),
      description(other.description), created_by(other.created_by), assigned_to(other.assigned_to),
      deadline(other.deadline) {}

Task &Task::operator=(const Task &other) {
    if (this == &other)
        return *this;

    task_id = other.task_id;
    task_name = other.task_name;
    priority = other.priority;
    status = other.status;
    description = other.description;
    created_by = other.created_by;
    assigned_to = other.assigned_to;
    deadline = other.deadline;

    return *this;
}

Task &Task::operator=(Task &&other) noexcept {
    if (this == &other)
        return *this;

    std::swap(task_id, other.task_id);
    std::swap(task_name, other.task_name);
    std::swap(priority, other.priority);
    std::swap(status, other.status);
    std::swap(description, other.description);
    std::swap(created_by, other.created_by);
    std::swap(assigned_to, other.assigned_to);
    std::swap(deadline, other.deadline);

    return *this;
}

Task::Task(Task &&other) noexcept
    : task_id(other.task_id), task_name(other.task_name), priority(other.priority), status(other.status),
      description(other.description), created_by(other.created_by), assigned_to(other.assigned_to),
      deadline(other.deadline) {
    other.task_id = 0;
}

unsigned int Task::GetTaskId() const { return task_id; }
Status Task::GetStatus() const { return this->status; }

const std::string Task::GetTaskName() const { return this->task_name; }
Priority Task::GetPriority() const { return this->priority; }

const std::string &Task::GetDescription() const { return this->description; }
unsigned int Task::GetCreatedBy() const { return this->created_by; }

unsigned int Task::GetAssignedTo() const { return this->assigned_to; }
const std::string &Task::GetDeadline() const { return this->deadline; }

std::string Task::PriorityToString(Priority p) {
    switch (p) {
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

std::string Task::StatusToString(Status s) {
    switch (s) {
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
Status Task::StringToStatus(std::string_view queryResult) {
    if (queryResult == "completed") {
        return Status::completed;
    } else if (queryResult == "created") {
        return Status::created;
    } else if (queryResult == "in_progress") {
        return Status::in_progress;
    } else if (queryResult == "in_review") {
        return Status::in_review;
    } else if (queryResult == "rejected") {
        return Status::rejected;
    }
    return Status::created;
}

Priority Task::StringToPriority(std::string_view queryResult) {
    if (queryResult == "low") {
        return Priority::low;
    } else if (queryResult == "medium") {
        return Priority::medium;
    } else if (queryResult == "high") {
        return Priority::high;
    } else if (queryResult == "critical") {
        return Priority::critical;
    }
    return Priority::low;
}

bool Task::operator==(const Task &entity) const {
    return task_id == entity.task_id && task_name == entity.task_name && priority == entity.priority &&
           status == entity.status && description == entity.description && created_by == entity.created_by &&
           assigned_to == entity.assigned_to && deadline == entity.deadline;
}

bool Task::operator!=(const Task &entity) const { return !(*this == entity); }
}  // namespace Entities
