import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

class Fibonacci
{
	Fibonacci()
	{
		JFrame frame = new JFrame("Fibonacci");
		
		TextField text = new TextField("Enter limit");
		JButton calc = new JButton("Display");
		JButton clear = new JButton("Clear");
		JLabel label = new JLabel();
		
		frame.setLayout(new FlowLayout());
		frame.setBounds(0,0,500,100);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		frame.add(text);
		frame.add(calc);
		frame.add(clear);
		frame.add(label);
				
		calc.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae){

				try {
				
					int n = Integer.parseInt(text.getText());
					
					if(n == 1)
						label.setText("[1,1]");
					else if(n == 2)
						label.setText("[1,1,2]");
					else if(n < 1)
						label.setText("Enter a natural number");
					else {
						ArrayList<String> list = new ArrayList<>();
						list.add("1");
						list.add("1");
						list.add("2");
						
						int i = 1, j = 2, res = 0;
						
						while(i+j <= n)
						{
							res = i+j;
							list.add(res+"");
							i = j;
							j = res;
						}
						
						label.setText(list.toString());
					}
					
				} catch (Exception e) {
					label.setText("Enter a natural number");
				}
			
			}
		});
		
		clear.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae){
				
				text.setText("");
				label.setText("");
			
			}
		});
	}
	
	public static void main(String args[])
	{
		new Fibonacci();
	}
}
