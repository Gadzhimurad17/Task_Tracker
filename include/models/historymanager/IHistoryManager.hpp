#pragma once
#include "models/repository/IRepository.hpp"
namespace HistoryManager {

template <typename T> class IHistoryManager {
public:
    virtual ~IHistoryManager() {}

    virtual void AddInUndoHistory(const T &entity) = 0;
    virtual const T &GetUndoTop() const = 0;
    virtual bool UndoIsEmpty() const = 0;
    virtual void PopUndoTop() = 0;

    virtual void AddInRedoHistory(const T &entity) = 0;
    virtual const T &GetRedoTop() const = 0;
    virtual bool RedoIsEmpty() const = 0;
    virtual void PopRedoTop() = 0;
};
}  // namespace HistoryManager
