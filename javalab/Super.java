class Super
{
	int num;
	String name;

	Super(int x, String y)
	{
		num = x;
		name = y;
	}

	void display()
	{
		System.out.println("No = "+num+"\nName = "+name);
	}

	public static void main(String args[])
	{
		Super obj1 = new Super(7, "Arjun");
		Sub obj2 = new Sub("Arun");

		obj1.display();
		obj2.display();
	}
}

class Sub extends Super
{
	String name;

	Sub(String x)
	{
		super(0,"Lev");
		super.num = 21;
		name = x;
	}

	void display()
	{
		super.display();
		System.out.println("Name = "+name);
	}
}


