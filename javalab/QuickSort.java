import java.util.Scanner;
import java.util.Arrays;

class QuickSort
{
	static int partition(String[] arr, int p, int r)
	{
		String temp;
		String x = arr[r];
		int i = p - 1;
		
		for(int j = p; j < r; j++)
			if(arr[j].toLowerCase().compareTo(x.toLowerCase()) <= 0)
			{
				if(i++ != j)
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		
		if(r != i+1)
		{
			temp = arr[i+1];
			arr[i+1] = arr[r];
			arr[r] = temp;
		}
		 
		 return i+1;
	}
	
	static void quickSort(String[] arr, int p, int r)
	{
		if(p<r)
		{
			int q = partition(arr, p, r);
			quickSort(arr, p, q-1);
			quickSort(arr, q+1, r);
		}
	}
	
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		
		System.out.println("Enter the list size");
		int n = in.nextInt();
		
		String s = in.nextLine(); 
		
		String[] arr = new String[n];
		
		System.out.println("Enter the names");
		for(int i=0; i<n; i++)
			arr[i] = in.nextLine();
		
		quickSort(arr, 0, n-1);
		
		System.out.println("Sorted array = "+Arrays.toString(arr)); 
	}
}
