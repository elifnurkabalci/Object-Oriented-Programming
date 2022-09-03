class Video extends DataSet implements Visual, Playable{
    public String nameString, infoString, durationString;
    public Video(String n){
        super(n);
    }
    public double get_duration(){
        return 1.0;
    }
    public void info(){
        System.out.println("video");
        System.out.println(get_dimension());
        System.out.println(get_duration());
    }
    public double get_dimension(){
        return 1.0;
    }
    public Video(String name, String duration, String info){
        nameString=name;
        durationString=duration;
        infoString=info;
    }
    
}
