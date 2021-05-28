#include <iostream>
#include <string>
#include <vector>

int chorus_counter = 0;
int verse_counter = 0;

class Concept : public std::string
{
private:
	Concept *parent;

public:
	Concept() : std::string() {}
	Concept(std::string name) : std::string(name) {}
	Concept(std::string name, Concept *parent) : std::string(name), parent(parent) {}

	operator bool() { return !this->empty(); }

	Concept operator=(const Concept &value)
	{
		Concept assigned = value.compare("undefined") == 0 ? !*this : *this;

		if (this->compare("below") == 0)
			std::cout << value << " " << assigned << " " << *parent << std::endl;

		if (this->compare("above") == 0)
			std::cout << assigned << " " << *parent << ", only " << value << std::endl;

		if (this->compare("religion") == 0)
			std::cout << "And " << assigned << " too" << std::endl;

		return value;
	}

	Concept operator==(const char *value)
	{
		std::cout << "It's " << value << " if you try" << std::endl;
		return Concept(value);
	}

	Concept operator!=(const char *value)
	{
		std::cout << "It isn't " << value << " to do" << std::endl;
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

	Population(std::string name) : Concept(name), below("below", this), above("above", this) {}

	template <typename Func>
	void reduce(Func f)
	{
		Concept symbol = Concept(std::string(f()).compare("brothers") == 0 ? "brotherhood" : "");
		Concept subject = Concept(this->compare("men") == 0 ? "man" : "");
		std::cout << "A " << symbol << " of " << subject << std::endl;
	}
};

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
			std::cout << "Nothing to " << *this << " or " << other << " for" << std::endl;
		}

		return *this;
	}
};

Concept imagine(Concept possibility)
{
	std::cout << "\033[33m# Verse " << ++verse_counter << std::endl
			  << "\033[0mImagine ";

	if (possibility.compare("no heaven") == 0 || possibility.compare("no countries") == 0)
		std::cout << "there's " << possibility;
	else
		std::cout << possibility;

	std::cout << std::endl;

	if (possibility.compare("no possessions") == 0)
		std::cout << "I wonder if you can" << std::endl;

	return Concept();
}

void imagineAll(std::string action)
{
	std::cout << "Imagine all the people" << std::endl
			  << action << std::endl
			  << std::endl;
}

void chorus()
{
	std::cout << "\033[33m# Chorus" << std::endl
			  << "\033[0mYou may say I'm a dreamer" << std::endl
			  << "But I'm not the only one" << std::endl
			  << "I hope someday you'll join us" << std::endl
			  << "And the world will " << (++chorus_counter == 1 ? "be" : "live") << " as one" << std::endl
			  << std::endl;
}

bool need(Concept concepts)
{
	bool needed = false;

	if (!needed)
		std::cout << "No need for " << concepts << std::endl;

	return needed;
}

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

// TODO: accumulate line and capitalize the first letter before flushing

DeclarePopulation(us);
DeclarePopulation(men);

DeclareAction(kill);
DeclareAction(die);

int main()
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