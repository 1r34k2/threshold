#include "Park.h"
#define SIZE_OF_ARRAY 10

class Trans{
private:
    struct trans{
        string name;
    }t;
    Park list[SIZE_OF_ARRAY];
    int count;
public:
    Trans(){
        t.name = "";
        count = 0;
    }
    Trans(string name){
        t.name = name;
        count = 0;
    }
    ~Trans(){}

    bool isEmpty(){return count == 0;}
    bool isFull(){return count == SIZE_OF_ARRAY;}

    bool Add(int number){
        if(!isFull() && number > 0 && !Find(number)){
            if(isEmpty()) list[0].SetNumber(number);
            else{
                for(int i = 0;i < count;i++){
                    if(list[i].GetNumber() > number){
                        for(int j = count;j > i;j--) list[j] = list[j-1];
                        list[i].SetNumber(number);
                        list[i].SetQueue(nullptr);
                        count++;
                        return true;
                    }
                }
                list[count].SetNumber(number);
            } 
            count++;
            return true;
        }
        return false;
    }

    bool Del(int number){
        if(!isEmpty()){
            for(int i = 0;i < count; i++){
                if(list[i].GetNumber() == number){
                    while(!list[i].isEmpty()) list[i].Del();
                    for(int j = i;j < count;j++) list[j] = list[j+1];
                    while(!list[count-1].isEmpty()) list[count-1].Del();
                    count--;
                    return true;
                }
            }
        }
        return false;
    }

    bool Find(int number){
        if(!isEmpty())
            for(int i = 0;i < count; i++)
                if(list[i].GetNumber() == number) return true;
        return false;
    }

    bool AddQ(int number,string brand,int year){
        if(!isEmpty())
            for(int i = 0;i < count; i++)
                if(list[i].GetNumber() == number) return list[i].Add(brand,year);
        return false;
    }

    bool DelQ(int number){
        if(!isEmpty())
            for(int i = 0;i < count; i++)
                if(list[i].GetNumber() == number) return list[i].Del();
        return false;
    }

    bool FindQ(int number, string brand){
        if(!isEmpty())
            for(int i = 0;i < count; i++)
                if(list[i].GetNumber() == number) return list[i].Find(brand);
        return false;
    }

    void Show() {
		if (!isEmpty()) {
			for(int i=0;i<count;i++) {
				cout << "----------------------------------------------------\n";
				cout << "|" << setw(8) << list[i].GetNumber() << setw(8) << "|";
				list[i].Show();
    			cout << "\n";
	        }
		}
	}

    string getString()
	{
		string str = "";
		for(int i=0;i<count;i++) {
            stringstream ss;
			ss << list[i].GetNumber();
            str += ss.str();
			str += list[i].getString();
			str += '\n';
		} 
		return str;
	}
	void SetName(string name) { t.name = name; }
	string GetName() { return t.name; }
};