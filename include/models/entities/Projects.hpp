#pragma once
#include <string>

namespace Entities {
class Projects {
private:
    unsigned int project_id;
    const std::string project_name;
    const std::string description;
    unsigned int created_by;

public:
    explicit Projects(unsigned int project_id_, const std::string &project_name_, const std::string &descripyion_,
                      unsigned int created_by_) noexcept;

    unsigned int GetProjectId() const;
    const std::string &GetProjectName() const;
    const std::string &GetDescription() const;
    unsigned int GetCreatedBy() const;
};
}  // namespace Entities
