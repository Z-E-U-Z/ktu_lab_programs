import java.util.*;

class StringTokens
{
	public static void main(String args[])
	{
		int sum = 0;
		
		System.out.println("Enter the integers to be added separated by a space!");
		Scanner in = new Scanner(System.in);
		String s = in.nextLine();
		
		StringTokenizer str = new StringTokenizer(s);
		
		System.out.println("\nYou entered :");
		
		while(str.hasMoreTokens())
		{
			int num = Integer.parseInt(str.nextToken());
			System.out.println(num);
			sum += num;
		}
		
		System.out.println("\nSum = "+sum);
	}
}			
