#pragma once
namespace Services {

template <typename T> class IService {
public:
    virtual ~IService(){};

    virtual void Create(const T &entity) = 0;
    virtual void Update(const T &entity) = 0;
    virtual void Remove(unsigned int entity_id) = 0;

    virtual void Undo() = 0;
    virtual void Redo() = 0;
};
}  // namespace Services
