#include"pch.h"

class Cat
{
public:
	Cat(int a):itsAge(a)
	{
		HowManyCats++;
	}

	virtual ~Cat()
	{
		HowManyCats--;
	}
	virtual int GetAge() { return itsAge; }
	virtual void SetAge(const int a) { itsAge = a; }

	static int HowManyCats;
private:
	int itsAge;

};

int Cat::HowManyCats = 0;

TEST(TestCaseName, TestCat)
{
	const int MaxCats = 5;
	int i;
	Cat* CatHouse[MaxCats];
	for (size_t i = 0; i < MaxCats; i++)
	{
		CatHouse[i] = new Cat(i);
		std::cout <<"Now cats:" << Cat::HowManyCats << std::endl;
	}

	for (size_t i = 0; i < MaxCats; i++)
	{
		std::cout << "the " << i << " cat's age is " << CatHouse[i]->GetAge() << std::endl;;
	}

}