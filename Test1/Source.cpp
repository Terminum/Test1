#include <iostream>

class Point
{
private:
	int x, y;
public:

	Point() : x(0), y(0)
	{

	}

	void SetX()
	{
		std::cout << "Enter x - ";
		std::cin >> x;
	}

	void SetY()
	{
		std::cout << "Enter y - ";
		std::cin >> y;
	}

	int Getx()
	{
		return x;
	}
	int Gety()
	{
		return y;
	}
};

class MAN
{
private:
	int x, y, r;
public:
	MAN() : x(0), y(0), r(0)
	{
		std::cout << "Enter x - ";
		std::cin >> x;

		std::cout << "Enter y - ";
		std::cin >> y;

		std::cout << "Enter r - ";
		std::cin >> r;
	}

	bool Loc(Point p)
	{
		if (((x - p.Getx()) * (x - p.Getx())) + ((y - p.Gety()) * (y - p.Gety())) <= r * r) // (x-x0)^2+(y-y0)^2<=r^2
		{
			return 1;
		}
		else
		return 0;
	}

	int Dist(Point p)
	{
		return (((x - p.Getx()) * (x - p.Getx())) + ((y - p.Gety()) * (y - p.Gety()))); //// (x-x0)^2+(y-y0)^2
	}

};



int main()
{
	std::cout << "Enter data for 1-st object." << std::endl;
	MAN O1;
	std::cout << "Enter data for 2-nd object." << std::endl;
	MAN O2;
	Point P1;

	char c;
	std::cout << " <s> set point <m> choose best hand <e> exit --> ";
	std::cin >> c;

	while (c != 'e')
	{
		if (c == 's')
		{
			P1.SetX();
			P1.SetY();
		}
		else if (c == 'm')
		{
			int l1 = -1;
			int l2 = -1;

			if (O1.Loc(P1))
			{
				l1 = O1.Dist(P1);
			}
			if (O2.Loc(P1))
			{
				l2 = O2.Dist(P1);
			}

			if (l1 < 0 and l2 < 0)
			{
				std::cout << "Out of Range." << std::endl;
			}
			else if (l1 > 0 and l2 < 0)
			{
					std::cout << "Hand 1" << std::endl;
			}
			else if (l1 < 0 and l2 > 0)
			{
				std::cout << "Hand 2" << std::endl;
			}
			else if (l1 > l2)
			{
				std::cout << "Hand 2" << std::endl;
			}
			else
			{
				std::cout << "Hand 1" << std::endl;
			}
		}
		std::cout << " --> ";
		std::cin >> c;
		
	}
	
	

}