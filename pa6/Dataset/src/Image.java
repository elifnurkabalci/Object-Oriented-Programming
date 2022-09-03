class Image extends DataSet implements Visual, NonPlayable{
    public String nameString, infoString, dimeString;
    public double get_dimension(){
        return 1.0;
    }
    public void info(){
        System.out.println("Image");
        System.out.println(get_dimension());
    }
    public Image(String n){
        super(n);
    }
    public Image(String name, String dimention, String info){
        nameString=name;
        dimeString=dimention;
        infoString=info;
    }
}