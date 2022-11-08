#include "Tram.h"
#include <iomanip>
#include <sstream>


class Park{
private:
    struct park{
        int number;
    }p;
    Tram* queue;
public:
    Park(){
        p.number = 0;
        queue = nullptr;
    }
    Park(int number){
        p.number = number;
        queue = nullptr;
    }
    ~Park(){
        Tram* temp;
        while(queue != nullptr){
            temp = queue;
            queue = queue->GetNext();
            delete(temp);
        }
    }
    bool isEmpty(){return queue == nullptr;}
    
    bool Add(string brand,int year){
        if(year > 1960){
            Tram* current = queue,* temp = new Tram(brand,year);
            if(isEmpty()) queue = temp;
            else{
                while(current->GetNext() != nullptr) current = current->GetNext();
                current->SetNext(temp);
            } 
            return true;
        }
        return false;
    }
    
    bool Del(){
        Tram* temp = queue;
        queue = queue->GetNext();
        delete(temp);
        return true;
    }

    bool Find(string brand){
        Tram* current = queue;
        while(current != nullptr){
            if(current->GetBrand() == brand) return true;
            current = current->GetNext();
        }
        return false;
    }

    void Show() {
		if (!isEmpty()) {
			Tram* current = queue;
			while (current != nullptr) {
				if (current != queue) cout << "|" << setw(16) << "|";
				cout << setw(13) << current->GetBrand() << setw(8) << " " << setw(10) << current->GetYear();
				if (current->GetNext() != nullptr) cout << "\n";
                current = current->GetNext();
			}
		}
	}

    string getString()
	{
		string str = "";
		if (!isEmpty())
		{
			Tram* current = queue;
			while (current != nullptr){
				stringstream ss;
				str += " " + current->GetBrand();
                ss << current->GetYear();
				str += " " + ss.str();
				current = current->GetNext();
			} 
		}
		return str;
	}

    int GetNumber(){return p.number;}
    void SetNumber(int number){p.number = number;}
    Tram* GetQueue(){return queue;}
    void SetQueue(Tram* queue){this->queue = queue;}
};