import studpack.Result;

class Hybrid
{
	public static void main(String arg[])
	{
		Result st1 = new Result("Abhiram", 04, 88.75f, 91, 95);
		Result st2 = new Result("Ajith", 07, 89, 90.5f, 96);
		Result st3 = new Result("Emil", 22, 90, 92.5f, 99);
		Result st4 = new Result("Dinoy", 21, 92.5f, 89, 98);
		Result st5 = new Result("Jijo", 29, 90, 90.5f, 97.5f);
		
		st1.displayTotal();
		st2.displayTotal();
		st3.displayTotal();
		st4.displayTotal();
		st5.displayTotal();
	}
}
