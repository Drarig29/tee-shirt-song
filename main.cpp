#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Concept : public std::string
{
public:
	Concept() : std::string() {}
	Concept(std::string name) : std::string(name) {}

	operator bool() { return !this->empty(); }

	Concept operator=(const Concept &value)
	{
		Concept assigned = value.compare("undefined") == 0 ? !*this : *this;

		if (this->compare("below") == 0)
			cout << value << " " << assigned << " us" << endl;

		if (this->compare("above") == 0)
			cout << assigned << " us, only " << value << endl;

		if (this->compare("religion") == 0)
			cout << "And " << assigned << " too" << endl;

		return value;
	}

	Concept operator==(const char *value)
	{
		cout << "It's " << value << " if you try" << endl;
		return Concept(value);
	}

	Concept operator!=(const char *value)
	{
		cout << "It isn't " << value << " to do" << endl;
		return Concept(value);
	}

	Concept operator!() { return Concept("no " + *this); }
	Concept operator||(const Concept &other) { return Concept(*this + " or " + other); }
};

class Population : Concept
{
public:
	Concept below;
	Concept above;

	Population(std::string name) : Concept(name), below("below"), above("above") {}

	template <typename Func>
	void reduce(Func f) {
		Concept symbol = Concept(std::string(f()).compare("brothers") == 0 ? "brotherhood" : "");
		Concept subject = Concept(this->compare("men") == 0 ? "man" : "");
		cout << "A " << symbol << " of " << subject << endl;
	}
};

Concept imagine(Concept possibility)
{
	cout << "Imagine ";

	if (possibility.compare("no heaven") == 0 || possibility.compare("no countries") == 0)
		cout << "there's " << possibility;
	else
		cout << possibility;

	cout << endl;

	if (possibility.compare("no possessions") == 0) 
		cout << "I wonder if you can" << endl;

	return Concept();
}

bool need(Concept concepts)
{
	bool needed = false;

	if (!needed)
		cout << "No need for " << concepts << endl;

	return needed;
}

void imagineAll(std::string action)
{
	cout << "Imagine all the people" << endl
		 << action << endl
		 << endl;
}

int chorus_number = 0;

void chorus()
{
	cout << "You may say I'm a dreamer" << endl
		 << "But I'm not the only one" << endl
		 << "I hope someday you'll join us" << endl
		 << "And the world will " << (++chorus_number == 1 ? "be" : "live") << " as one" << endl
		 << endl;
}

class Reasons
{
public:
	int length;
};

class Action : Concept
{
public:
	Reasons reasons;

	Action(std::string name) : Concept(name) {}

	Action operator||(const Action &other)
	{
		if (this->reasons.length + other.reasons.length == 0)
		{
			cout << "Nothing to " << *this << " or " << other << " for" << endl;
		}

		return *this;
	}
};

#define Declare(Type, name) Type name(#name)
#define DeclareConcept(name) Declare(Concept, name)
#define DeclarePopulation(name) Declare(Population, name)
#define DeclareAction(name) Declare(Action, name)

DeclareConcept(heaven);
DeclareConcept(hell);
DeclareConcept(sky);
DeclareConcept(countries);
DeclareConcept(religion);
DeclareConcept(possessions);
DeclareConcept(greed);
DeclareConcept(hunger);
DeclareConcept(undefined);

// TODO: make a reference to the population in the concepts, to be able to un-hardcode `us`
// TODO: same for Action and Reason?
// TODO: mark verses and chorus
// TODO: remove using namespace std

DeclarePopulation(us);
DeclarePopulation(men);

DeclareAction(kill);
DeclareAction(die);

int main(int argc, char const *argv[])
{
	/**
	 * Guess the song... 😌 😎
	 */

	imagine(!heaven) == "easy";
	us.below = !hell;
	us.above = sky;
	imagineAll("living for today");

	imagine(!countries) != "hard";
	(kill || die).reasons.length == 0;
	religion = undefined;
	imagineAll("living life in peace");

	chorus(); //🎵🎶

	imagine(!possessions) ? "😀" : "😥";
	need(greed || hunger) == false;
	men.reduce([]() { return "brothers"; });
	imagineAll("sharing all the world");

	chorus(); //🎵🎶
}