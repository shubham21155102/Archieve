// import java.util.ArrayList;
// import java.util.Iterator;
// import java.util.List;

// public class Index {
//     public static void main(String[] args) {

//         List<Integer> list = new ArrayList<>();
//         list.add(1);
//         list.add(2);
//         list.add(3);
//         Iterator<Integer> iterator = list.iterator();
//         iterator.remove();
//         System.out.println(list.get(0));
//     }
// }
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

abstract class Animal {
    abstract void sound();
}

public class Index {
    void listReducer(int[] list) {
        int N = list.length;
        if (N == 0)
            return;
        int[] newList = new int[N - 1];
        for (int i = 0; i < N - 1; i++) {
            newList[i] = list[i];
        }
        listReducer(newList);
    }


    public static void main(String[] args) {

        List<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(3);

        Iterator<Integer> iterator = list.iterator();
        if (iterator.hasNext()) {
            iterator.next(); // Move to the first element
            iterator.remove(); // Now it's safe to remove the first element
        }

        System.out.println(list.get(0)); // This will print 2, as the first element (1) is removed
        Animal a = new Animal() {
            @Override
            void sound() {
                System.out.println("Sound");
            }
        };
        a.sound();
        // Animal animal= new Animal();
        // animal.sound();
    }
}
