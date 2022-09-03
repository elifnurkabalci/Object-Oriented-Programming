import java.util.ArrayList;

public class DataSet{
    ArrayList<DataSet> data = new ArrayList<DataSet>();
    private String name;
    public DataSet(String n){
        name = n;
    }
    public DataSet(){
    }
    public String get_name(){
        return name;
    }
    public void register(Player x){
        data.add(x);
    }
    public void register(Viewer x){
        data.add(x);
    }
    public void add(DataSet x){
        data.add(x);
    }
    public void remove(DataSet x){
        if(data.contains(x)){
            data.remove(x);
        }
    }
    public void remove_observer(Player x){
        for(int i=0; i<x.data.size(); i++){
            if(x.data.get(i)==x){
                x.data.remove(i);
            }
        }
    }
    public void remove_observer(Viewer x){
        for(int i=0; i<x.data.size(); i++){
            if(x.data.get(i)==x){
                x.data.remove(i);
            }
        }
    }
}