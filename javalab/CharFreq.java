public class CharFreq
{
	public static void main(String[] args)
	{
		String str = "Hello world. \"Hi\", Mr.007 to the world";
		char ch = '"';
		int count = 0;

		for(int i=0; i<str.length(); i++)
			if(str.charAt(i) == ch)
			       count++;	

		System.out.println("Frequency of '"+ch+"' in \""+str+"\" is "+count);
	}
}




