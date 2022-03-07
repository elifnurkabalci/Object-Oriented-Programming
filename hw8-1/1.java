import java.awt.FlowLayout;
import java.awt.GraphicsConfiguration;
import java.awt.GridLayout;
import java.io.File;
//import java.io.FileReader;
//import java.io.FileWriter;
import java.util.Random;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JTextField;


class HexGame{
    static GraphicsConfiguration gc;
    public static void Show_Screen(char[][] Arr, int a,JFrame f){
        String ptr[]={"A", "B","C", "D", "E", "F", "G", "H", "I", "J", "K", "L"}; // col 
        
        JButton s = new JButton(" "); // space
        f.add(s);
        for(int i=0; i<a; i++){
            JButton c = new JButton(ptr[i]); 
            f.add(c);
        }
        for(int i=1; i<=a; i++){
            JButton c = new JButton(Integer.toString(i));
            f.add(c);
            for(int j=0; j<a; j++){
                JButton b = new JButton(".");
                f.add(b);
            }
        }
        f.setLayout(new GridLayout(a+1,a+1));
        f.setSize(400,400);
        f.setVisible(true);


    }
    public static void Write_in_Load(int b, char a, File file){
       //if(a=='0') file.write(a);
       //else if(a!= '0') file.write(a+""+b);
       //file.write("\n");
    }
    public static void Read_Load_Write_Save() {
        /*try{
            FileReader input = new FileReader("Load.txt");
            FileWriter output = new FileWriter("Save.txt");
            String a;
            while(a!='0'){
                input.read(a);
                output.write(a);
            }
        }
        catch(Exception e){
            System.out.println("Error");
        }*/
       
    }
    public static boolean FirstEnd(int a, char[][] arr){
        int i=0, j=0,result=1;
        boolean bol=false;
        while(j== a){ 
            while(i==a){
                result=1;
                if(arr[i][j]=='x'){
                    result=0;
                    if(arr[i][j+1]=='x'){ //right
                        j++;
                    }
                    else if(arr[i+1][j+1]=='x'){ //dwn to right
                        i++;
                        j++;
                    }
                    else if(arr[i-1][j+1]=='x'){ // up to right
                        i--;
                        j++;
                    }
                }
                else{
                    i++;
                }
            }
            i=0;
            if(result==1) break;
            else if(result==0) j++;
        }
        if(j==a) bol=true;
        return bol;
    }
    public static boolean SecondEnd(int a, char[][] arr){
        int i=0, j=0,result=1;
        boolean bol=false;
        while(i== a){ 
            while(j==a){
                result=1;
                if(arr[i][j]=='o'){
                    result=0;
                    if(arr[i][j+1]=='o'){ //right
                        j++;
                    }
                    else if(arr[i+1][j+1]=='o'){ //dwn to right
                        i++;
                        j++;
                    }
                    else if(arr[i+1][j]=='o'){ // down
                        i++;
                    }
                    else if(arr[i+1][j-1]=='o'){ // down to left
                        j--;
                        i++;
                    }
                }
                else{
                    i++;
                }
            }
            i=0;
            if(result==1) break;
            else if(result==0) j++;
        }
        if(j==a) bol=true;
        return bol;
    }
    public static boolean isEnd(int a, char[][] arr){
        return FirstEnd(a, arr) || SecondEnd(a, arr);
    }
    public static void Pre_Play2(char[][] arr, int a, File file, JFrame f) { // people to people
        int k=0, m=2, n=1,row=1,coll=1;
        String b,c;
        while((coll!=5 && row!=0) || isEnd(a, arr)==true){
            b = JOptionPane.showInputDialog("Choose row:");
            row = Integer.parseInt(b);
            c = JOptionPane.showInputDialog("Choose coll:");
            coll = Integer.parseInt(c);
            if(coll== '5') m=0;
            while(m!=0){
                while(n!=0){
                    if(coll>a || row>a){
                        b = JOptionPane.showInputDialog("Choose row:");
                        row = Integer.parseInt(b);
                        c = JOptionPane.showInputDialog("Choose coll:");
                        coll = Integer.parseInt(c);
                    }
                    else{
                        n*=0;
                    }
                }
                if(arr[row-1][coll]=='.'){
                    if(k%2==0){
                        arr[row-1][coll]='x';
                        k++;
                        m*=0;
                    }
                    else if(k%2==1){
                        arr[row-1][coll]='o';
                        k++;
                        m*=0;
                    }
                    Show_Screen(arr, a,f);
                }
                char t =(char) coll;
                Write_in_Load(row, t, file);
            }
            m++;
            b=null;
            c=null;
            //f.setVisible(false);
        }
    }

    public static void Pre_Play1(char[][] arr, int a, File file,JFrame f) { // people to computer
        int row=1,coll=1,k=0, m=1;
        int n=1;
        String b,c;
        Random rand = new Random();
        while((coll!=5 && row!=0) || isEnd(a, arr)==true){
            if(k%2 ==0){
                b = JOptionPane.showInputDialog("Choose row:");
                row = Integer.parseInt(b);
                c = JOptionPane.showInputDialog("Choose coll:");
                coll = Integer.parseInt(c)-65;
                if(coll== '5') m=0;
            }
            if(k%2==1){
                row = rand.nextInt(a);
                coll= rand.nextInt(a);
                while(arr[row-1][coll]!='.'){
                    row = rand.nextInt(a);
                    coll= rand.nextInt(a);
                }
            }
            while(m!=0){
                while(n!=0){
                    if(coll>a || row>a){
                        b = JOptionPane.showInputDialog("Choose row:");
                        row = Integer.parseInt(b);
                        c = JOptionPane.showInputDialog("Choose coll:");
                        coll = Integer.parseInt(c);
                    }
                    else{
                        n*=0;
                    }
                }
                if(arr[row-1][coll]=='.'){
                    if(k%2==0){
                        arr[row-1][coll]='x';
                        k++;
                        m*=0;
                    }
                    else if(k%2==1){
                        arr[row-1][coll]='o';
                        k++;
                        m*=0;
                    }
                }
                char t =(char) coll;
                Show_Screen(arr, a,f);
                Write_in_Load(row,t, file);
            }
            //f.setVisible(false);
            m++;
            b=null;
            c=null;
        }
    }
    public static void Fill_Arr(int a, int b, File file){
        char[][] Arr = new char[12][12];
        JFrame f=new JFrame();
        for(int i=0; i<a; i++){        // fill with space
            for(int j=0; j<a; j++){
                Arr[i][j]='.';
            }
        }
        if(b==1 || b==2) Show_Screen(Arr,a,f);
        else System.err.println("Error");
        if(b == 1) Pre_Play1(Arr,a,file,f);
        if(b == 2) Pre_Play2(Arr,a,file,f);
    }
    public static void Choose(JFrame frame) {
        File file = new File("Load.txt");
        String a,b;
        int c,d;
        a = JOptionPane.showInputDialog("Enter The Boardsize");
        c = Integer.parseInt(a);
        Write_in_Load(c, '0', file);
        b = JOptionPane.showInputDialog("1) One Player 2) Two Player");
        d = Integer.parseInt(b);
        Write_in_Load(d, '0', file);
        Fill_Arr(c,d,file);
        //file.close();
        Read_Load_Write_Save();
    }  
    public static void Greeting(JFrame frame) {
        frame.setTitle("HexGame.elifnur");
        frame.getContentPane().setLayout(new FlowLayout());
        JTextField textfield1 = new JTextField("WELCOME TO HEXGAME");
        textfield1.setBounds(50, 100, 200, 30);
        frame.getContentPane().add(textfield1);
        frame.setSize(400, 400);
        frame.setLocation(200, 200);
        frame.setLayout(null);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(true);
        
    }
    public static void main(String[] args){
        JFrame frame= new JFrame(gc);
        Greeting(frame);
        Choose(frame);
    }
}