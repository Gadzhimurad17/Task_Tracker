#include "models/repository/DatabaseManager.hpp"

namespace Repository
{
DatabaseManager::DatabaseManager()
{
    conn = std::make_unique<pqxx::connection>(
        "host=localhost port=5439 dbname=task_manager_db user=myuser password=1234 ");
};
pqxx::connection &DatabaseManager::GetConn() const
{
    return *conn;
}
bool DatabaseManager::IsConnected()
{
}
} // namespace Repository
