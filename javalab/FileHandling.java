import java.io.*;

class FileHandling
{
	
	public static void main(String args[]) throws IOException
	{
		
		try
		{
			FileInputStream fin = new FileInputStream("inputfile.txt");
			FileOutputStream fout = new FileOutputStream("outputfile.txt");
			
			int i;
			
			while((i = fin.read()) != -1)
			{
				fout.write(i);
			}
		}
		catch (IOException e)
		{
			System.out.println("Exception : " + e);
		}
	}
}
