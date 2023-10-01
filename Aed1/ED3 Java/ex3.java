import java.util.Scanner;
import java.lang.String;

public class ex3 {
    public static void invertMaiusculas(String word) {
        int tam = word.length();
        int count = 0;

        for (int i = tam - 1; i >= 0; i--) {
            if (word.charAt(i) >= 'A' && word.charAt(i) <= 'Z') {
                System.out.println(word.charAt(i));
                count++;
            }
        }
        System.out.println("Maiusculas: " + count);
    }

    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        String word;

        do
        {
            System.out.print("Entrar com palavra: ");
            word = s.nextLine();
            if(word.compareTo("FIM") != 0)
            {
                invertMaiusculas(word);
            }
        }while(word.compareTo("FIM") != 0);
        s.close();
    }
}
