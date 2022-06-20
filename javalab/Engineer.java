class Employee
{
	static double salary;
	static String classname;

	static void display(String clsname)
	{
		classname = clsname;
		System.out.println("Name of class is "+classname);
	}

	static void calcSalary(double sal)
	{
		salary = sal;
		System.out.println("Salary of employee is "+sal);
	}
}

class Engineer extends Employee
{
	public static void main(String... args)
	{
		Employee.display("Employee");
		Employee.calcSalary(10000);

		Engineer engg1 = new Engineer();
		
		engg1.display("Engineer");
		engg1.calcSalary(20000);
	}
}



