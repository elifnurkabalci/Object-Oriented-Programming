class Text extends DataSet implements NonVisual,NonPlayable{
    public String nameString, infoString;
    public Text(String n){
        super(n);
    }
    public Text(String name, String info){
        nameString = name;
        infoString = info;
    }
    public void info(){
        System.out.println("Text");
    }
}