#include "../include/TaskManager.hpp"
#include "../include/historymanager/HistoryManager.hpp"
// #include <algorithm>
#include<iostream>
void TaskManager::AddTask(Task& task){
    tasks.push_back(std::move(task));
    historyManager.AddInHistory(task);
}

void TaskManager::Print(const uint ID){
    for(const auto& x:tasks){
        if(ID==x.GetID()){
            std::cout<<x.GetTitle()<<' '<<Task::StatusToString(x.GetStatus())
            <<' '<<Task::PriorityToString(x.GetPriority())<<std::endl;
        }
    }
}

Task& TaskManager::GetTask(const uint ID){
            for(auto& x:tasks){

                if(x.GetID()==ID){
                    return x;
                    break;
                }

            }
            throw std::runtime_error("Task not found");
        }


void TaskManager::RemoveTask(const uint ID){
    std::erase_if(tasks,[ID](const Task& task){
        return task.GetID()==ID;
    });
}

void TaskManager::ChangeStatus(const uint ID,Status&& s){
    Task& task=GetTask(ID);
    historyManager.AddInHistory(task);
    task.SetStatus(s);


}
void TaskManager::ChangePriority(const uint ID,Priority&& p){
    Task& task(GetTask(ID));
    historyManager.AddInHistory(task);
    task.SetPriority(p);
}
void TaskManager::ReturnLastAction(uint ID){
            Task&& task1=std::move(historyManager.tasksHistory.top());
            tasks[ID-1]=task1;
}
