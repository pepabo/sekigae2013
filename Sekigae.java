import java.util.*;

public class Sekigae {
    public static void main(String[] args) {
        List<String> list = Arrays.asList("たけお", "きたけー", "ぐっさん", "おっくん");
        Collections.shuffle(list);
        System.out.println(list);
    }
}
