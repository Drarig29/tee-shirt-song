#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Concept : public std::string
{
public:
    Concept() : std::string() {}
    Concept(std::string value) : std::string(value) {}

    operator bool() { return !this->empty(); }

    Concept operator=(const Concept &value)
    {
        if (this->compare("below") == 0)
            cout << value << " " << *this << " us" << endl;

        if (this->compare("above") == 0)
            cout << *this << " us, only " << value << endl;

        return value;
    }

    Concept operator==(const char *value)
    {
        if (value == "easy")
            cout << "It's " << value << " if you try" << endl;

        return Concept(value);
    }

    Concept operator!() { return Concept("no " + *this); }
    Concept operator||(const Concept &other) { return Concept(*this + " or " + other); }
};

class Population
{
public:
    Concept below;
    Concept above;

    Population() : below("below"), above("above") {}

    template <typename Func>
    void reduce(Func f) {}
};

Concept imagine(Concept possibility)
{
    cout << "Imagine ";

    if (possibility == "no heaven" || possibility == "no countries")
        cout << "there's " << possibility;
    else
        cout << possibility;

    cout << endl;

    return Concept();
}

bool need(Concept concepts)
{
    return true;
}

void imagineAll(std::string action)
{
    cout << "Imagine all the people" << endl
         << action << endl
         << endl;
}

void chorus()
{
    cout << "Chorus" << endl
         << endl;
}

class Reasons
{
public:
    int length;
};

class Action
{
public:
    Reasons reasons;

    Action operator||(const Action &other)
    {
        this->reasons.length += other.reasons.length;
        return *this;
    }
};

#define DeclareConcept(name) Concept name(#name)

DeclareConcept(heaven);
DeclareConcept(hell);
DeclareConcept(sky);
DeclareConcept(countries);
DeclareConcept(religion);
DeclareConcept(possessions);
DeclareConcept(greed);
DeclareConcept(hunger);
DeclareConcept(undefined);

Population us;
Population men;

Action kill;
Action die;

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