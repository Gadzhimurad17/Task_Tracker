#include "models/services/TaskService.hpp"
namespace Services {
TaskService::TaskService(HistoryManager::IHistoryManager<Entities::Task> &historyManager_,
                         Repository::IRepository<Entities::Task> &repository_) noexcept
    : historyManager(historyManager_), repository(repository_) {}

void TaskService::Create(const Entities::Task &entity) {
    historyManager.AddInUndoHistory(entity);
    repository.Create(entity);
}

void TaskService::Update(const Entities::Task &entity) {
    if (repository.Get(entity.GetTaskId()) != historyManager.GetUndoTop()) {

        historyManager.AddInUndoHistory(repository.Get(entity.GetTaskId()).value());
        repository.Update(entity);

    } else {
        repository.Update(entity);
    }
}
void TaskService::Undo() {
    if (historyManager.UndoIsEmpty()) {
        std::cerr << "История пуста" << std::endl;
    }

    const Entities::Task &&task = std::move(historyManager.GetUndoTop());
    historyManager.AddInRedoHistory(repository.Get(task.GetTaskId()).value());
    repository.Update(task);
    historyManager.PopUndoTop();
}
void TaskService::Redo() {
    if (historyManager.RedoIsEmpty()) {
        std::cerr << "История пуста" << std::endl;
    }
    const Entities::Task &&task = std::move(historyManager.GetRedoTop());
    // historyManager.AddInRedoHistory(repository.Get(task.GetTaskId()).value());
    repository.Update(task);
    historyManager.PopRedoTop();
}

void TaskService::Remove(unsigned int entity_id) { repository.Remove(entity_id); }
}  // namespace Services
