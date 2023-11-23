#include <iostream>

using namespace std;

class Critter
{
public:  
  Critter(int hunger = 0, int boremood = 0);
  void Eat(int food = 4);
  void Play(int playing = 4);
  void Listen();
private:
  int m_hunger, m_boremood;
  void Pass_time(int time = 1);
  int Get_mood() const;
};

Critter::Critter(int hunger, int boremood) : m_hunger(hunger), m_boremood(boremood)
{}

int Critter::Get_mood() const
{
  return (m_hunger + m_boremood);
}

void Critter::Pass_time(int time)
{
  m_hunger += time;
  m_boremood += time;
}

void Critter::Listen()
{
  cout << "I'm а critter and I feel ";
  int mood = Get_mood();
  if (mood > 15)
  {
    cout << "mad\n";
  }
  else if (mood > 10)
  {
    cout << "frustrated\n";
  }
  else if (mood > 5)
  {
    cout << "Okay\n";
  }
  else
  {
    cout << "Over the moon!\n";
  }
Pass_time();
}

void Critter::Play(int playing)
{
  cout << "Woaa!\n";
  m_boremood -= playing;
  if (m_boremood < 0)
  {
    m_boremood = 0;
  }
  Pass_time();
}

void Critter::Eat(int food)
{
  cout << "AM!\n";
  m_hungry -= food;
  if( m_hungry < 0)
  {
    m_hungry = 0;
  }
  Pass_time();
}

int main()
{
  Critter crit;
  crit.Listen();
  int choice;
  do
    {
      cout << "Instruction:\n";
      cout << "0 - Quit the game\n";
      cout << "1 - Play with ur Critter\n";
      cout << "2 - Feed  u Critter\n";
      cout << "3 - Listen to u Critter\n";
      cout << "Choice --- ";
      cin >> choice;
      switch(choice)
        {
          case 0:
            cout << "Bye-Bye!\n";
            break;
          case 1:
            crit.Play();
            break;
          case 2:
            crit.Eat();
            break;
          case 3:
            crit.Listen();
            break;
          default:
            cout << "What?         (-_-)\n";
            cout << "U seriosly? :(-----):\n";
        }
    }while(choice != 0);
    return 0;
}

