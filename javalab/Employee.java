class Employee
{
	String name;
	int age;
	long phno;
	String address;
	double salary;
	
	void printSalary()
	{
		System.out.println("Salary = "+salary);
	}
	
	void printDetails()
	{
				
		System.out.println("\nName = "+name+"\nAge = "+age+"\nPhone No. = "+phno+"\nAddress = "+address+"\nSalary = "+salary);
	}

	public static void main(String args[])
	{
		System.out.println("Employee Details :-");
		Officer officer1 = new Officer("Ajith", 19, 8943234482l, "Ajith House, Wayanad", 75325.50);
		Manager manager1 = new Manager("Dinoy", 19, 7501234657l, "Dinoy House, Kozhikode", 81234.75, "Accounts");
	}
}

class Officer extends Employee
{
	String spl;
	
	Officer(String name, int age, long phno, String address, double salary, String spl)
	{	
		this.name = name;
		this.age = age;
		this.phno = phno;
		this.address = address;
		this.salary = salary;
		this.spl = spl;
		
		this.printDetails();
		
		this.printSpl();
	}
	
	Officer(String name, int age, long phno, String address, double salary) //Since specialization is optional data
	{	
		this.name = name;
		this.age = age;
		this.phno = phno;
		this.address = address;
		this.salary = salary;

		this.printDetails();
	}	
	
	void printSpl()
	{
		System.out.println("Specialization = "+spl);
	}
}

class Manager extends Employee
{
	String dept;
	
	Manager(String name, int age, long phno, String address, double salary, String dept) 
	{	
		this.name = name;
		this.age = age;
		this.phno = phno;
		this.address = address;
		this.salary = salary;
		this.dept = dept;
		
		this.printDetails();
		
		this.printDept();
	}
	
	Manager(String name, int age, long phno, String address, double salary) //Since department is optional data
	{	
		this.name = name;
		this.age = age;
		this.phno = phno;
		this.address = address;
		this.salary = salary;
		
		this.printDetails();
	}
	
	void printDept()
	{
		System.out.println("Department = "+dept);
	}	
}

