class Shift
{
	public static void main(String args[])
	{
		int a = 5; //0000000000000101
		int b = -5; //1111111111111011
		int ls1 = a<<2; //0000000000010100
		int rs1 = a>>2; //0000000000000001
		int urs1 = a>>>2; //0000000000000001
		int ls2 = b<<2; //1111111111101100
		int rs2 = b>>2; //1111111111111110
		int urs2 = b>>>2; //00111111111111111111111111111110

		System.out.println(ls1+" "+rs1+" "+urs1+" "+ls2+" "+rs2+" "+urs2);
	}
}


