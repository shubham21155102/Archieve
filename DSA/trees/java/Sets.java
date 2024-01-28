package trees.java;

import java.util.HashSet;

public class Sets {
    public static void main(String[] args) {
        HashSet<Integer> hs=new HashSet<>();
        hs.add(56);
        hs.add(6);
        hs.add(78);
        hs.add(56);
        hs.add(45);
        System.out.println(hs);
        for(Integer i:hs){
            System.out.println(i);
        }
    }
}
