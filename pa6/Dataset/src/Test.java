import java.util.ArrayList;

public class Test {
    public static void test1(){ // extra tests in homework pdf
        DataSet ds1= new Audio("audio1");
        DataSet ds2= new Video("video1");
        DataSet ds3= new Text("text1");
        DataSet ds4= new Image("image1");
        if(ds1 instanceof Playable){  // audio
            System.out.println("playable");
            Playable p = (Playable)ds1;
            p.info();
        }
        if(ds2 instanceof Playable){ // video
            System.out.println("playable");
            Playable p20= (Playable)ds2;
            p20.info();
        }
        if(ds3 instanceof NonPlayable){ // text
            System.out.println("nonplayable");
            NonPlayable p3 = (NonPlayable)ds3;
            p3.info();
        }
        if(ds4 instanceof NonPlayable){ // image
            System.out.println("nonplayable");
            NonPlayable p4 = (NonPlayable)ds4;
            p4.info();
        }
    }
    
    public static void main(String[] args){
        ArrayList<DataSet> a1 = new ArrayList<DataSet>();
        DataSet ds=new DataSet();

        ds.add(new Image("imagename1", "dimension info1", "other info1"));
        ds.add(new Image("imagename2", "dimension info2", "other info2"));
        ds.add(new Image("imagename3", "dimension info3", "other info3"));
        ds.add(new Image("imagename4", "dimension info4", "other info4"));
        ds.add(new Image("imagename5", "dimension info5", "other info5"));

        ds.add(new Audio("audioname1", "duration1", "other info1"));
        ds.add(new Audio("audioname1", "duration1", "other info1"));
        ds.add(new Audio("audioname2", "duration2", "other info2"));
        ds.add(new Audio("audioname3", "duration3", "other info3"));
        
        ds.add(new Video("videoname1", "duration1", "other info1"));
        ds.add(new Video("videoname2", "duration2", "other info2"));
        ds.add(new Video("videoname3", "duration3", "other info3"));
        
        ds.add(new Text("textname1", "other info1"));
        ds.add(new Text("textname2", "other info2"));
        ds.add(new Text("textname3", "other info3"));
        //declarations
        
        Player p1 = new Player();
        Player p2 = new Player();
        Viewer v1 = new Viewer();
        Viewer v2 = new Viewer();

        ds.register(p1);
        ds.register(p2);
        ds.register(v1);
        ds.register(v2); // they are add the player or viewer
        a1.add(ds);

        DataSet temp = a1.get(0); // for become easy
        for(int i=0; i<ds.data.size(); i++){ // print the array list contains
            System.out.println(temp.data.get(i).getClass().getName());
        }
        System.out.println(); 

        ds.remove(p1); // remove the one element
        System.out.println("After deleting p1 player element\n");

        temp = a1.get(0); // for become easy
        for(int i=0; i<ds.data.size(); i++){
            System.out.println(temp.data.get(i).getClass().getName());
        }
        System.out.println(); // for arrangement
        System.out.println();

        test1(); // calling extra tests

        System.out.println();
        
        Playable po = p1.currently_playing();
        po.info();
        ds.remove((DataSet)po);       

        System.out.println();

        NonPlayable np = v1.currently_viewing();
        np.info();
        if(np instanceof Viewer){
            Viewer v = (Viewer)np;
            v.show_list();
        }
    }
}
