#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

extern void begin_music();
extern void end_music();

#define sleep(ms) std::this_thread::sleep_for(std::chrono::milliseconds(ms));

int chorus_counter = 0;
int verse_counter = 0;

/**
 * @brief This class holds the current line of the lyrics to uppercase the first letter of it before flushing to the standard output.
 */
class Lyrics
{
public:
	Lyrics()
	{
        begin_music();

		this->output << "\033[32m"
					 << R"(
/**
 * Guess the song... 😌 😎
 */
)"
					 << "\033[0m" << std::endl;
	}

	~Lyrics()
	{
		char last;

		for (char &current : this->output.str())
		{
			std::cout << current << std::flush;

			if (current == last && last == '\n')
			{
				sleep(150);
			}
			else
			{
				sleep(10);
			}

			last = current;
		}

        // End music when a key is pressed.
        std::getchar();
        end_music();
	}

	friend Lyrics &operator<<(Lyrics &, const std::string &);
	friend Lyrics &operator<<(Lyrics &, int);

private:
	std::ostringstream output;
	std::ostringstream current_line;
} lyrics;

Lyrics &operator<<(Lyrics &lyrics, const std::string &value)
{
	if (value == "\n")
	{
		std::string line = lyrics.current_line.str();
		line[0] = toupper(line[0]);

		// Flush with uppercase first letter.
		lyrics.output << line << std::endl;
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

/**
 * @brief Defines a concept in the song.
 */
class Concept : public std::string
{
private:
	/**
	 * @brief The parent of the concept.
	 */
	Concept *parent;

public:
	Concept() : std::string() {}
	Concept(std::string name) : std::string(name) {}
	Concept(std::string name, Concept *parent) : std::string(name), parent(parent) {}
	Concept(const Concept &) = default;

	operator bool() { return !this->empty(); }

	Concept operator=(const Concept &value)
	{
		Concept assigned = value.compare("undefined") == 0 ? !*this : *this;

		if (this->compare("below") == 0)
			lyrics << value << " " << assigned << " " << *this->parent << "\n";

		if (this->compare("above") == 0)
			lyrics << assigned << " " << *this->parent << ", only " << value << "\n";

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

/**
 * @brief Defines a population referenced in the song.
 */
class Population : Concept
{
public:
	/**
	 * @brief A concept below the population.
	 */
	Concept below;

	/**
	 * @brief A concept above the population.
	 */
	Concept above;

	Population(std::string name) : Concept(name), below("below", this), above("above", this) {}

	/**
	 * @brief An operation which is applied to a population.
	 *
	 * @tparam Func
	 * @param operation
	 */
	template <typename Func>
	void reduce(Func operation)
	{
		Concept symbol = Concept(std::string(operation()).compare("brothers") == 0 ? "brotherhood" : "");
		Concept subject = Concept(this->compare("men") == 0 ? "man" : "");
		lyrics << "A " << symbol << " of " << subject << "\n";
	}
};

/**
 * @brief Defines a list of reasons.
 */
class Reasons
{
public:
	int length;
};

/**
 * @brief Defines an action in the song.
 */
class Action : Concept
{
public:
	/**
	 * @brief The list of reasons why this action is happening.
	 */
	Reasons reasons;

	Action(std::string name) : Concept(name) {}

	Action operator||(const Action &other)
	{
		if (this->reasons.length + other.reasons.length == 0)
			lyrics << "Nothing to " << *this << " or " << other << " for"
				   << "\n";

		return *this;
	}
};

/**
 * @brief Start of a verse. Imagine a possibility...
 *
 * @param possibility
 * @return Concept
 */
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

/**
 * @brief End of a verse. Imagine all the people doing an action...
 *
 * @param action
 */
void imagineAll(std::string action)
{
	lyrics << "Imagine all the people"
		   << "\n"
		   << action << "\n"
		   << "\n";
}

/**
 * @brief The chorus, which comes in two slightly different versions.
 */
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

/**
 * @brief Do you really need this?
 *
 * @param concepts
 * @return bool
 */
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