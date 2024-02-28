package java_stl;

import java.util.HashMap;
import java.util.Map;

public class HashMaps {
    public static void main(String[] args) {
        int[] nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int max = 0;
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                map.put(nums[i], map.get(nums[i]) + 1);
                int x=map.get(nums[i]);
                max = Math.max(max, x);
            } else {
                map.put(nums[i], 1);
            }
        }
        System.out.println(max);
        System.out.println(map);
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int key = entry.getKey();
            int value = entry.getValue();
            max = Math.max(max, value);
        }
        int ans = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int key = entry.getKey();
            int value = entry.getValue();
            System.out.print(value + " ");
            if(value == max) ans+=max;
          
        }

        System.out.println(ans);
        System.out.println(max);
    }
}
