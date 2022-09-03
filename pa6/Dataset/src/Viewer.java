class Viewer extends DataSet implements NonPlayable{
    Viewer(){
    }
    // they commands are same with  the player, Theris desings are same
    public void show_list(){
        for(int i=0; i<data.size(); i++){
            if(data.get(i) instanceof NonPlayable)
                System.out.println(data.get(i));
        }

    }
    public Viewer currently_viewing(){
        if(data.isEmpty()){
            data.add(new Viewer());
        }
        int i;
        for(i=0; i<data.size(); i++){
            if(data.get(i) instanceof NonPlayable) break;
        }
        return (Viewer)data.get(i);
    }
    public void next(String type){
        if(data.isEmpty()){
            System.out.println("Dummy");
        }
        else{
            if(type == "audio"){
                int i;
                for(i=0; i<data.size(); i++){
                    if(data.get(i).getClass().getName()=="Audio"){
                        currently_viewing();
                        break;
                    }
                }
                System.out.println(data.get(i)); // next index in own type
            }
            else if(type=="video"){
                int i;
                for(i=0; i<data.size(); i++){
                    if(data.get(i).getClass().getName()=="Video"){
                        currently_viewing();
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
        else{
            if(type == "audio"){
                int i;
                for(i=0; i<data.size(); i++){
                    if(data.get(i).getClass().getName()=="Audio"){
                        currently_viewing();
                        break;
                    }
                }
                if(i>0) System.out.println(data.get(i-1)); // next index in own type
            }
            else if(type=="video"){
                int i;
                for(i=0; i<data.size(); i++){
                    if(data.get(i).getClass().getName()=="Video"){
                        currently_viewing();
                        break;
                    }
                }
                if(i>0) System.out.println(data.get(i-1)); // next index in own type
            }
            else System.out.println("error");
        }
    }
    public void info(){
        System.out.println("Viewer");
    }
}
