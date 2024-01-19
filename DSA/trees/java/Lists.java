package trees.java;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Lists {
    public static void main(String[] args) {
        List<Integer> l=new ArrayList<>();
        l.add(23);
        l.add(24);
        l.add(-90);
        l.add(25);
        l.add(0);
        l.add(23);
        Collections.sort(l,Collections.reverseOrder());
        System.out.println(l);
    }
}
