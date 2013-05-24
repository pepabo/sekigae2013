import java.util.ArrayList;
import java.util.Collections;
 
public class Sekigae{
    public static void main(String[] args){
 
  ArrayList<String> list = new ArrayList<String>();
 
	list.add("okkun");
	list.add("kitak");
	list.add("keoken");
	list.add("gussan");
 
	Collections.shuffle(list);
 
	System.out.println(list.get(0) +" | "+ list.get(1) +" | "+ 
			   list.get(2) +" | "+ list.get(3)); 
    }
}
