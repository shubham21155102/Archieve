package trees.java;

import java.util.HashMap;

public class Maps {
    public static void main(String[] args) {
        HashMap<Integer,Integer>hm=new HashMap<>();
        int[] l={23,24,25,26,27,28,28};
        for(int i=0;i<l.length;i++){
            if(hm.containsKey(l[i])){
                hm.put(l[i],hm.get(l[i])+1);
            }
            else{
                hm.put(l[i],1);
            }
        }
        System.out.println(hm);
    }
}
