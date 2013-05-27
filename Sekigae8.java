import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Sekigae8 {
    public static void main(String[] args) {
        List<String> users = Arrays.asList("okkun", "kitak", "keoken", "gussan");
        Collections.shuffle(users);
        users.stream().map(u -> u + "\n").forEach(System.out::print);
    }
}
