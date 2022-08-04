import java.io.*;
import java.util.*;

public class graphics {

    public static Integer size = 5;
    public static Integer alt_size = 0;
    public static Integer original_size = size;
    public static Integer gap = 1;
    
    public static Boolean contact = true;
    public static Boolean revert = false;

    public static Boolean border = true;

    public static String border_char = "|";
    public static StringBuilder border_title = new StringBuilder("graphics.java");

    public static Boolean debug = true;
    
    public static void main(String args[]) 
    {
        
        if (debug == true) 
        {
            System.out.println("SIZE=" + size);
            System.out.println("GAP=" + gap);
            System.out.println("BORDER=" + border);

            if (border) 
            {
                System.out.println("BORDER_CHAR=" + border_char);
                if (border_title.length() > 0) 
                {
                    System.out.println("BORDER_TITLE=" + border_title);
                }
            }
        }

        System.out.println("+"+r("-", (size+gap)*2)+"+");
        for (int i = 0; i < size; i++)
        {
            original_size -= 1;
            alt_size += 1;
            System.out.println(border_char + r("*", alt_size) + r(" ", ((original_size + gap)*2)) + r("*", alt_size) + border_char);
        }

        for (int k = 1; k < alt_size; k++)
        {
            size -= 1;
            original_size += 1;
            System.out.println(border_char + r("*",size) + r(" ", ((original_size+gap)*2)) + r("*",size) + border_char);
        }

        System.out.println("+"+r("-", (alt_size+gap)*2)+"+");
    }

    public static String r(String char_, Integer amount) {
        return new String(new char[amount]).replace("\0", char_);
    }
}