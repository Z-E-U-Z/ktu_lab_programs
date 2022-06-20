import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Traffic
{
	Traffic()
	{
		JFrame frame = new JFrame("Traffic Light");
		JRadioButton[] b = new JRadioButton[3];
		ButtonGroup bg = new ButtonGroup();    

		for(int i=0;i<3;i++)
		{
			b[i] = new JRadioButton("");		
			b[i].setFont(new Font("Sans Serif", Font.BOLD, 24));
					
		}

		b[0].setBackground(Color.GRAY);
		b[1].setBackground(Color.GRAY);
		b[2].setBackground(Color.GRAY);
		
		for(int i=0;i<3;i++)
		{
			bg.add(b[i]);
			frame.add(b[i]);
		}
		
		frame.setSize(300,130);
		
		frame.setLayout(new GridLayout(1,3));
		
		frame.setVisible(true);
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		b[0].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae){
			
				b[0].setBackground(Color.RED);
				b[1].setBackground(Color.GRAY);
				b[2].setBackground(Color.GRAY);
				
				b[0].setText("STOP");
				b[1].setText("");
				b[2].setText("");
			}
		});
		b[1].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae){
			
				b[1].setBackground(Color.YELLOW);
				b[0].setBackground(Color.GRAY);
				b[2].setBackground(Color.GRAY);
				
				b[1].setText("WAIT");
				b[0].setText("");
				b[2].setText("");
			}
		});
		b[2].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae){
			
				b[2].setBackground(Color.GREEN);
				b[1].setBackground(Color.GRAY);
				b[0].setBackground(Color.GRAY);
				
				b[2].setText("GO");
				b[1].setText("");
				b[0].setText("");
			}
		});
	}
	
	public static void main(String...args)
	{
		new Traffic();
	}
}
