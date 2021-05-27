#include <iostream>
#include <string>
#include <vector>

using namespace std;
using Concept = bool;

class Population
{
public:
	Concept below;
	Concept above;

	template <typename Func>
	void reduce(Func f) {}
};

class String : public std::string
{
public:
	operator bool() { return !empty(); }
	String(std::string value) {}
};

String imagine(Concept possibility)
{
	return String("");
}

bool need(Concept concepts)
{
	return true;
}

void imagineAll(std::string something)
{
}

void chorus()
{
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
};

Action operator||(Action left, const Action &right)
{
	left.reasons.length += right.reasons.length;
	return left;
}

#define DeclareConcept(name) Concept name = true

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