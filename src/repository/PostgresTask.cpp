// #include "../../include/repository/PostgresTask.hpp"
// #include <string>
// #include <iostream>
// #include "../../include/TaskManager.hpp"
// TaskRepo
// void DatabaseManager::Add(const Task &task) {
//     try {
//         pqxx::work tx(*conn);

//         std::string query =
//             "INSERT INTO tasks (title, priority, status) "
//             "VALUES ($1, $2, $3)";

//         tx.exec_params(query,
//                        task.GetTitle(),
//                        task.GetPriority(),
//                        task.GetStatus()
//         );

//         tx.commit();

//     }
//     catch (const std::exception& e) {
//         std::cout << "Ошибка связи с БД: " << e.what() << std::endl;
//         throw;
//     }
// }
// Task DatabaseManager::Get(uint ID){
//     try{
//         pqxx::work tx(*conn);
//         const std::string query=
//                     "SELECT * "
//                     "FROM tasks "
//                     "WHERE ID=$1 LIMTI 1";

//         const pqxx::result r=tx.exec_params(query,ID);
//         const Status status=static_cast<Status>(
//             r[0]["status"].as<int>()
//         );

//         const Priority priority=static_cast<Priority>(
//             r[0]["priority"].as<int>()
//         );

//         const std::string title=r[0]["title"].as<std::string>();
//         Task task(
//             status,
//             title,
//             priority
//         );

//         return task;
//     }
//     catch(const std::exception& e){
//         std::cout<<"Ошибка связи с БД:"<<e.what()<<std::endl;
//         throw;
//     }
// };
// std::vector<std::unique_ptr<Task>> DatabaseManager::GetAll(){
//     std::vector<std::unique_ptr<Task>> tasks;
//     try{
//         pqxx::work tx(*conn);
//         const std::string query = R"(
//             SELECT
//             FROM ;
//         )";
//         const pqxx::result result =tx.exec(query);
//         for (const auto& r:result){
//             uint id = r["id"].as<int>();
//             const Status status=static_cast<Status>(r["status"].as<int>());

//             const Priority priority=static_cast<Priority>(
//                 r["priority"].as<int>()
//             );
//             const std::string title=r["title"].as<std::string>();
//             Task task(
//                 status,
//                 title,
//                 priority
//             );
//             tasks.push_back(std::make_unique<Task>(task));
//         }
//     }
//     catch(const std::exception& e){
//         std::cout<<"Ошибка связи с БД:"<<e.what()<<std::endl;
//         throw;
//     }
//     return tasks;
// }
// void DatabaseManager::Update(const Task& task){
//     try{
//         pqxx::work tx(*conn);
//         const std::string query=
//         R"(UPDATE
//             SET
//             WHERE
//         )";
//         tx.exec_params(query,

//         );
//     }
//     catch(const std::exception& e){
//         std::cout<<"Ошибка связи с БД:"<<e.what()<<std::endl;
//         throw;
//     }
// }
// void DatabaseManager::Remove(uint ID){
//     try{
//         pqxx::work tx(*conn);
//     }
//     catch(const std::exception()& e){

//     }
// }
