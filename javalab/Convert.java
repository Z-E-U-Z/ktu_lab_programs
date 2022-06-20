import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Convert
{
	Convert()
	{
		JButton coninch = new JButton("Convert to Inches");
		JButton confeet = new JButton("Convert to Feet");
		Button close = new Button("CLOSE");
		JLabel feet = new JLabel("Feet ", JLabel.RIGHT);
		JLabel inch = new JLabel("Inches ", JLabel.RIGHT);
		JLabel empty = new JLabel("", JLabel.CENTER);
		JTextField inchtext = new JTextField();
		JTextField feettext = new JTextField();
		
		JFrame frame = new JFrame("CONVERTOR");
		JPanel panel1 = new JPanel();
		JPanel panel2 = new JPanel();
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		frame.setSize(500,500);
		
		frame.setLayout(new GridBagLayout());
		panel1.setLayout(new GridLayout(1,5));
		panel2.setLayout(new FlowLayout());
		
		GridBagConstraints c = new GridBagConstraints();
		
		panel1.add(feet);
		panel1.add(feettext);
		panel1.add(inch);
		panel1.add(inchtext);
		panel1.add(empty);
		
		panel2.add(coninch);
		panel2.add(confeet);
		
		c.gridx = 0;
		c.gridy = 0;
		c.weightx = 1;
		c.weighty = 1;
		c.fill = GridBagConstraints.HORIZONTAL;
		frame.add(panel1, c);
		
		c.gridy = 1;
		frame.add(panel2, c);
		
		c.gridy = 2;
		c.fill = GridBagConstraints.NONE;
		frame.add(close, c);
		
		frame.setVisible(true);
		panel1.setVisible(true);
		panel2.setVisible(true);
		
		coninch.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
			try{
				float num = Float.parseFloat(feettext.getText());
				inchtext.setText(num*12 + "");
				feettext.setText(num+"");
				empty.setText("Success!");
			}catch(Exception e){empty.setText("Invalid!");}
		}});
		
		confeet.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
			try{
				float num = Float.parseFloat(inchtext.getText());
				feettext.setText(num/12 + "");
				inchtext.setText(num+"");
				empty.setText("Hurray!");
			}catch(Exception e){empty.setText("Invalid!");}
		}});
		
		close.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				System.exit(0);
			}
		});
	}
	
	public static void main(String args[])
	{
		new Convert();
	}
}
