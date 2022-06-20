class StaticTest
{
	static void display()
	{
		System.out.println("Hello");
	}

	public static void main(String[] args)
	{
		System.out.println(args[2]);
		display();
		Stest obj = new Stest();
		Stest.val(7);
		obj.val(10);
		System.out.println(obj.a+" "+Stest.a);
	}
}

class Stest
{
	static int a=5;

	static void val(int c)
	{
		a = c;
	}
}



