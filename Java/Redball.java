package Redball;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.Timer;
import javax.swing.WindowConstants;

public class RedBall extends JComponent implements ActionListener, MouseMotionListener, KeyListener {

    private int ballx = 150;
    private int bally = 30;
   
    private int paddlex = 0;
    private int ballySpeed = 7;
    private int ballxSpeed = 5;
    
    public int score = 0;
    private int scorefinal;
    public int bestscore;

    public boolean gameOver, started;
   public static void main(String[] args) {

        JFrame wind = new JFrame("Nikhil's paddle");
        RedBall g = new RedBall();
        wind.add(g);
        wind.pack();
        wind.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        wind.setLocationRelativeTo(null);
        wind.setVisible(true);
        wind.addMouseMotionListener(g);

        Timer tt = new Timer(20, g);
        tt.start();

    }

    public void newball(int ballx, int bally, int ballxspeed, int ballyspeed) {

        ballx = 150;
        bally = 30;
        ballxspeed = 5;
        ballyspeed = 7;

        JOptionPane.showMessageDialog(null, "new ball !");

        return;
    }

    @Override
    public Dimension getPreferredSize() {

        return new Dimension(800, 800);
    }

    @Override
    protected void paintComponent(Graphics g) {

        //draw the sky
        g.setColor(Color.cyan);
        g.fillRect(0, 0, 800, 600);

        g.setColor(Color.green);
        g.fillRect(0, 550, 800, 100);

        //draw the paddel
        g.setColor(Color.blue);
        g.fillRect(paddlex, 510, 100, 20);

        //draw the ball
        g.setColor(Color.BLACK);
        g.fillOval(ballx, bally, 30, 30);
        
        //score	
        if (score >= 5) {
            g.setColor(Color.black);
            g.setFont(new Font("Arial", 8, 50));
            g.drawString(String.valueOf(score), 15, 80);
        } else {
            g.setColor(Color.white);
            g.setFont(new Font("Arial", 8, 50));
            g.drawString(String.valueOf(score), 0 , 80);
        }
        // start && gameOver
        g.setColor(Color.white);
        g.setFont(new Font("Arial", 8, 50));

        if (gameOver) {

            g.drawString(String.valueOf(" Best Score :" + scorefinal), 50 / 1 - 15, 200);
            score=0;
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        ballx = ballx + ballxSpeed;
        bally = bally + ballySpeed;

        // Window Down 
        if (ballx >= paddlex && ballx <= paddlex + 100 && bally >= 475) {

            ballySpeed = -7;
            score++;

        }

        if (bally >= 700 ) {

           // score = 0;
            bally = 30;
            gameOver = true;

        }

        // Window up
        if (bally <= 0) {

            ballySpeed = 10;

        }

        // Window right
        if (ballx >= 775) {

            ballxSpeed = -20;

        }

        // Window left
        if (ballx <= 0) {

            ballxSpeed = 20;

        }

   

        //**********************************************************************
        bestscore = score;

        if (scorefinal <= bestscore) {

        scorefinal = score ;

        } 
        
        if (scorefinal > bestscore) {

            scorefinal = scorefinal;

        } else {

            scorefinal = bestscore;
            scorefinal = score;
        }
        
        repaint();
    }

    @Override
    public void mouseMoved(MouseEvent e) {

        paddlex = e.getX() - 50;
        repaint();
    }

    @Override
    public void mouseDragged(MouseEvent e) {
    }

    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {

    }

    @Override
    public void keyReleased(KeyEvent e) {

    }

}
