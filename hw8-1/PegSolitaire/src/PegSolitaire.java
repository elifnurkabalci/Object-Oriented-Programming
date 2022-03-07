/**
 * @author elifnurkabalci
 * @version 1.0.0
 * @since 2022-01-28
 */

import java.awt.FlowLayout;
import java.awt.GraphicsConfiguration;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import javax.swing.JButton;
import javax.swing.JRadioButton;
import javax.swing.JTextField;
import javax.swing.JFrame;

interface PegSolitaireGame{
    public void print();
    public void initilizes();
    public int endgame();
    public int boardScore();
    public Object clone() throws CloneNotSupportedException;
    public void controlMove();
    public void printscore();
    public void ReadFile();
    public void WriteFile();
    public void fillvec();
    public void Greeting();
}
public class PegSolitaire implements PegSolitaireGame{
    char[][] vec = new char[9][9];
    static int row = 0, col=0,size=0, lastrow=0, lastcol=0;
    static int type=0;
    static GraphicsConfiguration gc;
    JFrame frame = new JFrame(gc);
    JButton [][]buttons= new JButton[9][9];
    JFrame f= new JFrame();
    JButton []arr = new JButton[3];
    JRadioButton []k = new JRadioButton[6];
    JFrame choc = new JFrame();

    public Object clone() throws CloneNotSupportedException
    {
        return super.clone();
    }
    public void print(){
        //f.setDefaultCloseOperation(1);
        String ptr[]={"A", "B","C", "D", "E", "F", "G", "H", "I", "J", "K", "L"}; // col 
        JButton s = new JButton(" "); // space
        f.add(s);
        for(int i=0; i<size; i++){
            JButton c = new JButton(ptr[i]); // col locations
            f.add(c);
        }
        for(int i=0; i<size; i++){ //row
            JButton c = new JButton(Integer.toString(i+1));
            f.add(c);
            for(int j=0; j<size; j++){ //col
                JButton b = new JButton(String.valueOf(vec[i][j]));
                f.add(b);
                buttons[i][j]=b;
                buttons[i][j].addActionListener(listen);
            }
        }
        JButton rst = new JButton("Reset");
        JButton load = new JButton("Load");
        JButton save = new JButton("Save");
        f.add(rst);
        f.add(load);
        f.add(save);
        arr[0]=rst; arr[1]=load; arr[2]=save;
        arr[0].addActionListener(listen); arr[1].addActionListener(listen); arr[2].addActionListener(listen);
        for(int i=0; i<size-3; i++){
            JButton m = new JButton(" "); // space
            f.add(m);
        }
        f.setLayout(new GridLayout(size+2,size+1));
        f.setSize(800,800);
        f.setVisible(true);
    }
    public void controlMove(){
        boolean temp=false;
        if(vec[lastrow][lastcol]=='P' && vec[row][col]=='.'){
            if(lastcol == col && lastrow==row+2 && vec[lastrow+1][col]=='P'){ // down
                vec[lastrow][lastcol]='.';
                vec[row][col]='P';
                vec[lastrow+1][col]='.';
                temp=true;
            }
            else if(lastcol == col && lastrow==row-2 && vec[lastrow-1][col]=='P'){ // down
                vec[lastrow][lastcol]='.';
                vec[row][col]='P';
                vec[lastrow-1][col]='.';
                temp=true;
            }
            else if(lastrow == row && lastcol==col+2 && vec[row][col+1]=='P'){ // right
                vec[lastrow][lastcol]='.';
                vec[row][col]='P';
                vec[row][col+1]='.';
                temp=true;
            }
            else if(lastrow == row && lastcol==col-2 && vec[row][col-1]=='P'){ // left
                vec[lastrow][lastcol]='.';
                vec[row][col]='P';
                vec[row][col-1]='.';
                temp=true;
            }
        }
        else{ // if move does not exist
            f.getContentPane().removeAll();
            f.repaint();
            print();
        }
        if(temp==true){ // if first moving is completed
            // printing and become ready for next move
            f.getContentPane().removeAll();
            f.repaint();
            print();
            
        }
    }
    public void printscore(){
        JFrame fr= new JFrame(); // I choose the jbutton for printing score
        JRadioButton buttn = new JRadioButton("Score: " + boardScore());
        buttn.setBounds(75, 50, 100, 30);
        fr.add(buttn);
        fr.setSize(200, 200);
        fr.setLayout(null);
        fr.setVisible(true);
    }
    public void ReadFile(){
        try {
            try (FileReader file = new FileReader("save.txt")) { // if file is exist
                char[] a = new char[1]; 
                file.read(a); // type of game
                type=a[0] - 48;  // char to int
                if(type==1 || type==4) size=7;
                else if(type==2 || type==5) size=9;
                else if(type==3) size=8; // for declare size
                char[][] array = new char[9][9]; // for reaind from file
                for(int i=0; i<size; i++){
                    file.read(a); // \n 
                    file.read(array[i]); // read line by line
                    for(int j=0; j<size; j++){
                        if(array[i][j]=='0') vec[i][j]=' ';
                        else if(array[i][j]=='\n') System.out.println("err");
                        else vec[i][j]=array[i][j];
                    }
                }
                file.close();
            }
        } catch (Exception e) {
            System.out.println("Error");
        }
    }
    public void WriteFile(){
        try {
            FileWriter file = new FileWriter("save.txt");
            file.write((char)type+48);
            file.write("\n");
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    if(vec[i][j]!='P' && vec[i][j]!='.') file.write('0');
                    else file.write(vec[i][j]);
                }
                file.write("\n");
            }
            file.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        
    }
    ActionListener listen = new ActionListener(){
        public void actionPerformed(ActionEvent e){
        if(endgame()==1){
            printscore(); 
        }
        else if(e.getSource() == arr[0]){
            f.getContentPane().removeAll();
            f.repaint();
            initilizes();
        }
        else if(e.getSource() == arr[1]){ // I understand, load use saved game
            ReadFile();
            f.getContentPane().removeAll();
            f.repaint();
            print();
        }
        else if(e.getSource() == arr[2]){ // I understand save the details to file
            WriteFile();
        }
        else{    
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    if(e.getSource() == buttons[i][j]){
                        row=i;
                        col=j;
                    }
                }
            }
            if(lastrow==0 && lastcol==0){ // in first button
                lastcol=col; lastrow=row;
            }
            else{ // in second button
                controlMove();
                lastcol=0; lastrow=0; // ready for second round
                row=0; col=0;
            }
        }
        }
    };
    ActionListener list = new ActionListener(){
        public void actionPerformed(ActionEvent e){
            if(k[0].isSelected()){ // declare the sizes and types
                size=7;
                type=1;
                choc.setVisible(false);
                fillvec();
            }
            else if(k[1].isSelected()){
                type=2;
                size=9;
                choc.setVisible(false);
                fillvec();
            }
            else if(k[2].isSelected()){
                type=3;
                size=8;
                choc.setVisible(false);
                fillvec();
            }
            else if(k[3].isSelected()){
                type=4;
                size=7;
                choc.setVisible(false);
                fillvec();
            }
            else if(k[4].isSelected()){
                type=5;
                size=9;
                choc.setVisible(false);
                fillvec();
            }
            else if(k[5].isSelected()){
                type=7;
                choc.setVisible(false);
                fillvec();
            }
        }
    };
    public void fillvec(){
        switch (type)
    {  // In this switch, we fill the vector 
    case 1:{
        for(int i=0; i<7; i++){
            if(i==0 || i==6){
                vec[i][2]='P'; vec[i][3]='P'; vec[i][4]='P';
            }
            else if(i==1 || i==5){
                vec[i][1]='P'; vec[i][2]='P'; vec[i][3]='P'; vec[i][4]='P'; vec[i][5]='P';
            }
            else if(i==2){
                vec[i][0]='P'; vec[i][1]='P'; vec[i][2]='P';
                vec[i][3]='.';
                vec[i][4]='P'; vec[i][5]='P'; vec[i][6]='P';
            }
            else if(i==3 || i==4){
                vec[i][0]='P'; vec[i][1]='P'; vec[i][2]='P'; vec[i][3]='P'; vec[i][4]='P'; vec[i][5]='P'; vec[i][6]='P';
            }
        }
    }break;
    case 2:{
        for(int i=0; i<9; i++){
            if(i==0 || i==1 || i==2 || i==6 || i==7 || i==8){
                vec[i][3]='P'; vec[i][4]='P'; vec[i][5]='P';
            }
            else if(i==3 || i==5){
                vec[i][0]='P'; vec[i][1]='P'; vec[i][2]='P'; vec[i][3]='P'; vec[i][4]='P'; vec[i][5]='P'; vec[i][6]='P'; vec[i][7]='P'; vec[i][8]='P';
            }
            else if(i==4){
                vec[i][0]='P'; vec[i][1]='P'; vec[i][2]='P'; vec[i][3]='P';
                vec[i][4]='.';
                vec[i][5]='P'; vec[i][6]='P'; vec[i][7]='P'; vec[i][8]='P';
            }
        }
    }break;
    case 3:{
        for(int i=0; i<8; i++){
            if(i==0 || i==1 || i==2 || i==6 || i==7){
                vec[i][2]='P'; vec[i][3]='P'; vec[i][4]='P';
            }
            else if(i==3 || i==5){
                vec[i][0]='P'; vec[i][1]='P'; vec[i][2]='P'; vec[i][3]='P'; vec[i][4]='P'; vec[i][5]='P'; vec[i][6]='P'; vec[i][7]='P';
            }
            else if(i==4){
                vec[i][0]='P'; vec[i][1]='P'; vec[i][2]='P';
                vec[i][3]='.';
                vec[i][4]='P'; vec[i][5]='P'; vec[i][6]='P'; vec[i][7]='P';
            }
        }
    }break;
    case 4:{
        for(int i=0; i<7; i++){
            if(i==0 || i==1 || i==5 || i==6){
                vec[i][2]='P'; vec[i][3]='P'; vec[i][4]='P';
            }
            else if(i==2 || i==4){
                vec[i][0]='P'; vec[i][1]='P'; vec[i][2]='P'; vec[i][3]='P'; vec[i][4]='P'; vec[i][5]='P'; vec[i][6]='P';
            }
            else if(i==3){
                vec[i][0]='P'; vec[i][1]='P'; vec[i][2]='P';
                vec[i][3]='.';
                vec[i][4]='P'; vec[i][5]='P'; vec[i][6]='P';
            }
        }
    }break;
    case 5:{
        for(int i=0; i<9; i++){
            if(i==0 || i==8){
                vec[i][4]='P';
            }
            else if(i==1 || i==7){
                vec[i][3]='P'; vec[i][4]='P'; vec[i][5]='P';
            }
            else if(i==2 || i==6){
                vec[i][2]='P'; vec[i][3]='P'; vec[i][4]='P'; vec[i][5]='P'; vec[i][6]='P';
            }
            else if(i==3 || i==5){
                vec[i][1]='P'; vec[i][2]='P'; vec[i][3]='P'; vec[i][4]='P'; vec[i][5]='P'; vec[i][6]='P'; vec[i][7]='P';
            }
            else if(i==4){
                vec[i][0]='P'; vec[i][1]='P'; vec[i][2]='P'; vec[i][3]='P';
                vec[i][4]='.';
                vec[i][5]='P'; vec[i][6]='P'; vec[i][7]='P'; vec[i][8]='P';
            }
        }
    }break;
    case 6:{   
        vec[4][4]='.';
        vec[5][3]='P'; vec[5][5]='P';
        vec[6][2]='P'; vec[6][4]='P'; vec[6][6]='P';
        vec[7][1]='P'; vec[7][3]='P'; vec[7][5]='P'; vec[7][7]='P';
        vec[8][0]='P'; vec[8][2]='P'; vec[8][4]='P'; vec[8][6]='P'; vec[8][8]='P';
    }break;
    case 7:{
        ReadFile();
    }break;
    default: //cerr<<"Wrong choose bye"<<endl;
        break;
    }
    print();
    }
    public void initilizes(){
        JRadioButton a = new JRadioButton("1");
        JRadioButton b = new JRadioButton("2");
        JRadioButton d = new JRadioButton("3");
        JRadioButton n = new JRadioButton("4");
        JRadioButton g = new JRadioButton("5");
        JRadioButton h = new JRadioButton("Saved");
        JButton except = new JButton("click");
        
        k[0]=a; k[1]=b; k[2]=d; k[3]=n; k[4]=g; k[5]=h;
        a.setBounds(75, 50, 100, 30);
        b.setBounds(75, 100, 100, 30);
        d.setBounds(75, 150, 100, 30);
        n.setBounds(75, 200, 100, 30);
        g.setBounds(75, 250, 100, 30);
        h.setBounds(75, 300, 100, 30);
        except.setBounds(75, 350, 80, 30);
        for(int i=0; i<6; i++){
            choc.add(k[i]);
        }
        choc.add(except);
        except.addActionListener(list); // only button have action listener
        choc.setSize(500,500);
        choc.setLocation(700,300);
        choc.setLayout(null);
        choc.setVisible(true);
    }
    public void Greeting(){
        frame.setTitle("PegSolitaire Game ");
        frame.getContentPane().setLayout(new FlowLayout());
        JTextField textfield1 = new JTextField("WELCOME TO PEGSOLITAIRE");
        textfield1.setBounds(50, 100, 200, 30);
        frame.getContentPane().add(textfield1);
        frame.setSize(300, 300);
        frame.setLocation(800, 200);
        frame.setLayout(null);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(true);
        
    }
    public int endgame(){
        int test=1;
        for(int i=0; i<size-2; i++){
            for(int j=0; j<size-2; j++){
                if(vec[i][j]=='P' && vec[i][j+1]=='P' && vec[i][j+2]=='.'){ // right
                        test=0;
                }
                if(vec[i][j]=='P' && vec[i+1][j]=='P' && vec[i+2][j]=='.'){ // down
                    test=0;
                }
                if(i>2){
                    if(vec[i][j]=='P' && vec[i-1][j]=='P' && vec[i-2][j]=='.') test=0;
                }
                if(j>2){
                    if(vec[i][j]=='P' && vec[i][j-1]=='P' && vec[i][j-2]=='.') test=0;
                }
            }        
        }
        return test;
    }
    public int boardScore(){
        int result=0;
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if(vec[i][j]=='P') result++;
            }
        }
        return result;
    }
    
    public static void main(String[] args){
        PegSolitaire obj1 = new PegSolitaire(); 
        obj1.Greeting();
        obj1.initilizes();
    }
}
