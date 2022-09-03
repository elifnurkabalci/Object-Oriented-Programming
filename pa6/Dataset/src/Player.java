class Player extends DataSet implements Playable {
    public Player(){ // for declaration, empty constructor
    }
    public void info(){ // info for player object
        System.out.println("Player");
        System.out.println(get_duration());
    }
    public double get_duration(){ // its constant
        return 1.0;
    }
    
    public void show_list(){ // if arraylist have any object it print the elements
        for(int i=0; i<data.size(); i++){
            if(data.get(i) instanceof Playable)
                System.out.println(data.get(i));
        }
    }
    public Playable currently_playing(){ // currently working data for playables
        if(data.isEmpty()){
            data.add(new Player());
        }
        int i;
        for(i=0; i<data.size(); i++){
            if(data.get(i) instanceof Playable) break;
        }
        return (Playable)data.get(i);
    }
    public void next(String type){
        if(data.isEmpty()){ // if its empty
            System.out.println("Dummy");
        }
        else{
            if(type == "text"){
                int i;
                for(i=0; i<data.size(); i++){
                    if(data.get(i).getClass().getName()=="Text"){
                        currently_playing();
                        break;
                    }
                } // getclass.getname giving the type name
                System.out.println(data.get(i)); // next index in own type
            }
            else if(type=="image"){
                int i;
                for(i=0; i<data.size(); i++){
                    if(data.get(i).getClass().getName()=="Image"){
                        currently_playing();
                        break;
                    }
                }
                System.out.println(data.get(i)); // next index in own type
            }
            else System.out.println("error");
        }
    }
    public void previous(String type){
        if(data.isEmpty()){
            System.out.println("Dummy");
        }
        else {
            if(type == "text"){
                int i;
                for(i=0; i<data.size(); i++){
                    if(data.get(i).getClass().getName()=="Text"){
                        currently_playing();
                        break;
                    }
                }
                if(i>0) System.out.println(data.get(i-1)); // next index in own type
            }
            else if(type=="image"){
                int i;
                for(i=0; i<data.size(); i++){
                    if(data.get(i).getClass().getName()=="Image"){
                        currently_playing();
                        break;
                    }
                }
                if(i>0) System.out.println(data.get(i-1)); // next index in own type
            }
            else System.out.println("error");

        }
    }
    
}
