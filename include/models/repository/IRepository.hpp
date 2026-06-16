#pragma once
namespace Repository {
template <typename T> class IRepository {
public:
    virtual ~IRepository(){};

    virtual void Create(const T &entity) = 0;
    // virtual T Find(unsigned int entity_id) = 0;
    virtual void Update(const T &entity) = 0;
    virtual void Remove(unsigned int entity_id) = 0;
};
}  // namespace Repository
