#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int chorus_counter = 0;
int verse_counter = 0;

class Lyrics
{
public:
	friend Lyrics &operator<<(Lyrics &, const std::string &);
	friend Lyrics &operator<<(Lyrics &, int);

private:
	std::ostringstream current_line;
} lyrics;

Lyrics &operator<<(Lyrics &lyrics, const std::string &value)
{
	if (value == "\n")
	{
		std::string line = lyrics.current_line.str();
		line[0] = toupper(line[0]);

		// Flush with uppercase first letter.
		std::cout << line << std::endl;
		lyrics.current_line = std::ostringstream();
		return lyrics;
	}

	lyrics.current_line << value;
	return lyrics;
}

Lyrics &operator<<(Lyrics &lyrics, int value)
{
	lyrics << std::to_string(value);
	return lyrics;
}

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
			lyrics << value << " " << assigned << " " << *parent << "\n";

		if (this->compare("above") == 0)
			lyrics << assigned << " " << *parent << ", only " << value << "\n";

		if (this->compare("religion") == 0)
			lyrics << "And " << assigned << " too"
				   << "\n";

		return value;
	}

	Concept operator==(const char *value)
	{
		lyrics << "It's " << value << " if you try"
			   << "\n";
		return Concept(value);
	}

	Concept operator!=(const char *value)
	{
		lyrics << "It isn't " << value << " to do"
			   << "\n";
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
		lyrics << "A " << symbol << " of " << subject << "\n";
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
			lyrics << "Nothing to " << *this << " or " << other << " for"
				   << "\n";
		}

		return *this;
	}
};

Concept imagine(Concept possibility)
{
	lyrics << "\033[33m# Verse " << ++verse_counter << "\n"
		   << "\033[0mImagine ";

	if (possibility.compare("no heaven") == 0 || possibility.compare("no countries") == 0)
		lyrics << "there's " << possibility;
	else
		lyrics << possibility;

	lyrics << "\n";

	if (possibility.compare("no possessions") == 0)
		lyrics << "I wonder if you can"
			   << "\n";

	return Concept();
}

void imagineAll(std::string action)
{
	lyrics << "Imagine all the people"
		   << "\n"
		   << action << "\n"
		   << "\n";
}

void chorus()
{
	lyrics << "\033[33m# Chorus"
		   << "\n"
		   << "\033[0mYou may say I'm a dreamer"
		   << "\n"
		   << "But I'm not the only one"
		   << "\n"
		   << "I hope someday you'll join us"
		   << "\n"
		   << "And the world will " << (++chorus_counter == 1 ? "be" : "live") << " as one"
		   << "\n"
		   << "\n";
}

bool need(Concept concepts)
{
	bool needed = false;

	if (!needed)
		lyrics << "No need for " << concepts << "\n";

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