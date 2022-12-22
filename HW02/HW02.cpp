#include <iostream>
#include <string>
#include "station.cpp"
using namespace std;

class Trip {

public:
    Station* header;
    Station* trailer;
    int numStation;
    
    Trip()
    {
        header = new Station;
        trailer = new Station;
        header->next = trailer;
        header->prev = NULL;
        trailer->prev = header;
        trailer->next = NULL;
        numStation = 0;  
    }

    void printList()
    {
        cout << "[ ";
        Station* ptr = header->next;
        while (ptr != trailer) {
            cout << ptr->name << " ";
            ptr = ptr->next;
        }
        cout << "]\n";
    }


    void insert_front(string newItem)
    {
        Station* newStation = new Station();
        newStation->name = newItem;
        newStation->next = header->next;
        newStation->prev = header;
        header->next->prev = newStation;
        header->next = newStation;
        numStation++;
    }
    
    void insert_back(string newItem)
    {
        Station* newStation = new Station();
        newStation->name = newItem;
        newStation->next = trailer;
        newStation->prev = trailer->prev;
        trailer->prev->next = newStation;
        trailer->prev = newStation;
        numStation++;
    }

    void remove_front()
    {
        if(header->next != trailer){
            Station* stationRemove;
            stationRemove = header->next;
            header->next = stationRemove->next;
            stationRemove->prev = header;
            delete stationRemove;
            stationRemove = nullptr;
            numStation--;
        }
    }
    
    void remove_back()
    {
        if(trailer->prev != header){
            Station* stationRemove;
            stationRemove = trailer->prev;
            trailer->prev = stationRemove->prev;
            stationRemove->prev->next = trailer;
            delete stationRemove;
            stationRemove = nullptr;
            numStation--;
        }
    }

    Station* visit(int nStep, string stepText)
    {
        Station* lastStation = header->next;
        for(int i=0;i<nStep;i++){
            if(stepText[i] == 'R'){
                if(lastStation->next->next != NULL){
                    lastStation = lastStation->next;
                }
            }else{
                if(lastStation->prev->prev != NULL){
                    lastStation = lastStation->prev;
                }
            }
        }
        return(lastStation);
    
    }
};