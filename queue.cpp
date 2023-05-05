#include <iostream>
using namespace std;


template <typename ElemType>
class queue {

	struct stadium {
		ElemType name;
		ElemType sport;
		ElemType year;
		ElemType add;
		ElemType capacity;
		ElemType fields;
		ElemType tabtype;
		stadium* next = NULL;

	};
	stadium* head = NULL;
	stadium* tail = NULL;
	int size;
public:
	void push(const ElemType&, const ElemType&, const ElemType&, const ElemType&, const ElemType&, const ElemType&, const ElemType&);
	bool pop(ElemType&, ElemType&, ElemType&, ElemType&, ElemType&, ElemType&, ElemType&);
	void change(string name,string info);
};


template <typename ElemType>
void queue<ElemType>::push(const ElemType& name, const ElemType& sport, const ElemType& year, const ElemType& add, const ElemType& capacity, const ElemType& fields, const ElemType& tabtype) {
	stadium* elem = new stadium();

	elem->name = name;
	elem->sport = sport;
	elem->year = year;
	elem->add = add;
	elem->capacity = capacity;
	elem->fields = fields;
	elem->tabtype = tabtype;


	if (head == NULL)
	{
		head = tail = elem;
		
	}
	else 
	{
		tail = tail->next = elem;
		
	}
	size++;
}

template <typename ElemType>
bool queue<ElemType>::pop(ElemType& name,ElemType& sport, ElemType& year,ElemType& add,ElemType& capacity,ElemType& fields,ElemType& tabtype) {
	if (!head)  return false;

	name = head->name;
	sport = head->sport;
	year = head->year;
	add = head->add;
	capacity = head->capacity;
	fields = head->fields;
	tabtype = head->tabtype;
	
	stadium *elem = head;
	head = head->next;
	delete elem;
	return true;
}






template <typename ElemType>
void queue<ElemType>::change(string name, string info) {
	stadium* elem = head;
	
	
	if (name == head->name) {
			head->name = info;
	}

	
}



int main()
{
	queue<string> q;
	string names[3] = { "FIRST", "SECOND", "THIRD"};
	string sports[3] = { "football", "tennis", "basketball" };
	string years[3] = { "1999", "2004", "2018" };
	string adds[3] = { "Russia, Moscow", "USA, NewYork", "UK, London" };
	string capacities[3] = { "100000", "250000", "50000" };
	string field[3] = { "4", "8", "2" };
	string tabtypes[3] = { "digital", "digital", "digital" };


	for(int i = 0; i < 3; i++) {
		q.push(names[i], sports[i], years[i], adds[i], capacities[i], field[i], tabtypes[i]);
	}


	
	string name1 , info;
	cout << "Enter name of a stadium:"; cin >> name1;
	cout << "Enter data:"; cin >> info;
	
	q.change(name1, info);



	string name, sport, year, add, capacity, fields, tabtype;
	while (q.pop(name, sport, year, add, capacity, fields, tabtype))
	{
		cout << "name:" << name << endl;
		cout << "sport:" << sport << endl;
		cout << "year:" << year << endl;
		cout << "add:" << add << endl;
		cout << "capacity:" << capacity << endl;
		cout << "fields:" << fields << endl;
		cout << "tabtype:" << tabtype << endl;
		cout << "\n";
	}

	

}
