#pragma once
#include "../Task.hpp"
#include <vector>
#include <memory>

class ITaskRepository {
public:
    virtual ~ITaskRepository() = default;

    virtual void Add(const Task& task) = 0;
    virtual Task Get(uint ID) = 0;
    virtual std::vector<std::unique_ptr<Task>> GetAll() = 0;
    virtual void Update(const Task& task) = 0;
    virtual void Remove(uint ID) = 0;

};
