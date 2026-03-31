#include "../include/Task.hpp"
std::string Task::StatusToString(Status s){
    switch (s) {
        case Status::completed :return "completed";
        case Status::created : return "created";
        case Status::in_progress: return "in_progress";
        case Status::in_review : return "in_review";
        case Status::rejected : return "rejected";
    }
    return "Unknown";
}
uint Task::counter=0;
std::string Task::PriorityToString(Priority p){
    switch(p){
        case Priority::critical :return "critical";
        case Priority::high : return "high";
        case Priority::low : return "low";
        case Priority::medium : return "medium";
    }
    return "Uknown";
}
