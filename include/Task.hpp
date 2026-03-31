#pragma once
#include <string>
#include <iostream>
enum class Status{
    created=0,
    in_progress=1,
    in_review=2,
    completed=3,
    rejected=4
};

enum class Priority{
    low = 0,
    medium=1,
    high=2,
    critical=3
};

class Task final{
    private:
        uint ID=0;
        Status status;
        std::string title;
        Priority priority;

    public:
        static uint counter;

        Task(const Status& s,const std::string& t,const Priority& p):
            status(s),
            title(t),
            priority(p)
        {
            this->ID= Task::counter+1;
            Task::counter=Task::counter+1;
            std::cout<<"Вызвался конструктор"<<std::endl;

        };

        Task ( const Task& other):
            ID(counter),
            status(other.status),
            title(other.title),
            priority(other.priority)
        {
            std::cout<<"Вызвался конструктор копирования"<<std::endl;
        };
        Task& operator=(const Task& other){
            this->ID=(counter+1);
            this->status=other.status;
            this->title=other.title;
            this->priority=other.priority;
            return *this;
        }
         Task& operator=(Task&& other) noexcept {
        if (this != &other) {
            ID = other.ID;
            status = other.status;
            title = std::move(other.title);
            priority = other.priority;
        }
        return *this;
    }
        Task(Task&& other) noexcept:
            ID(other.ID),
            status(other.status),
            title(std::move(other.title)),
            priority(other.priority)
        {
        other.title.clear();

        std::cout << "Вызвался конструктор перемещения" << std::endl;
    }

        static std::string StatusToString(Status s);

        static std::string PriorityToString(Priority p);

        uint  GetID()const{return this->ID;}

        Status  GetStatus() const{return this->status;}

        std::string  GetTitle()const{return this->title;}

        Priority  GetPriority()const{return this->priority;}




        void SetStatus(Status s) {this->status=s;}

        void SetTitle(std::string t) {this->title=t;}

        void SetPriority(Priority p) {this->priority=p;}
};
