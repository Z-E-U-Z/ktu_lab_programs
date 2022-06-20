import java.io.*;

class Except
{
	static int a[] = {0,1,2,3,4};
	static String b = "hello";
	int i = 0;
	
	public static void main(String args[]) throws IOException
	{	
		tryFinally(2);
		multipleCatch(3);
		nestedTry("1234",1);
		throwExample(args);
		throwsExample(0);
	}


	static void tryFinally(int index)
	{
		System.out.println("Try-Finally example :");
		
		try {
		
			System.out.println(a[index]);
		
		} catch(ArrayIndexOutOfBoundsException e) {
		
			System.out.println("Exception thrown : "+e);
		
		} finally {
		
			System.out.println(a[0]+" "+a[1]+" "+a[2]+" "+a[3]+" "+a[4]);
		
		}
	}
	
	static void multipleCatch(int index)
	{
		System.out.println("\nMultiple catch example :");

		try {
			
			System.out.println(b.charAt(index));
			System.out.println(a[index]);
			System.out.println(a[index]/a[index]);
				
		} catch(ArithmeticException e) {
		
			System.out.println("Exception thrown : "+e);
		
		} catch(IndexOutOfBoundsException e) {
		
			System.out.println("Exception thrown : "+e);
	
		} catch(RuntimeException e) {
		
			System.out.println("Exception thrown : "+e);
		
		} 
	}
	
	static void nestedTry(String str, int index)
	{
		System.out.println("\nNested Try example :");
		
		try {
			int j = Integer.parseInt(str);
			System.out.println(j);
			
			try {
				System.out.println(str.charAt(index));
				System.out.println(a[index]);
				
				try {
					
					Except obj = new Except();
					if(index == 0)
						obj = null;
					
					System.out.println(obj.i);
				
				} catch(NullPointerException e) {
		
					System.out.println("Exception thrown : "+e);		
		
				}
				
			} catch(IndexOutOfBoundsException e) {
		
				System.out.println("Exception thrown : "+e);		
			
			}
		
		} catch (NumberFormatException e) {
		
			System.out.println("Exception thrown : "+e);		
		
		}
	}
	
	static void throwExample(String input[])
	{
		System.out.println("\nThrow example :");		
		
		if(input.length != 2)
		{
			throw new RuntimeException("Input 2 numbers at the command-line !");
		}	
		
		else
		{
		
			try {		
		
			int x = Integer.parseInt(input[0]);
			int y = Integer.parseInt(input[1]);
		
			System.out.println(x+y);						
		
			} catch(NumberFormatException e){
			
			System.out.println("Input 2 numbers !");
			throw e;
		
			}
		
		}
	}
	
	static void throwsExample(int index) throws FileNotFoundException, ArrayIndexOutOfBoundsException
	{
		
		System.out.println("\nThrows example :");
		
		System.out.println(a[index]);
		
		File file = new File ("/home/amal/javalab/Hello.java");
		
		FileReader fr = new FileReader(file);
		
	}
}

