class Audio extends DataSet implements NonVisual, Playable{
    public String nameString, infoString, durationString;
    public Audio(String n){
        super(n); // calling up data
    }
    public double get_duration(){
        return 3.5; // constant
    }
    public void info(){
        System.out.println("audio");
        //System.out.println(super.get_name());
    }
    public Audio(String name, String duration, String info){
        nameString=name; 
        durationString=duration;
        infoString=info;
        //System.out.println(name);
    }
}
