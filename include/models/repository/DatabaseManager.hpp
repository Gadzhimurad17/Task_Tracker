#pragma once
#include <memory>
#include <pqxx/pqxx>
namespace Repository
{
class DatabaseManager
{
  private:
    std::unique_ptr<pqxx::connection> conn;

  public:
    DatabaseManager();
    pqxx::connection &GetConn() const;
    bool IsConnected();
};
} // namespace Repository
