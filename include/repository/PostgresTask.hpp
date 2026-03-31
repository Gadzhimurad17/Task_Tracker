#pragma once
#include "ITaskRepository.hpp"
#include <iostream>
#include <pqxx/pqxx>
#include <memory>
class DatabaseManager : ITaskRepository {
private:
  std::unique_ptr<pqxx::connection> conn;

public:
  DatabaseManager() {
    conn = std::make_unique<pqxx::connection>(
      "host=localhost "
      "port=5432 "
                                              "dbname=tasksinfo "
                                              "user=gadzhimurad "
                                              "password=1961");
  };

  void Add(const Task &task) override;
  Task Get(uint ID) override;
  std::vector<std::unique_ptr<Task>> GetAll() override;
  void Update(const Task &) override;
  void Remove(uint ID) override;
};
