#pragma once

//Item class
class Item
{
public:
	Item();
	Item(const std::string& name, float quality, float strength, int cost);
	~Item();

	void SetName(const std::string& name)
	{
		Name = name;
	};

	const std::string& GetName()
	{
		return Name;
	};

	void SetQuality(float q)
	{
		Quality = q;
	};

	float GetQuality()
	{
		return Quality;
	};

	void SetStrength(float s)
	{
		Strength = s;
	};

	float GetStrength()
	{
		return Strength;
	};

	void SetCost(int c)
	{
		Cost = c;
	};

	int GetCost()
	{
		return Cost;
	};

	//Function to display the Item to the console window
	void Display();
private:
	std::string Name;
	float Strength;
	float Quality;
	int Cost;
};