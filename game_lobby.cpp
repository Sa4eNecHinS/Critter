#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
	Player(const string& name = ""); //создаем коструктор в параметрах которого берем ссылку на символ
	string get_name() const; //создаем функцию типа -стринг- конст,чтобы не могли изменить. Отвечает за вывод имени
	Player* get_next() const; //создаем функцию класса -плейр-,тоже конст,т.к просто  выводим значение следующего(нач = 0)
	void set_next(Player* next); //функция которая присваивает m_p_next = next.т.е отвечает за передачу --очереди--
private:
	string m_name; //просто приватная строка
 	Player* m_p_next; //указатель на класс -плейр-
};

Player::Player(const string& name) : m_name(name), m_p_next(nullptr) //конструктор который говорит m_name возьми значение от name, m_p_next от (nuulptr)
{}

string Player::get_name() const //просто возвращает имя
{
	return m_name;
}

Player* Player::get_next() const //возвращает указатель(0)
{
	return m_p_next;
}

void Player::set_next(Player* next) //передает значение следующему в очереди
{
	m_p_next = next;
}

class Lobby
{
	friend ostream& operator<<(ostream& os, const Lobby& a_lobby);//дружественная функция,котрая перегружает оператор <<. и еще берет значение от ссылки на lobby
public:
	Lobby(); //конструктор
	~Lobby(); //диконструктор
	void add_player(); //функция добавления игрока
	void remove_player(); //функция удаления игрока
	void clear(); //функция очищения лобби
private:
	Player* m_p_head; //указатель - начало очереди
};

Lobby::Lobby() : m_p_head(nullptr) //начало очереди бери значение от 0
{}

Lobby::~Lobby()
{
	clear(); //обращаемся к функции
}

void Lobby::add_player() 
{
	cout << "Enter a name please --- "; //просим ввести имя
	string name; //создаем переменную
	cin >> name; //считываем ее
	Player* p_new_player = new Player(name); //создаем указатель на класс -плейр- для которого выделяем место и берем значение -нейм-
	if (m_p_head == 0) //проверяем а не равно ли наше значение начало очереди 0
	{ 
		m_p_head = p_new_player; //если так то просто присваиваем значение перменной
	}
	else
	{
		Player* p_iter = m_p_head; //создаем еще одну переменную  указатель которая равна началу очереди
		while (p_iter->get_next() != 0) //цикл в котором проверяем на начало очереди не равное 0
		{
			p_iter = p_iter->get_next(); //разыменовываем указатель к функции get_next()
		}
		p_iter->set_next(p_new_player); //передает значение  к следующему в очереди
	}
}

void Lobby::remove_player()
{
	if (m_p_head == 0) //если начало очереди равно 0,нельзя никого убрать
	{
		cout << "NIZA!\n";
	}
	else 
	{
		Player* p_temp = m_p_head; //создаем указатель на класс -плейр- который равен началу очереди
		m_p_head = m_p_head->get_next(); //говорим присвойка значение m_p_head от функции get_next()
		delete p_temp; //удаляем созданный ранее объект
	}
}

void Lobby::clear()
{
	while (m_p_head != 0)
	{
		remove_player(); //обращаемся к функции
	}
}

ostream& operator<<(ostream& os, const Lobby& a_lobby) //перезагружаем оператор << 
{
	Player* p_iter = a_lobby.m_p_head; //создаем указатель класса -плейр- который равен конст ссылку от начала очереди
	os << "\nhere whos in the game lobby:\n"; //выводим текст
	if (p_iter == 0) //проверяем а не равно ли 0
	{
		os << "Lobby is empty\n\n";
	}
	else
	{
		while (p_iter != 0) //создаем цикл пока не равно 0
		{
			os << p_iter->get_name() << endl; //передаем имя
			p_iter = p_iter->get_next(); //передаем значение в -гет некст()-
		}
	}
	return os; //чтобы работал вывод через os << "...";
}

int main()
{
	Lobby my_lobby; //создаем переменную относящуюся к классу лобби
	int choice; //выбор пользователя
	do
	{
		cout << my_lobby; //выводим класс лобби,приводим его в действие
		cout << "INstruction:\n"; //просто текст
		cout << "0 - Exit the game\n";
		cout << "1 - Add the player in lobby\n";
		cout << "2 - Delete player at lobby \n";
		cout << "3 - Clear all lobby\n";
		cout << "\nEnter ur choice --- "; //просим ввести пользователя ответ
		cin >> choice; //считываем ответ
		switch (choice) //обрабатываем ответ пользователя
		{
			case 0: cout << "Bye.Bye!\n"; break;
			case 1: my_lobby.add_player(); break;
			case 2: my_lobby.remove_player(); break;
			case 3: my_lobby.clear(); break;
			default: cout << "NINE, NO NO (-_-)\n";
					 cout << "           (-   -)\n";
		}
	} while (choice != 0); //условие,т.к цикл do
	return 0; 
}

