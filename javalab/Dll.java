import java.util.*;

class Dll
{
	public static void main(String args[])
	{
		LinkedList<String> list = new LinkedList<String>();
		
		list.add("Ajith");
		list.add(0,"Mnakshi");
		list.add("Dinoy");
		list.add("Emil");
		list.add("Jijo");
		
		System.out.println(list+"\n");
		
		list.remove(4);
		list.remove("Emil");
		
		Iterator itr = list.iterator();
		
		System.out.println("The list, after deletion, contains:");
		
		while(itr.hasNext())
			System.out.println(itr.next());
	}
}
