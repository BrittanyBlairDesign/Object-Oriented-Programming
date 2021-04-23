
/*
	Brittany's Sandwich shop
	by-BrittanyBlair
	GAP255 M1
*/

#include <iostream>
#include <vector>

// Kinds of bread
enum TypesOfBread
{
	WHEAT,
	WHITE,
	ITALIAN,
	WRAP,
	BRIOCHE,
	SOURDOUGH,
	RYE,
	PITA,
	MULTIGRAIN,
	FOCACCIA,
	CIABATTA,
};

//Kindsof proteins
enum TypesOfProtein
{
	BEEF,
	SALAMI,
	ROASTBEEF,
	BOLOGNA,
	HAM,
	CORNEDBEEF,
	CHICKENBREAST,
	TURKEY,
	SPAM,
	PEPPERONI,
	SETAN,
	TOFURKEY,
	TOFU,
	PEANUTBUTTER,
	STEAK,
	EGG,
	TUNA,
	NONE,
};

//Kinds of condiments
enum TypesOfCondiments
{
	MUSTARD,
	DEJON,
	MAYO,
	KETCHUP,
	JELLY,
	THOUSANDISLAND,
	SALSA,
	RELISH,
	HORSERADDISH,
	BARBECUE,
	HOTSAUSE,
	AIOLI,
	SOURCREAM,
	HUMMUS,
	SIRACHA,
	NA,
};

//Sandwich class that holds each sandwiches information.
class Sandwich 
{
private:
	
	std::string m_name;							// name of the sandwich
	float m_price;								// price of the sandwich
	TypesOfBread m_bread;						// What kind of bread the sandwich uses
	TypesOfProtein m_firstprotein;				// what kind of protein is in the sandwich
	TypesOfProtein m_secondprotein = NONE;		// What is the second protein on the sandwich
	TypesOfCondiments m_firstcondiment;			// what Condiment is used in the sandwich
	TypesOfCondiments m_secondcondiment = NA;	// the second condiment used on the sandwich
	bool m_toasted;								// is the sandwich toasted or not
	std::vector<std::string> m_toppings;		// list of toppings

public:

	// constructor customizes a sandwich with one protein and one condiment.
	Sandwich(std::string name, float price, std::vector<std::string> toppings, TypesOfCondiments condiment, TypesOfBread bread, TypesOfProtein protein, bool Toasted)
		: m_price(price),
		m_name(name),
		m_bread(bread),
		m_firstprotein(protein),
		m_firstcondiment(condiment),
		m_toasted(Toasted)
	{
		m_toppings = toppings;
	}

	// constructor customizes a sandwich with two proteins and two condiment.
	Sandwich(std::string name, float price, std::vector<std::string> toppings, TypesOfCondiments condiment1, TypesOfCondiments condiment2, TypesOfBread bread, TypesOfProtein protein1, TypesOfProtein protein2, bool Toasted)
		: m_price(price),
		m_name(name),
		m_bread(bread),
		m_firstprotein(protein1),
		m_secondprotein(protein2),
		m_firstcondiment(condiment1),
		m_secondcondiment(condiment2),
		m_toasted(Toasted)
	{
		m_toppings = toppings;
	}

	//Getters
	float GetPrice() { return m_price; }			//Get and return the price of the sandwich
	std::string GetName() { return m_name; }	//gets the name of the sandwich
	void GetToppings()					//Prints the different toppings that are on the sandwich
	{
		for (int i = 0; i < m_toppings.size(); ++i)		// takes the size of the toppings vector and then prints each of them out.
		{
			std::cout << "	" << m_toppings[i] << std::endl;
		}
	}
	void PrintOrder()
	{
		// prints name of the sandwich
		std::cout << m_name << std::endl;

		// prints the sandwich bread
		switch (m_bread)
		{
		case WHEAT:
			std::cout << "Bread : " << "Wheat"; break;
		case WHITE:
			std::cout << "Bread : " << "White";break;
		case ITALIAN:
			std::cout << "Bread : " << "Italian"; break;
		case WRAP:
			std::cout << "Bread : " << "Wrap"; break;
		case BRIOCHE:
			std::cout << "Bread : " << "Brioche"; break;
		case SOURDOUGH:
			std::cout << "Bread : " << "Sourdough"; break;
		case RYE:
			std::cout << "Bread : " << "Rye"; break;
		case PITA:
			std::cout << "Bread : " << "Pita"; break;
		case MULTIGRAIN:
			std::cout << "Bread : " << "Multigrain"; break;
		case FOCACCIA:
			std::cout << "Bread : " << "Focaccia"; break;
		case CIABATTA:
			std::cout << "Bread : " << "Ciabatta"; break;
		}

		// prints if toasted
		if (m_toasted)
		{
			std::cout << " Toasted" << std::endl;
		}
		else
		{
			std::cout << std::endl;
		}

		//prints the proteins
		switch (m_firstprotein)
		{
		case BEEF:
			std::cout << "Protein 1 : " << "Beef" << std::endl; break;
		case SALAMI:
			std::cout << "Protein 1 : " << "Salami" << std::endl; break;
		case ROASTBEEF:
			std::cout << "Protein 1 : " << "Roast beef" << std::endl; break;
		case BOLOGNA:
			std::cout << "Protein 1 : " << "Bologna" << std::endl; break;
		case HAM:
			std::cout << "Protein 1 : " << "Ham" << std::endl; break;
		case CORNEDBEEF:
			std::cout << "Protein 1 : " << "Corned beef" << std::endl; break;
		case CHICKENBREAST:
			std::cout << "Protein 1 : " << "Chicken Breast" << std::endl; break;
		case TURKEY:
			std::cout << "Protein 1 : " << "Turkey" << std::endl; break;
		case SPAM:
			std::cout << "Protein 1 : " << "Spam" << std::endl; break;
		case PEPPERONI:
			std::cout << "Protein 1 : " << "Pepperoni" << std::endl; break;
		case SETAN:
			std::cout << "Protein 1 : " << "Setan" << std::endl; break;
		case TOFURKEY:
			std::cout << "Protein 1 : " << "Tofurkey" << std::endl; break;
		case TOFU:
			std::cout << "Protein 1 : " << "Tofu" << std::endl; break;
		case PEANUTBUTTER:
			std::cout << "Protein 1 : " << "Peanutbutter" << std::endl; break;
		case STEAK:
			std::cout << "Protein 1 : " << "Steak" << std::endl; break;
		case EGG:
			std::cout << "Protein 1 : " << "Egg" << std::endl; break;
		case TUNA:
			std::cout << "Protein 1 : " << "Tuna" << std::endl; break;
		case NONE:
			break;
		}

		switch (m_secondprotein)
		{
		case BEEF:
			std::cout << "Protein 2 : " << "Beef" << std::endl; break;
		case SALAMI:
			std::cout << "Protein 2 : " << "Salami" << std::endl; break;
		case ROASTBEEF:
			std::cout << "Protein 2 : " << "Roast beef" << std::endl; break;
		case BOLOGNA:
			std::cout << "Protein 2 : " << "Bologna" << std::endl; break;
		case HAM:
			std::cout << "Protein 2 : " << "Ham" << std::endl; break;
		case CORNEDBEEF:
			std::cout << "Protein 2 : " << "Corned beef" << std::endl; break;
		case CHICKENBREAST:
			std::cout << "Protein 2 : " << "Chicken Breast" << std::endl; break;
		case TURKEY:
			std::cout << "Protein 2 : " << "Turkey" << std::endl; break;
		case SPAM:
			std::cout << "Protein 2 : " << "Spam" << std::endl; break;
		case PEPPERONI:
			std::cout << "Protein 2 : " << "Pepperoni" << std::endl; break;
		case SETAN:
			std::cout << "Protein 2 : " << "Setan" << std::endl; break;
		case TOFURKEY:
			std::cout << "Protein 2 : " << "Tofurkey" << std::endl; break;
		case TOFU:
			std::cout << "Protein 2 : " << "Tofu" << std::endl; break;
		case PEANUTBUTTER:
			std::cout << "Protein 2 : " << "Peanutbutter" << std::endl; break;
		case STEAK:
			std::cout << "Protein 2 : " << "Steak" << std::endl; break;
		case EGG:
			std::cout << "Protein 2 : " << "Egg" << std::endl; break;
		case TUNA:
			std::cout << "Protein 2 : " << "Tuna" << std::endl; break;
		case NONE:
			break;
		}

		// call the get toppings function to print toppings
		std::cout << "Toppings :" << std::endl;
		GetToppings();

		//prints the condiments
		switch (m_firstcondiment)
		{
		case MUSTARD:
			std::cout << "First Condiment : " << "Mustard" << std::endl; break;
		case DEJON:
			std::cout << "First Condiment : " << "Dejon" << std::endl; break;
		case MAYO:
			std::cout << "First Condiment : " << "Mayo" << std::endl; break;
		case KETCHUP:
			std::cout << "First Condiment : " << "Ketchup" << std::endl; break;
		case JELLY:
			std::cout << "First Condiment : " << "Jelly" << std::endl; break;
		case THOUSANDISLAND:
			std::cout << "First Condiment : " << "Thousand Ilsand" << std::endl; break;
		case SALSA:
			std::cout << "First Condiment : " << "Salsa" << std::endl; break;
		case RELISH:
			std::cout << "First Condiment : " << "Relish" << std::endl; break;
		case HORSERADDISH:
			std::cout << "First Condiment : " << "Horseraddish" << std::endl; break;
		case BARBECUE:
			std::cout << "First Condiment : " << "Barbecue" << std::endl; break;
		case HOTSAUSE:
			std::cout << "First Condiment : " << "Hot Sauce" << std::endl; break;
		case AIOLI:
			std::cout << "First Condiment : " << "Aioli" << std::endl; break;
		case SOURCREAM:
			std::cout << "First Condiment : " << "Sour Cream" << std::endl; break;
		case HUMMUS:
			std::cout << "First Condiment : " << "Hummus" << std::endl; break;
		case SIRACHA:
			std::cout << "First Condiment : " << "Siracha" << std::endl; break;
		case NA:
			break;
		}

		switch (m_secondcondiment)
		{
		case MUSTARD:
			std::cout << "Second Condiment : " << "Mustard" << std::endl; break;
		case DEJON:
			std::cout << "Second Condiment : " << "Dejon" << std::endl; break;
		case MAYO:
			std::cout << "Second Condiment : " << "Mayo" << std::endl; break;
		case KETCHUP:
			std::cout << "Second Condiment : " << "Ketchup" << std::endl; break;
		case JELLY:
			std::cout << "Second Condiment : " << "Jelly" << std::endl; break;
		case THOUSANDISLAND:
			std::cout << "Second Condiment : " << "Thousand Ilsand" << std::endl; break;
		case SALSA:
			std::cout << "Second Condiment : " << "Salsa" << std::endl; break;
		case RELISH:
			std::cout << "Second Condiment : " << "Relish" << std::endl; break;
		case HORSERADDISH:
			std::cout << "Second Condiment : " << "Horseraddish" << std::endl; break;
		case BARBECUE:
			std::cout << "Second Condiment : " << "Barbecue" << std::endl; break;
		case HOTSAUSE:
			std::cout << "Second Condiment : " << "Hot Sauce" << std::endl; break;
		case AIOLI:
			std::cout << "Second Condiment : " << "Aioli" << std::endl; break;
		case SOURCREAM:
			std::cout << "Second Condiment : " << "Sour Cream" << std::endl; break;
		case HUMMUS:
			std::cout << "Second Condiment : " << "Hummus" << std::endl; break;
		case SIRACHA:
			std::cout << "Second Condiment : " << "Siracha" << std::endl; break;
		case NA:
			break;
		}

		// print total price.
		std::cout << "Price : $" << m_price << std::endl;

	}

	//Setters
	//set a new price
	void ChangePrice(float X)			//takes in a new price and changes the cost of that sandwich, returns nothing
	{
		m_price = X;
	}

	//Change sandwich name
	void ChangeName(std::string N)		//Takes in a new Name and assigns the sandwiches name to the new one. returns nothing
	{
		m_name = N;
	}

	//add new toppings
	void AddTopping(std::string T)		//Adds a topping string to the list of toppings vector.
	{
		m_toppings.push_back(T);
	}
};

//Main
int main() 
{
	//Sandwich vector
	std::vector <Sandwich> SandwichOrder;

	// Ham sandwich
	Sandwich ham("Ham and Cheese", 2.50f, { "Cheese", "Lettuce", "Tomato" }, MUSTARD, WHITE, HAM, false);
	SandwichOrder.push_back(ham);

	//Burrito
	Sandwich burrito("Homewrecker", 5.65f, { "Cheese", "Lettuce", "Tomato", "Grilled peppers", "Grilled onion", "Black beans", "Seasoned Rice" }, SOURCREAM, SALSA, WRAP, CHICKENBREAST, STEAK, true);
	SandwichOrder.push_back(burrito);

	//Egg sandwich
	Sandwich egg("Egg salad sandwich", 2.50f, { "Lettuce" }, MUSTARD, MAYO, MULTIGRAIN, EGG, HAM, true);
	SandwichOrder.push_back(egg);

	//Pizza panini
	Sandwich panini("Pizza Panini", 4.75f, { "Cheese", "Roma tomatoes" }, HOTSAUSE, PITA, PEPPERONI, true);
	SandwichOrder.push_back(panini);

	//Tuna Sandwich
	Sandwich tuna("Tuna Sandwich", 3.25f, { "Lettuce", "Tomato", "Red Onino", "Cellary" }, MUSTARD, MAYO, WHITE, TUNA, NONE, true);
	SandwichOrder.push_back(tuna);

	//Ruben
	Sandwich ruben("Ruben", 5.50f ,{ "Swiss Cheese", "Sauerkraut" }, THOUSANDISLAND, RYE, CORNEDBEEF, true);
	SandwichOrder.push_back(ruben);

	//Cheesesteak
	Sandwich cheesesteak("Cheesesteak", 4.25, { "Grilled onions", "Grilled Peppers", "Cheese" }, KETCHUP, ITALIAN, STEAK, false);
	SandwichOrder.push_back(cheesesteak);

	//turkey club
	Sandwich turkeyclub("Turkey Club", 2.75, { "Lettuce", "Tomato", "Pickles", "Red onion" }, MUSTARD, MAYO, WHEAT, TURKEY, NONE, true);
	SandwichOrder.push_back(turkeyclub);

	//Hot chicken sandwich
	Sandwich hotchicken("Hot Chicken Sandwich", 4.00, { "Pickles" }, HOTSAUSE, BRIOCHE, CHICKENBREAST, false);
	SandwichOrder.push_back(hotchicken);

	//Grilled cheese sandwich
	Sandwich grilledcheese("Grilled Cheese", 1.75, { "Chedar Cheese", "Tomato" }, KETCHUP, WHITE, NONE, true);
	SandwichOrder.push_back(grilledcheese);

	// find the total cost of all sandwiches
	float price = 0;

	// printing sandwich shop recipt 
	std::cout << "Sandwich Shop Recipt" << std::endl << std::endl;

	for (int i = 0; i < SandwichOrder.size(); ++i)
	{
		SandwichOrder[i].PrintOrder();
		std::cout << std::endl;
		float newprice = price + SandwichOrder[i].GetPrice();
		price = newprice;
	}

	std::cout << "Total Sale ammount : $" << price << std::endl;

	system("pause");
	return 0;
}
