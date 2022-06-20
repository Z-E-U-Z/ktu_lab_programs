abstract class Shape
{
	abstract int numberOfSides();
}

class Triangle extends Shape
{
	int numberOfSides()
	{
		return 3;
	}
}

class Rectangle extends Shape
{
	int numberOfSides()
	{
		return 4;
	}
}

class Hexagon extends Shape
{
	int numberOfSides()
	{
		return 6;
	}
}

class NoOfSides
{
	public static void main(String... args)
	{	
		Triangle tri1 = new Triangle();
		Rectangle rect1 = new Rectangle();
		Hexagon hex1 = new Hexagon();
		
		System.out.println("No. of sides in Triangle = "+tri1.numberOfSides());
		System.out.println("No. of sides in Rectangle = "+rect1.numberOfSides());
		System.out.println("No. of sides in Hexagon = "+hex1.numberOfSides());
	}
}

