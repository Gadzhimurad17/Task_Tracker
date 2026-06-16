#include "models/entities/Projects.hpp"
namespace Entities
{
Projects::Projects(unsigned int project_id_, const std::string &project_name_,
                            const std::string &descripyion_, unsigned int created_by_) noexcept
    : project_id(project_id_), project_name(project_name_), description(descripyion_),
      created_by(created_by_){};

unsigned int Projects::GetProjectId() const
{
    return project_id;
}

const std::string &Projects::GetProjectName() const
{
    return project_name;
}

const std::string &Projects::GetDescription() const
{
    return description;
}

unsigned int Projects::GetCreatedBy() const
{
    return created_by;
}
} // namespace Entities
