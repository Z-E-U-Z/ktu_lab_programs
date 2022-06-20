public class Transpose
{
	public static void main(String[] args)
	{
		int row=3, column=3;
		int matrix[][]={{1,2,3},{4,5,6},{7,8,9}};
		
		//transpose the matrix
		int transpose[][]=new int[column][row];
		for(int i=0;i<row;i++)
			for(int j=0;j<column;j++)
				transpose[j][i]=matrix[i][j];

		//display the transpose
		System.out.println("The transpose is: ");
		for(int j=0;j<column;j++)
		{
			for(int i=0;i<row;i++)
				System.out.print(transpose[j][i]+" ");
			System.out.println();
		}
	}
}
