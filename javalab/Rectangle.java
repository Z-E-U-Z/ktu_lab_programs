class Rectangle
{
	int length;
	int breadth;
	int area;

	void getData(int x, int y)
	{
		length = x;
		breadth = y;
	}
	
	int getArea()
	{
		int area = length * breadth;
		return area;
	}

	public static void main(String args[])
	{
		Rectangle myrect1 = new Rectangle();
		Rectangle myrect2 = new Rectangle();

		myrect1.length = 10;
		myrect1.breadth = 20;

		myrect2.getData(5,10);

		myrect1.area = myrect1.length * myrect1.breadth;

		myrect2.area = myrect2.getArea();

		int area1 = myrect1.length * myrect1.breadth;
		int area2 = myrect2.getArea();

		System.out.println("Area of first rectangle = "+myrect1.area+" or "+area1);
		System.out.println("Area of second rectangle = "+myrect2.area+" or "+area2);
	}
}

