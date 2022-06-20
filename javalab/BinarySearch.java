import java.util.*;

class BinarySearch
{
	static void search(int arr[], int X)
	{
		int first = 0;
		int last = arr.length-1;
		int mid = (first + last)/2;
		
		while(first <= last)
		{
			if(X < arr[mid])
			{
				last = mid - 1;
			}
			else if(X > arr[mid])
			{
				first = mid + 1;
			}
			else
			{
				System.out.println("Element found at index: "+mid);
				break;
			}
			
			mid = (first + last)/2;
		}
		
		if(first > last)
			System.out.println("Element not found!");
	}
	
	public static void main(String args[])
	{	
		Scanner in = new Scanner(System.in);
		
		System.out.println("Enter the no. of elements");
		int n = in.nextInt();
		
		int arr[] = new int[n];
		
		System.out.println("Enter the elements in ascending order");
		for(int i=0;i<n;i++)
			arr[i] = in.nextInt();
		
		System.out.println("Enter the search element");
		int X = in.nextInt();
		
		search(arr, X);
	}
}
